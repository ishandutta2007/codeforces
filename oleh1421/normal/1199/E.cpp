#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
typedef long long ll;
using namespace std;
vector<int>g[300001];
bool used[300001];
int x[500001];
int y[500001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        int n,m;cin>>n>>m;
        for (int i=1;i<=n+n+n;i++) {
            g[i].clear();
            used[i]=false;
        }
        for (int i=1;i<=m;i++){
            int a,b;cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
            x[i]=a;
            y[i]=b;
        }
        vector<pair<int,int> >v;
        for (int i=1;i<=n+n+n;i++) v.push_back({(int)g[i].size(),i});
        sort(v.begin(),v.end());
        vector<int>random;
        for (auto i:v) random.push_back(i.second);
        vector<int>indSet;
        for (auto v:random){
            if (used[v]) continue;
            for (auto to:g[v]){
                used[to]=true;
            }
            used[v]=true;
            indSet.push_back(v);
        }
        if ((int)indSet.size()>=n){
            cout<<"IndSet\n";
            for (int i=0;i<n;i++) cout<<indSet[i]<<" ";
            cout<<endl;
        } else {
            for (int i=1;i<=n+n+n;i++) used[i]=false;
            vector<pair<int,int> >edges;
            for (int i=1;i<=m;i++){
                edges.push_back({(int)(g[x[i]].size()+g[y[i]].size()),i});
            }
            sort(edges.begin(),edges.end());
            vector<int>ans;
            for (auto i:edges){

                if (used[x[i.second]] || used[y[i.second]]) continue;
                used[x[i.second]]=true;
                used[y[i.second]]=true;
                ans.push_back(i.second);
            }
            if ((int)ans.size()>=n){
                cout<<"Matching\n";
                for (int i=0;i<n;i++) cout<<ans[i]<<" ";
                cout<<endl;
            }
            else {
                  cout<<"Impossible\n";
            }
        }
    }
    return 0;
}