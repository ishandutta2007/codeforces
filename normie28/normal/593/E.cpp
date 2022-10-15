
// Problem : D. Binary String To Subsequences
// Contest : Codeforces - Codeforces Round #661 (Div. 3)
// URL : https://codeforces.com/contest/1399/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
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
#define maxn 20
#define int long long
const int mod=1e9+7;
int n,m,q;
bool vis[maxn][maxn];
struct matrix{
    int a[maxn][maxn];
    void init(){memset(a,0,sizeof(a));for(int i=0;i<maxn;i++)a[i][i]=1;}
    void print(){for(int i=0;i<maxn;i++){for(int j=0;j<maxn;j++)printf("%lld ",a[i][j]);printf("\n");}printf("\n");}
    matrix operator * (const matrix &x)const{
        matrix y;
        memset(y.a,0,sizeof(y.a));
        for(int i=0;i<maxn;i++)for(int j=0;j<maxn;j++)for(int k=0;k<maxn;k++)(y.a[i][j]+=(a[i][k]*x.a[k][j])%mod)%=mod;
        return y;
    }
    matrix operator = (const matrix &x){
        for(int i=0;i<maxn;i++)for(int j=0;j<maxn;j++)a[i][j]=x.a[i][j];
        return *this;
    }
}ans,base;
struct order{
    int type,x,y,t;
    bool operator < (const order &a){
        return t<a.t;
    }
}o[10008];
void build_base(){
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int k=0;k<n;k++)for(int z=0;z<m;z++){
        int now1=i*m+j;
        int now2=k*m+z;
        int dis=abs(k-i)+abs(z-j);
        if(!vis[i][j]&&!vis[k][z]&&dis<=1)base.a[now1][now2]=1;
        else base.a[now1][now2]=0;
    }
}
void q_pow(matrix base,int t){
    for(;t;t>>=1,base=base*base)if(t&1)ans=base*ans;
}
void solve(){
    sort(o+1,o+1+q);
    ans.a[0][0]=1;
    o[0].t=1;
    for(int i=1;i<=q;i++){
        int tim=o[i].t-o[i-1].t;
        build_base();
        q_pow(base,tim);
        if(o[i].type==1){
            printf("%lld\n",ans.a[o[i].x*m+o[i].y][0]);
        }else if(o[i].type==2){
            ans.a[o[i].x*m+o[i].y][0]=0;
            vis[o[i].x][o[i].y]=1;
        }else{
            ans.a[o[i].x*m+o[i].y][0]=0;
            vis[o[i].x][o[i].y]=0;
        }
    }
}
main(){
    cin>>n>>m>>q;
    for(int i=1;i<=q;i++)cin>>o[i].type>>o[i].x>>o[i].y>>o[i].t,o[i].x--,o[i].y--;
    solve();
}