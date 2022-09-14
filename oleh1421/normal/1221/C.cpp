#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int long long
using namespace std;
int cnt[201];
void solve(){
     int c,m,x;cin>>c>>m>>x;
     cout<<min({(c+x+m)/3,m,c})<<endl;

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