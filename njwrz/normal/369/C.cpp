#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
int n;
vector <pair<int,bool> > a[100005];
vector <int> ans;
bool vis[100005];
int dfs(int v){
    vis[v]=1;
    int re=0;
    for(int i=0;i<a[v].size();i++){ 
        if(!vis[a[v][i].f]){
            int t=dfs(a[v][i].f);
            re+=t+a[v][i].s;
            if(t==0&&a[v][i].s)
                ans.push_back(a[v][i].f);
        }
    }
    return re;
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int f,s,t;
        cin>>f>>s>>t;
        t--;
        a[f].push_back(make_pair(s,t));
        a[s].push_back(make_pair(f,t));
    }
    dfs(1);
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}