#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
int a[N],b[N],pref[N];

void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    vector<pair<pair<int,int>,int> >v;
    for (int i=1;i<=n;i++){
        v.push_back({{a[i],i-1},b[i]});
    }
    sort(v.begin(),v.end());
    pref[0]=0;
    for (int i=0;i<n;i++){
        pref[i+1]=max(pref[i],v[i].second);
    }
    vector<int>ans(n,0);
    int mn=1000000001;
    bool ok=false;
    for (int i=n;i>=1;i--){
        mn=min(mn,v[i-1].second);
        if (mn>pref[i-1]){
            ok=true;
            for (int j=i;j<=n;j++){
                ans[v[j-1].first.second]=1;
            }
            break;
        }
    }
    if (!ok) for (int i=0;i<n;i++) ans[i]=1;
    for (int i:ans) cout<<i;
    cout<<endl;
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
/**

**/