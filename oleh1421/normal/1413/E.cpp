#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
int type[N];
int ind[N];
int p[N];
void solve(){
    ll a,b,c,d;cin>>a>>b>>c>>d;
    if (b*c-a<0) {
        cout<<-1<<endl;
        return;
    }
    ll k=(a/(d*b));
    cout<<max(a*(k+1ll)-d*b*k*(k+1ll)/2ll,a)<<endl;


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}