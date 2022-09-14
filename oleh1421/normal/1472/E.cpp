//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=400004;
int ans[N];
int a[N],b[N];
void solve(){
    int n;cin>>n;
    vector<pair<pair<int,int>,int> >v;
    for (int i=1;i<=n;i++){
        ans[i]=-1;
        int w,h;cin>>w>>h;
        a[i]=w;
        b[i]=h;
        v.push_back({{w,h},i});
        v.push_back({{h,w},i});
    }
    sort(v.begin(),v.end());
    for (int i=1;i<v.size();i++){
        if (v[i].first.second>=v[i-1].first.second) v[i]=v[i-1];
    }
    for (int i=1;i<=n;i++){
        pair<pair<int,int>,int>fnd={{a[i],-1},-1};
        int pos=upper_bound(v.begin(),v.end(),fnd)-v.begin()-1;
        if (pos!=-1 && v[pos].first.second<b[i]) ans[i]=v[pos].second;
        cout<<ans[i]<<" ";
    }
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
/*

3 0
aa
bcd
*/