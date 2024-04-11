#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=10010;
vector<int>g[N];
int mt[N];
int mt1[N];
bool used[N];
bool dfs(int v){
    if (used[v]) return false;
    used[v]=true;
    for (int to:g[v]){
        if (mt[to]==-1 || dfs(mt[to])){
            mt[to]=v;
            mt1[v]=to;
            return true;
        }
    }
    return false;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    vector<pair<int,pair<int,int> > >v;
    for (int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        v.push_back({c,{a,b}});
    }
    sort(v.begin(),v.end());
    int l=0;
    int r=m+1;
    while (r-l>1){
        int cnt=0;
        int mid=(l+r)/2;
        for (int i=0;i<mid;i++){
            g[v[i].second.first].push_back(v[i].second.second);
        }
        for (int i=1;i<=n;i++){
            mt[i]=mt1[i]=-1;
        }
        for (int run=1;run;){
            run=0;
            for (int i=0;i<=n;i++) used[i]=false;
            for (int i=1;i<=n;i++){
                if (mt1[i]==-1 && dfs(i)){
                    cnt++;
                    run=1;
                }
            }
        }

        for (int i=1;i<=n;i++) g[i].clear();
        if (cnt==n) r=mid;
        else l=mid;
    }
    if (r==m+1) cout<<-1<<endl;
    else cout<<v[r-1].first<<endl;
    return 0;
}