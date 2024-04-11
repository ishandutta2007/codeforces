#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
///#define int ll
using namespace std;
mt19937_64 rnd((unsigned) chrono::steady_clock::now().time_since_epoch().count());
const int N=1500010;
const ll inf=1000000000000000001ll;
const ll mod=998244353;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    if (n>=2 && s[0]==s[1]){
        cout<<s[0]<<s[1]<<endl;
        return;
    }
    int ans=n-1;
    bool eq=true;
    for (int i=1;i<n;i++){
        if (s[i-1]<s[i]){
            ans=i-1;
            break;
        }
    }

    for (int i=0;i<=ans;i++) cout<<s[i];
    for (int i=ans;i>=0;i--) cout<<s[i];
    cout<<endl;

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
/**




**/