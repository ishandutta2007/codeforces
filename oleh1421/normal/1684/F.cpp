//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=500105;
const ll inf=1e9;
const ll mod=1000000007;
const int L=20;
int a[N];
int l[N],r[N];
vector<int>g[N];
int mx[N];
void solve(int Case){
    int n,m;cin>>n>>m;
    map<int,int>mp;
    set<int>st;
    for (int i=1;i<=n;i++) cin>>a[i],st.insert(a[i]);
    for (int i=1;i<=m;i++) cin>>l[i]>>r[i];
    for (int i=0;i<=n;i++) mx[i]=i;
    for (int i=1;i<=m;i++) mx[l[i]]=max(mx[l[i]],r[i]);
    for (int i=1;i<=n;i++) mx[i]=max(mx[i],mx[i-1]);
    int cnt=0;
    for (int x:st){
        mp[x]=++cnt;
    }
    for (int i=1;i<=n;i++) a[i]=mp[a[i]];
    for (int i=0;i<=n+1;i++) g[i].clear();
//    for (int i=1;i<=cnt;i++) g[i].push_back(0);
    for (int i=1;i<=n;i++) g[a[i]].push_back(i);
//    for (int i=1;i<=cnt;i++) g[i].push_back(n+1);
    int L=n+1;
    int R=0;
    vector<pair<int,int> >U;
    for (int i=1;i<=cnt;i++){
        int l=(int)g[i].size();
        int r=-1;
        for (int j=0;j<g[i].size();j++){
            int rr=upper_bound(g[i].begin(),g[i].end(),mx[g[i][j]])-g[i].begin()-1;
            if (rr>j){
                if (rr-j>1){
                    L=min(L,g[i][j+1]);
                    R=max(R,g[i][rr-1]);
                }
                U.push_back({g[i][j],g[i][rr]});
            }
        }

    }
    vector<pair<int,int> >need;
    for (auto cur:U){
        if (R<cur.first) R=max(R,cur.first);
        if (cur.second<L) L=min(L,cur.second);
    }
    for (auto cur:U){
        if (cur.first>=L && cur.first<=R) continue;
        if (cur.second>=L && cur.second<=R) continue;
        need.push_back(cur);
    }
    sort(need.begin(),need.end());
    int res=n;
    for (int i=0;i<need.size();i++){
        res=min(res,R-min(L,need[i].first)+1);
        R=max(R,need[i].second);
    }
    res=min(res,R-L+1);
    cout<<max(res,0)<<endl;
}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
1
7 3
1 1 2 1 3 3 5
1 4
4 5
2 4



**/