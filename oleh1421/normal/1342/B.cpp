#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
void solve(){
    string s;cin>>s;
    bool ok=true;
    for (int i=1;i<s.size();i++){
        if (s[i]!=s[i-1]){
            ok=false;
            break;
        }
    }
    if (ok){
        cout<<s<<endl;
        return;
    }
    string ans="";
    ans+=s[0];
    for (int i=1;i<s.size();i++){
        if (s[i]==ans.back()){
            ans+=char(((s[i]-'0')^1)+'0');
        }
        ans+=s[i];
    }
    cout<<ans<<endl;
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