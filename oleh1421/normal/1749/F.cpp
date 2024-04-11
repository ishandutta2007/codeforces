#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rnd(time(NULL));
const int N=200010;
const int L=21;
const ll mod=998244353;
int tin[N],tout[N];
int up[N][L];
int sz[N];
int mxto[N];
int timer=0;
vector<int>g[N];
void init(int v,int pr){
    up[v][0]=pr;
    for (int i=1;i<L;i++){
        up[v][i]=up[up[v][i-1]][i-1];
    }
    sz[v]=1;
    for (int to:g[v]){
        if (to!=pr){
            init(to,v);
            if (sz[mxto[v]]<sz[to]) mxto[v]=to;
            sz[v]+=sz[to];
        }
    }

}
int gl[N];
void dfs(int v,int pr,int mn){
    tin[v]=++timer;
    gl[v]=mn;
//    cout<<"TIN "<<v<<" "<<tin[v]<<endl;
    if (!mxto[v]) {
        tout[v]=timer;

        return;
    }
    dfs(mxto[v],v,mn);
    for (int to:g[v]){
        if (to!=pr && to!=mxto[v]){
            dfs(to,v,to);
        }
    }
    tout[v]=timer;

}
bool upper(int a,int b){
//    cout<<"X "<<a<<" "<<b<<" "<< tout[a]<<" "<<tout[b]<<endl;
    return (tin[a]<=tin[b] && tout[b]<=tout[a]);
}
int lca(int a,int b){
    if (upper(a,b)) return a;
    for (int i=L-1;i>=0;i--){
        if (!upper(up[a][i],b)) a=up[a][i];
    }
    return up[a][0];
}
struct BIT{
    int t[N];
    void upd(int pos,int x){
        for (;pos<N;pos|=pos+1) t[pos]+=x;
    }
    void add(int l,int r,int x){
        upd(l,x);
        upd(r+1,-x);
    }
    int get(int pos){
        int sum=0;
        for (;pos>=0;pos&=pos+1,pos--) sum+=t[pos];
        return sum;
    }
};
BIT T[L];
void ADD(int v,int pr,int k,int d){
//    cout<<v<<" "<<k<<" "<<d<<endl;
    while (!upper(gl[v],pr)){
        int l=tin[gl[v]];
        int r=tin[v];
        T[d].add(l,r,k);
        v=up[gl[v]][0];
    }
    int l=tin[pr]+1,r=tin[v];
    if (l<=r) T[d].add(l,r,k);
}
int get_value(int v){
    int ans=0;
    for (int it=0;it<L && v;it++){
        ans+=T[it].get(tin[v]);
        v=up[v][0];
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    tin[0]=timer;
    init(1,0);
    dfs(1,0,1);
    tout[0]=timer;
    cin>>m;
    for (int it=1;it<=m;it++){
        int type;cin>>type;
        if (type==1){
            int v;cin>>v;
            cout<<get_value(v)<<'\n';
        } else {
            int a,b,k,d;cin>>a>>b>>k>>d;
            int v=lca(a,b);
//            cout<<"LC "<<v<<endl;
            ADD(a,v,k,d);
            ADD(b,v,k,d);

            for (int it=0;it<d;it++){
                if (v==1){
                    for (int j=0;j<=d-it;j++){
//                        cout<<"X "<<j<<endl;
                        T[j].add(1,1,k);

                    }
                    v=0;
                    break;
                }
                T[d-it].add(tin[v],tin[v],k);
                T[d-it-1].add(tin[v],tin[v],k);
                v=up[v][0];
            }
            if (v){
                T[0].add(tin[v],tin[v],k);
            }
        }

    }
    return 0;
}
/**
6
1 2
1 3
4 2
5 2
3 6
6
1 3
1 6
1 3
2 3 2 10 0
2 5 2 10 1
1 1

**/