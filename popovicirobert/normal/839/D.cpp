#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 2e5;
const int MAXVAL = (int) 1e6;

int fr[MAXVAL + 1];
int p2[MAXN + 1];
int ans[MAXVAL + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, a;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a;
        fr[a]++;
    }
    p2[0] = 1;
    for(i = 1; i <= n; i++) {
        p2[i] = p2[i - 1] * 2;
        if(p2[i] >= MOD)
           p2[i] -= MOD;
    }
    for(i = MAXVAL; i >= 1; i--) {
        int cnt = 0;
        for(j = i; j <= MAXVAL; j += i) {
           cnt += fr[j];
           ans[i] -= ans[j];
           if(ans[i] < 0)
              ans[i] += MOD;
        }
        ans[i] = (ans[i] + 1LL * cnt * p2[cnt - 1]) % MOD;
    }
    int res = 0;
    for(i = 2; i <= MAXVAL; i++)
        res = (res + 1LL * i * ans[i]) % MOD;
    cout << res;
    //cin.close();
    //cout.close();
    return 0;
}