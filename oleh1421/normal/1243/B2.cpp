#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const long long mod=764983111ll;
const long long mod2=764983113ll;
int cnt[155];
void solve(){
    int n;cin>>n;
    string s,t;cin>>s>>t;
    for (int i=0;i<='z'-'a';i++) cnt[i]=0;
    for (int i=0;i<n;i++){
        cnt[s[i]-'a']++;
        cnt[t[i]-'a']++;
    }
    for (int i=0;i<='z'-'a';i++){
        if (cnt[i]%2){
            cout<<"No\n";
            return;
        }
    }
    vector<pair<int,int> >ans;
    for (int i=0;i<n;i++){
        if (s[i]==t[i]) continue;
        int ind=-1;
        for (int j=i+1;j<n;j++){
            if (s[i]==s[j]){
                ind=j;
                break;
            }
        }
        if (ind!=-1){
            swap(t[i],s[ind]);
            ans.push_back({ind,i});
            continue;
        }
        for (int j=i+1;j<n;j++){
            if (s[i]==t[j]){
                ind=j;
                break;
            }
        }
        ans.push_back({i,i});
        swap(s[i],t[i]);
        ans.push_back({i,ind});
        swap(s[i],t[ind]);
    }
    cout<<"Yes\n";
    cout<<ans.size()<<endl;
    for (auto i:ans) cout<<i.first+1<<" "<<i.second+1<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    /*ll n;cin>>n;
    vector<ll>d;
    for (ll i=2ll;i*i<=n;i++){
        if (n%i) continue;
        d.push_back(i);
        if (i*i<n) d.push_back(n/i);
    }
    */
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}