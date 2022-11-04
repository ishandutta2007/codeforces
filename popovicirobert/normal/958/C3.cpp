#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 5e5;
const int MAXK = 105;

int v[MAXN + 1], sp[MAXN + 1];

int dp1[MAXK + 1][MAXK + 1];
int dp2[MAXK + 1][MAXK + 1];

inline void update1(int pos, int p, int val, int k) {
    for(int i = pos; i <= p; i += lsb(i)) {
        dp1[k][i] = min(dp1[k][i], val);
    }
}

inline int query1(int pos, int k) {
    int ans = MAXN;
    for(int i = pos; i > 0; i -= lsb(i)) {
        ans = min(ans, dp1[k][i]);
    }
    return ans;
}

inline void update2(int pos, int val, int k) {
    for(int i = pos; i > 0; i -= lsb(i)) {
        dp2[k][i] = min(dp2[k][i], val);
    }
}

inline int query2(int pos, int p, int k) {
    int ans = MAXN;
    for(int i = pos; i <= p; i += lsb(i)) {
        ans = min(ans, dp2[k][i]);
    }
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, k, p, x;
    ios::sync_with_stdio(false);
    //cin >> n >> k >> p;
    scanf("%d%d%d" ,&n,&k,&p);
    for(i = 1; i <= n; i++) {
        scanf("%d" ,&v[i]);
        //cin >> v[i];
        sp[i] = (sp[i - 1] + v[i]) % p;
    }
    for(i = 0; i <= k; i++) {
        for(j = 1; j <= p + 1; j++) {
            dp1[i][j] = dp2[i][j] = MAXN;
        }
        for(j = 1; j <= p + 1; j++) {
            int val = MAXN;
            if(i == 0 && j == 1)
                val = 0;
            update1(j, p + 1, val, i);
            update2(j, val, i);
        }
    }
    for(i = 1; i <= n; i++) {
        for(j = k; j > 0; j--) {
            int val = min(query1(sp[i] + 1, j - 1) + sp[i], query2(sp[i] + 2, p + 1, j - 1) + sp[i] + p) - sp[i];
            update1(sp[i] + 1, p + 1, val, j);
            update2(sp[i] + 1, val, j);
            if(i == n && j == k) {
                cout << val + sp[n];
                return 0;
            }
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}