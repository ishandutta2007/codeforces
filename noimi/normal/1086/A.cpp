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
ll MOD=1e9+7;
#define INF 1e9+7

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
#define N 4e5
int ans[1100][1100]={};
int xmid,ymid;
void t(int a,int b){
    if(a>xmid){
        rep2(i,xmid,a){
            ans[i][ymid]++;
        }
    }
    else{
        rep2(i,a,xmid){
            ans[i][ymid]++;
        }
    }
    if(b>ymid){
        rep2(i,ymid,b){
            ans[a][i]++;
        }
    }
    else{
        rep2(i,b,ymid){
            ans[a][i]++;
        }
    }
}
main(){
    int xa=in(),ya=in(),xb=in(),yb=in(),xc=in(),yc=in();
    int xmax=max({xa,xb,xc}),xmin=min({xa,xb,xc});
    int ymax=max({ya,yb,yc}),ymin=min({ya,yb,yc});
    cout<<xmax+ymax-xmin-ymin+1<<endl;
    xmid=xa+xb+xc-xmax-xmin;ymid=ya+yb+yc-ymin-ymax;
    t(xa,ya);t(xb,yb);t(xc,yc);
    rep(i,1100)rep(j,1100){
        if(ans[i][j])cout<<i<<" "<<j<<endl;
    }
    
}