
// Problem : D. Little Elephant and Broken Sorting
// Contest : Codeforces - Codeforces Round #157 (Div. 1)
// URL : https://codeforces.com/problemset/problem/258/D
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
const int N=1010;
int n,m,a[N];
double res,f[N][N];
int main()
{
	cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[i]>a[j])
				f[i][j]=1.0;
            else 
				f[j][i]=1.0;
	int x,y;
    while(m--)
    {
    	cin>>x>>y;
        if(x==y)continue;
        for(int i=1;i<=n;i++)
        {
            if(i==x||i==y)
				continue;
            f[i][x]=f[i][y]=(f[i][x]+f[i][y])/2;
            f[x][i]=f[y][i]=(f[x][i]+f[y][i])/2;
        }
        f[x][y]=f[y][x]=0.5;
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            res+=f[i][j];
            cout<<fixed<<setprecision(9)<<res;
}