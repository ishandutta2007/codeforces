#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int L=17;
int up[100001][18];
int tin[100001];
int tout[100001];
int h[100001];
int timer=0;
vector<int>g[100001];
void dfs(int v,int pr,int cur){
     h[v]=cur;
     up[v][0]=pr;
     tin[v]=++timer;
     for (int i=1;i<=L;i++){
        up[v][i]=up[up[v][i-1]][i-1];
     }
     for (auto to:g[v]){
         dfs(to,v,cur+1);
     }
     tout[v]=++timer;
}
bool upper(int a,int b){
     return (tin[a]<=tin[b] && tout[a]>=tout[b]);
}
int lca(int a,int b){
    if (upper(a,b)) return a;
    if (upper(b,a)) return b;
    for (int i=L;i>=0;i--){
        if (!upper(up[a][i],b)) a=up[a][i];
    }
    return up[a][0];
}
pair<int,int> t1[400001];
void build1(int v,int l,int r){
    if (l==r){
        t1[v]={tin[l],l};
        return;
    }
    int m=(l+r)/2;
    build1(2*v,l,m);
    build1(2*v+1,m+1,r);
    t1[v]=max(t1[2*v],t1[2*v+1]);
}
pair<int,int> get1(int v,int l,int r,int L,int R){
              if (l>R || r<L) return {0,0};
              if (l>=L && r<=R) return t1[v];
              int m=(l+r)/2;
              return max(get1(2*v,l,m,L,R),get1(2*v+1,m+1,r,L,R));
}
pair<int,int> t2[400001];
void build2(int v,int l,int r){
    if (l==r){
        t2[v]={tin[l],l};
        return;
    }
    int m=(l+r)/2;
    build2(2*v,l,m);
    build2(2*v+1,m+1,r);
    t2[v]=min(t2[2*v],t2[2*v+1]);
}
pair<int,int> get2(int v,int l,int r,int L,int R){
              if (l>R || r<L) return {100000001,10000001};
              if (l>=L && r<=R) return t2[v];
              int m=(l+r)/2;
              return min(get2(2*v,l,m,L,R),get2(2*v+1,m+1,r,L,R));
}
int32_t main() {
    int n,tt;cin>>n>>tt;
    for (int i=2;i<=n;i++){
        int p;cin>>p;
        g[p].push_back(i);
    }
    tin[0]=0;
    dfs(1,0,0);
    tout[0]=n+n+1;
    build1(1,1,n);
    build2(1,1,n);
    while (tt--){
        int l,r;cin>>l>>r;
        pair<int,int>x1=get1(1,1,n,l,r);
        pair<int,int>x2=get2(1,1,n,l,r);
        int lca1=lca(max(get1(1,1,n,l,x1.second-1),get1(1,1,n,x1.second+1,r)).second,min(get2(1,1,n,l,x1.second-1),get2(1,1,n,x1.second+1,r)).second);
        int lca2=lca(max(get1(1,1,n,l,x2.second-1),get1(1,1,n,x2.second+1,r)).second,min(get2(1,1,n,l,x2.second-1),get2(1,1,n,x2.second+1,r)).second);
        if (h[lca1]>h[lca2]) cout<<x1.second<<" "<<h[lca1]<<endl;
        else cout<<x2.second<<" "<<h[lca2]<<endl;
    }
    return 0;
}
//20000000000000