//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
///use char if you want a naive algorithm to pass
#include <bits/stdc++.h>
//#include <vector>
#define endl '\n'
typedef long long ll;
using namespace std;
const int N=1000010;
vector<int>g[N];
vector<vector<int> >a;
int color[N];
int p[N];
int res=0;
int black=0;
bool solved[N];
bool inside[N];
bool used[N];
void dfs(int v,int h,int sz){
    if (color[v]) used[h%sz]=true;
    solved[v]=true;
    for (auto to:g[v]){
        if (!inside[to]){
            dfs(to,h+1,sz);
        }
    }

}
void component_solve(int root){
    int loop_size=1;
    int cur=root;
    vector<int>loop;
    inside[root]=true;
    while (p[cur]!=root){
        loop_size++;
        cur=p[cur];
        loop.push_back(cur);
        inside[cur]=true;
    }
    loop.push_back(root);
    reverse(loop.begin(),loop.end());
    res+=loop_size;
    for (int i=0;i<loop_size;i++){
        used[i]=false;
    }
    for (int i=0;i<loop_size;i++){
        dfs(loop[i],i,loop_size);
    }
    for (int i=0;i<loop_size;i++){
        black+=used[i];
    }


}
void solve(){
    int n,m;cin>>n>>m;
    a.clear();
    res=black=0;
    for (int i=0;i<=n*m;i++){
        g[i].clear();
        p[i]=-100;
        inside[i]=false;
        solved[i]=false;
    }
    a.resize(n);
    for (int i=0;i<n;i++){
        a[i].resize(m);
        for (int j=0;j<m;j++){
            char c;cin>>c;
            a[i][j]=i*m+j+1;
            color[a[i][j]]=(c-'0');
            color[a[i][j]]^=1;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            char c;cin>>c;
            if (c=='L'){
                g[a[i][j-1]].push_back(a[i][j]);
                p[a[i][j]]=a[i][j-1];
            } else if (c=='R'){

                g[a[i][j+1]].push_back(a[i][j]);
                p[a[i][j]]=a[i][j+1];
            } else if (c=='U'){
                g[a[i-1][j]].push_back(a[i][j]);
                p[a[i][j]]=a[i-1][j];
            } else {
                g[a[i+1][j]].push_back(a[i][j]);
                p[a[i][j]]=a[i+1][j];
            }
        }
    }
    for (int i=1;i<=n*m;i++){
        if (solved[i]) continue;
        vector<int>cur;
        int v=i;
        while (!solved[v]){
            solved[v]=true;
            v=p[v];
        }
        component_solve(v);
    }
    cout<<res<<" "<<black<<endl;
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
1
3 3
001
101
110
RLL
DLD
ULL
*/