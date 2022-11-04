#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 202;
const int C = 30;

int n;
ll l;
int a[N];

struct AC {
    int ptr;
    bool is_term[N];
    int nxt[N][C];
    int go[N][C];
    int suf[N];
    int cost[N];
    int sum[N];
    pair<int, int> parent[N];
    
    AC() {
        ptr = 1;
        for (int i = 0; i < N; i++) {
            is_term[i] = 0;
            fill(nxt[i], nxt[i] + C, -1);
            fill(go[i], go[i] + C, -1);
            suf[i] = -1;
            cost[i] = 0;
            sum[i] = -1;
            parent[i] = {-1, -1};
        }
    }

    void add(const string &s, int val) {
        int cur = 0;
        
        for (char cc : s) {
            int c = cc - 'a';
            
            if (nxt[cur][c] == -1) {
                parent[ptr] = {cur, c};
                nxt[cur][c] = ptr++;
            }
            
            cur = nxt[cur][c];
        }
        
        is_term[cur] = true;
        cost[cur] += val;
    }
    
    int calc_go(int v, int c) {
        if (go[v][c] != -1) {
            return go[v][c];
        }
        
        if (nxt[v][c] != -1) {
            return go[v][c] = nxt[v][c];
        }
        
        if (v == 0) {
            return 0;
        }
        
        return go[v][c] = calc_go(calc_suf(v), c);
    }
    
    int calc_suf(int v) {
        if (suf[v] != -1) {
            return suf[v];
        }
        
        if (v == 0 || parent[v].first == 0) {
            return 0;
        }
                
        return suf[v] = calc_go(calc_suf(parent[v].first), parent[v].second);
    }
    
    int calc_sum(int v) {
        if (sum[v] != -1) {
            return sum[v];
        }
        
        if (v == 0) {
            return cost[v];
        }
                
        return sum[v] = cost[v] + calc_sum(calc_suf(v));
    }
};

struct Matrix {
    ll a[N][N];
    
    Matrix() {
        for (int i = 0; i < N; i++) {
            fill(a[i], a[i] + N, -1);
        }
    }
    
    ll* operator[](const int i) {
        return a[i];
    }
    
    Matrix operator*(Matrix &b) {
        Matrix res;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    if (a[i][k] != -1 && b[k][j] != -1) {
                        res[i][j] = max(res[i][j], a[i][k] + b[k][j]);
                    }
                }
            }
        }
        
        return res;
    };
};

Matrix power(Matrix &a, ll p) {
    if (p == 1) {
        return a;
    }
    
    if (p & 1) {
        return power(a, p - 1) * a;
    }
    
    Matrix tmp = power(a, p / 2);
    return tmp * tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    AC ac;
    
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ac.add(s, a[i]);
    }
    
    Matrix dp;
    for (int i = 0; i < ac.ptr; i++) {
        for (int c = 0; c < C; c++) {
            int j = ac.calc_go(i, c);
            dp[i][j] = ac.calc_sum(j);
        }
    }
    
    Matrix res = power(dp, l);
    ll ans = *max_element(res[0], res[0] + ac.ptr);
    cout << ans << "\n";
    
    return 0;
}