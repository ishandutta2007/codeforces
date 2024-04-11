#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
#define MAX_V 400010
#define vec vector<int>
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
template<typename A, size_t NNN, typename T>
void Fill(A (&array)[NNN], const T &val){
    fill( (T*)array, (T*)(array+NNN), val );
}


#define INF 1e9+7
#define N 200001
ll MOD=998244353;
struct UnionFind{
    vector<int> par,sizes;
    UnionFind(int n):par(n+1),sizes(n+1,1){
        rep2(i,1,n)par[i]=i;
    }
    int root(int x){
        return (x==par[x]?x:par[x]=root(par[x]));
    }
    void unite(int x,int y){
        x=root(x);y=root(y);
        if(x==y)return ;
        if(sizes[x]<sizes[y]){
            swap(x,y);
        }
        par[y]=x;
        sizes[x]+=sizes[y];
    }
    bool same(int x,int y) {return (root(x)==root(y));}
    int size(int x) {return sizes[root(x)];}
};

main(){
    int n=in(),m=in(),k=in();
    UnionFind u(N);
    pair<int,pii> p[N];
    int mem;
    rep2(i,1,n){
        u.sizes[i]=0;
    }
    rep(i,k){
        mem=in();
        u.sizes[mem]++;
    }
    rep(i,m){
        int to=in(),from=in(),c=in();
        p[i]={c,{to,from}};
    }
    sort(p,p+m);
    int t=0;
    rep(i,m){
        int to=p[i].second.first,from=p[i].second.second,cost=p[i].first;
        if(u.same(to,from))continue;
        u.unite(to,from);
        if(u.size(mem)==k){
            rep(i,k){
                cout<<cost<<" ";
            }
            return 0;
        }
    }
}