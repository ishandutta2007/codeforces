#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000100;
const ll mod=998244353;
int x[N],y[N],t[N];
map<int,vector<pair<int,int> > >r,c;
vector<int>g[N];
bool used[N];
void dfs(int v,int &mn){
    mn=min(mn,t[v]);
    used[v]=true;
    for (int to:g[v]){
        if (!used[to]){
            dfs(to,mn);
        }
    }
}
void solve(){
    int n,k;cin>>n>>k;
    r.clear();
    c.clear();
    for (int i=0;i<=n;i++) g[i].clear(),used[i]=false;
    for (int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>t[i];
        r[x[i]].push_back({y[i],i});
        c[y[i]].push_back({x[i],i});
    }
    for (auto cur:r){
        sort(cur.second.begin(),cur.second.end());
        for (int i=1;i<cur.second.size();i++){
            if (cur.second[i].first-cur.second[i-1].first<=k){
                g[cur.second[i].second].push_back(cur.second[i-1].second);
                g[cur.second[i-1].second].push_back(cur.second[i].second);
            }
        }
    }
    for (auto cur:c){
        sort(cur.second.begin(),cur.second.end());
        for (int i=1;i<cur.second.size();i++){
            if (cur.second[i].first-cur.second[i-1].first<=k){
                g[cur.second[i].second].push_back(cur.second[i-1].second);
                g[cur.second[i-1].second].push_back(cur.second[i].second);
            }
        }
    }
    vector<int>v;
    for (int i=1;i<=n;i++){
        if (!used[i]){
            int mn=1000000001;
            dfs(i,mn);
            v.push_back(mn);
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int res=0;
    for (int i=0;i<v.size();i++){
        res=max(res,min(i,v[i]));
    }
    cout<<res<<endl;
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
//A[j] - >
//(a+b1)%M+(b2+c)%M<(a+c)%M