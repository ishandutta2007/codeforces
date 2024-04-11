#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int long long
using namespace std;
int cnt[201];
void solve(){
     int n;cin>>n;
     for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if ((i+j)%2) cout<<"B";
            else cout<<"W";
        }
        cout<<endl;
     }

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;tt=1;
    while (tt--){
        solve();
    }
    return 0;
}