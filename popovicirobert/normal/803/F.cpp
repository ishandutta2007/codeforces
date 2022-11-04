#include <bits/stdc++.h>
#define MAXN 100000
#define MOD 1000000007

using namespace std;

int ciur[MAXN + 1];
int v[MAXN + 1];
int vf[MAXN + 1];

int p2[MAXN + 1];

int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int i, j, n, cnt;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        vf[v[i]]++;
    }
    for(i = 2; i <= MAXN; i++)
        if(ciur[i] == 0)
            for(j = i; j <= MAXN; j += i)
                ciur[j] = i;
    p2[0] = 1;
    for(i = 1; i <= n; i++) {
        p2[i] = p2[i - 1] * 2;
        if(p2[i] >= MOD)
            p2[i] -= MOD;
    }
    for(i = 0; i <= n; i++)
        p2[i]--;
    int ans = 0;
    for(i = 2; i <= MAXN; i++) {
        int x = i;
        bool flag = 1;
        while(x > 1 && flag) {
            int aux = ciur[x];
            cnt = 0;
            while(ciur[x] == aux) {
                x /= aux;
                cnt++;
            }
            if(cnt > 1)
                flag = 0;
        }
        if(flag) {
            x = i;
            cnt = 0;
            while(x > 1) {
                int aux = ciur[x];
                while(aux == ciur[x])
                    x /= aux;
                cnt++;
            }
            x = i;
            int nr = 0;
            while(x <= MAXN) {
                nr += vf[x];
                x += i;
            }
            if(cnt % 2 == 1)
               ans += p2[nr];
            else
               ans -= p2[nr];
            if(ans >= MOD)
                ans -= MOD;
            if(ans < 0)
                ans += MOD;
        }
    }
    cout << (p2[n] - ans + MOD) % MOD;
   // cin.close();
   // cout.close();
    return 0;
}