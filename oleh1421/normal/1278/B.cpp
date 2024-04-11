#include <bits/stdc++.h>
#define endl '\n'
const long long mod=1000000007ll;
typedef long long ll;
using namespace std;
void solve(){
    ll a,b;cin>>a>>b;
    ll d=abs(a-b);
    ll cur=0ll;
    while (cur*(cur+1ll)<d+d) cur++;
    while ((cur*(cur+1ll)/2ll)%2!=d%2) cur++;
    cout<<cur<<endl;

}
int main()
{
    //freopen("meetings.in","r",stdin);
    //freopen("meetings.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}