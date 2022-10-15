
// Problem : E. Helper
// Contest : Codeforces - Codeforces Beta Round #33 (Codeforces format)
// URL : https://codeforces.com/problemset/problem/33/E
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
#define pb push_back
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
#define N 110
#define M 43210
#define L 16
struct E
{
    int w,x,p,z;
    E(){}
    E(int _w,int _x,int _p,int _z):w(_w),x(_x),p(_p),z(_z){}
    bool operator < (const E&a) const {return x<a.x;}
};
int n,m,p,a[N];map<string,int> A;int f[N][M],g[N][M],w[M][L];bool v[M];
vector<E> B;
int gg(int x,int y)
{
    int p=x;
    for(int i=0,p2=p;i<L;i++)
        if((y>>i)&1)p=w[p2][i],p2=p+1;
    return p;
}
void ff(int x,int y,int z)
{
    if(g[x][y]==-1)printf("%d\n",z);else
    if(g[x][y]==y)ff(x-1,y,z);else
    {
        ff(x-1,g[x][y],z+1);
        int l=w[g[x][y]][0],r=y-1;
        printf("%d %d %02d:%02d %d %02d:%02d\n",B[x-1].z+1,l/1440+1,l%1440/60,l%60,r/1440+1,r%1440/60,r%60);
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    for(int i=0,t=0;i<n;i++){string s;cin>>s;A[s]=t++;}
    for(int i=0;i<n;i++)scanf("%d",a+i);
    for(int i=0;i<4;i++)
    {
        int x0,y0,x1,y1;
        scanf("%2d:%2d-%2d:%2d",&x0,&y0,&x1,&y1);
        for(int j=0;j<p;j++)
            for(int k=x0*60+y0;k<=x1*60+y1;k++)v[j*1440+k]=1;
    }
    int P=p*1440;
    for(int j=0;j<L;j++)w[P][j]=P-1;
    for(int i=P-1;i>=0;i--)
    {
        if(v[i])w[i][0]=w[i+1][0];else w[i][0]=i;
        for(int j=1;j<L;j++)w[i][j]=w[w[i][j-1]+1][j-1];
    }
    for(int i=0;i<m;i++)
    {
        string s;cin>>s;int z,x,y,p;
        scanf("%d%2d:%2d%d",&z,&x,&y,&p),--z;
        if(A.find(s)==A.end())continue;
        B.pb(E(A[s],z*1440+x*60+y,p,i));
    }
    sort(B.begin(),B.end()),m=(int)B.size();
    memset(g,-1,sizeof g);
    for(int i=0;i<m;i++)
        for(int j=0;j<P;j++)
        {
            if(f[i][j]>f[i+1][j])
                f[i+1][j]=f[i][j],g[i+1][j]=j;
            int z=gg(j,a[B[i].w]);
            if(z>=B[i].x)continue;
            if(f[i][j]+B[i].p>f[i+1][z+1])
                f[i+1][z+1]=f[i][j]+B[i].p,g[i+1][z+1]=j;
        }
    int S=0,T=0;
    for(int i=0;i<=P;i++)if(f[m][i]>S)S=f[m][i],T=i;
    printf("%d\n",S);ff(m,T,0);
    return 0;
}