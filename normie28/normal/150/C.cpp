
// Problem : C. Smart Cheater
// Contest : Codeforces - Codeforces Round #107 (Div. 1)
// URL : https://codeforces.com/problemset/problem/150/C
// Memory Limit : 256 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define debug(args...) fprintf(stderr, args);
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const int MAXN = 150005;
int x[MAXN],p[MAXN],sum[MAXN];
#define lson l,m,o<<1
#define rson m+1,r,o<<1|1
double pre[MAXN<<2],suf[MAXN<<2],su[MAXN<<2],mx[MAXN<<2];
 
void pushup(int o){
    pre[o]=max(0.0,max(pre[o<<1],su[o<<1]+pre[o<<1|1]));
    suf[o]=max(0.0,max(suf[o<<1|1],su[o<<1|1]+suf[o<<1]));
    su[o]=su[o<<1]+su[o<<1|1];
    mx[o]=max(0.0,mx[o<<1]);
    mx[o]=max(mx[o],mx[o<<1|1]);
    mx[o]=max(mx[o],suf[o<<1]+pre[o<<1|1]);
}
 
void update(int l,int r,int o,int p,double v){
    if(l==r){
        su[o]=v;
        pre[o]=suf[o]=mx[o]=max(0.0,v);
        return;
    }
    int m=l+r>>1;
    if(p<=m)update(lson,p,v);
    else update(rson,p,v);
    pushup(o);
}
 
double A,temp;
void call(int l,int r,int o,int L,int R){
    if(L<=l&&r<=R){
        A=max(A,mx[o]);
        A=max(A,temp+pre[o]);
        temp=max(temp+su[o],suf[o]);
        A=max(A,temp);
        return;
    }
    int m=l+r>>1;
    if(L<=m)call(lson,L,R);
    if(m<R)call(rson,L,R);
}
 
int main()
{
    int n,m,c; cin>>n>>m>>c;
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<n-1;i++) cin>>p[i];
    for(int i=1;i<n;i++){
        double res=0.0;
        res=1.0*(x[i]-x[i-1])/2-1.0*c*p[i-1]/100;
        update(1,n-1,1,i,res);
    }
    double res=0.0;
    for(int i=0;i<m;i++){
        int l,r; cin>>l>>r;
        A=0.0;
        temp=0.0;
        call(1,n-1,1,l,r-1);
        res+=A;
    }
    cout<<fixed<<setprecision(9)<<res;
}