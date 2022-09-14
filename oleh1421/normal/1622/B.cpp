#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=300010;
const ll mod=998244353;
int p[N];
int ans[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    string s;cin>>s;
    vector<int>v,u;
    for (int i=0;i<s.size();i++){
        if (s[i]=='0') v.push_back(p[i+1]);
        else u.push_back(p[i+1]);
    }
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++) ans[v[i]]=i+1;
    sort(u.begin(),u.end());
    for (int i=0;i<u.size();i++) ans[u[i]]=i+1+(int)v.size();
    for (int i=1;i<=n;i++) cout<<ans[p[i]]<<" ";
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