#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int long long
using namespace std;
int cnt[201];
void solve(){
     int n;cin>>n;
     for (int i=0;i<=100;i++) cnt[i]=0;
     for (int i=1;i<=n;i++){
         int x;cin>>x;
         int cur=0;
         while (x>1){
            x/=2;
            cur++;
         }
         cnt[cur]++;
     }
     for (int i=0;i<=10;i++){
         cnt[i+1]+=cnt[i]/2;
     }
     if (cnt[11]) cout<<"YES\n";
     else cout<<"NO\n";

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}