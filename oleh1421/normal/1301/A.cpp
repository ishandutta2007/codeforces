#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=150010;

void solve(){
    string a,b,c;cin>>a>>b>>c;
    int n=(int)a.size();
    for (int i=0;i<n;i++){
        if (c[i]!=a[i] && c[i]!=b[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
int32_t main()
{
//    freopen("repair.in","r",stdin);
//    freopen("repair.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}