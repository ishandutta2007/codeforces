#include <bits/stdc++.h>


using namespace std;



int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int i,n,a,b,x;
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    int ans = 0;
    int cnt = 0;
    for(i = 1; i <= n; i++) {
        cin >> x;
        if(x == 1) {
            if(a > 0)
                a--;
            else if(b > 0) {
                cnt++;
                b--;
            }
            else if(cnt > 0)
                cnt--;
            else
                ans++;
        }
        else {
            if(b > 0)
               b--;
            else
               ans += 2;
        }
    }
    cout << ans;
   // cin.close();
   // cout.close();
    return 0;
}