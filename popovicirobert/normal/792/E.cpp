#include <bits/stdc++.h>
#define MAXN 500

using namespace std;

int v[MAXN + 1];

int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int i, n, y;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    long long ans = (1LL << 62);
    for(int x = 1; x * x <= v[1]; x++) {
        bool flag = 1;
        long long cnt = 0;
        for(i = 1; i <= n && flag; i++) {
           if((v[i] + x) / (x + 1) <= v[i] / x)
               cnt += ((v[i] + x) / (x + 1));
           else
               flag = 0;
        }
        if(flag == 1)
            ans = min(ans, cnt);
        flag = 1;
        cnt = 0;
        y = (v[1] / x);
        if(y > 0) {
            for(i = 1; i <= n && flag; i++) {
               if((v[i] + y) / (y + 1) <= v[i] / y)
                   cnt += ((v[i] + y) / (y + 1));
               else
                   flag = 0;
            }
            if(flag == 1)
                ans = min(ans, cnt);
        }
        flag = 1;
        cnt = 0;
        y = (v[1] / x) - 1;
        if(y > 0) {
            for(i = 1; i <= n && flag; i++) {
               if((v[i] + y) / (y + 1) <= v[i] / y)
                   cnt += ((v[i] + y) / (y + 1));
               else
                   flag = 0;
            }
            if(flag == 1)
                ans = min(ans, cnt);
        }
    }
    cout << ans;
   // cin.close();
   // cout.close();
    return 0;
}