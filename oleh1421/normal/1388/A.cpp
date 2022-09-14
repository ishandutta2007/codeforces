#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000010;
const ll mod=1000000007;
const ll inf=(1ll<<60);
void solve(){
    int n;cin>>n;

    if (n<=6+10+14) cout<<"NO\n";
    else if (n==6+10+14+6) cout<<"YES\n"<<"6 10 15 5\n";
    else if (n==6+10+14+10) cout<<"YES\n"<<"6 10 15 9\n";
    else if (n==6+10+14+14) cout<<"YES\n"<<"6 10 15 13\n";
    else cout<<"YES\n"<<6<<" "<<10<<" "<<14<<" "<<n-6-10-14<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}