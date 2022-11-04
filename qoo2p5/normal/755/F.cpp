#include <bits/stdc++.h>

using namespace std;

const int INF = (int) 1e9 + 123;

const int N = (int) 1e6 + 123;
const int B = 170;

int n, k;
int p[N];
int cnt;
int a[N];
bool used[N];
int q[N];
int need[N];
int res[N];

void run() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }
        
        int v = i;
        while (p[v] != i) {
            used[v] = 1;
            a[cnt]++;
            v = p[v];
        }
        a[cnt]++;
        used[v] = 1;
        
        cnt++;
    }
    
    int mi = 0;
    int ma = 0;
    
    int rk = k;
    int tmp = 0;
    
    for (int i = 0; i < cnt; i++) {
        tmp += a[i] % 2;
        ma += min(a[i] - a[i] % 2, 2 * rk);
        rk -= min(a[i] / 2, rk);
    }
    
    if (rk) {
        ma += min(rk, tmp);
    }
    
    for (int i = 0; i < cnt; i++) {
        q[a[i]]++;
    }
    
    bitset<N> dp;
    dp[0] = 1;
    
    for (int i = 1; i < N; i++) {
        if (!q[i]) {
            continue;
        }
        
        for (int j = 0; j < 20; j++) {
            if ((1 << j) <= q[i]) {
                q[i] -= (1 << j);
                res[(1 << j) * i]++;
            }
        }
        
        
        res[q[i] * i]++;
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < res[i]; j++) {
            dp |= dp << i;
        }
    }
    
    mi = dp[k] ? k : k + 1;
    
    cout << mi << " " << ma << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}