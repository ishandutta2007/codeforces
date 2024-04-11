//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
#define double ld
using namespace std;
mt19937 rng(time(NULL));
const int N=300501;
vector<int>g[N];
int used[N];
int n,m;
bool OK=true;
void dfs(int v){
    used[v]=1;
    for (auto to:g[v]){
        if (used[to]==2){
            OK=false;
        }
        if (!used[to]){
            dfs(to);
        }
    }
    used[v]=2;
}
bool ok(int v){
    OK=true;
    for (int i=1;i<=n;i++){
        used[i]=0;
    }
    dfs(v);
    return OK;
}
bool god[N];
int h[N];
int mn[N];
int mn1[N];
void dfs1(int v,int cur){
    h[v]=cur;
    mn[v]=h[v];
    mn1[v]=h[v];
    used[v]=true;
//    cout<<v<<" "<<cur<<endl;
    for (auto to:g[v]){
//        if (v==1) cout<<"OK "<<mn1[v]<<endl;
        if (used[to]){
            if (h[to]<mn[v]){
                mn1[v]=mn[v];
                mn[v]=h[to];
            } else if (h[to]<mn1[v]){
                mn1[v]=h[to];
            }
        } else {
            dfs1(to,cur+1);
            int x=mn[to];
            if (x<mn[v]){
                mn1[v]=mn[v];
                mn[v]=x;
            } else if (x<mn1[v]){
                mn1[v]=x;
            }
            x=mn1[to];
            if (x<mn[v]){
                mn1[v]=mn[v];
                mn[v]=x;
            } else if (x<mn1[v]){
                mn1[v]=x;
            }
        }
    }

}
vector<int>order;
void dfs2(int v){
    if (mn1[v]<h[v]) god[v]=false;
    else god[v]=true;
    used[v]=true;
    order.push_back(v);
    god[v]&=god[order[mn[v]]];

    for (auto to:g[v]){
        if (!used[to]){
            dfs2(to);
        }
    }
    order.pop_back();
}
void solve(){
    cin>>n>>m;
    for (int i=0;i<=n+10;i++){
        g[i].clear();
        used[i]=0;
    }
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
    }
    int good=-1;
    for (int it=1;it<=70;it++){
        int v=rng()%n+1;
        if (ok(v)){
            good=v;
            break;
        }
    }
    if (good==-1){
        cout<<-1<<endl;
        return;
    }
    for (int i=1;i<=n;i++){
        used[i]=false;
    }
    dfs1(good,0);
    for (int i=1;i<=n;i++){
        used[i]=false;
    }
    dfs2(good);
    vector<int>ans;
    for (int i=1;i<=n;i++){
        if (god[i]) ans.push_back(i);
    }
    if (ans.size()*5<n){
        cout<<-1<<endl;
    } else {
        for (auto i:ans) cout<<i<<" ";
        cout<<endl;
    }

}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
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
7 10
1 2
2 3
3 1
1 4
4 5
5 1
4 6
6 7
7 4
6 1
*/