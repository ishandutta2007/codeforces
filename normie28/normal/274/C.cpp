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
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,decltype(cmp),rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;


int n,i,j,k,l;
int x[105],y[105],dist[105][105];
double res,a,b,a1,a2,b1,b2,c1,c2;
 
int cal(int a,int b,int c){return (x[b]-x[a])*(x[c]-x[a])+(y[b]-y[a])*(y[c]-y[a]);}
void check(double X,double Y,double Min)
{
	int i;double tmp;
	for(i=1;i<=n;++i)
	{
		tmp=sqrt((x[i]-X)*(x[i]-X)+(y[i]-Y)*(y[i]-Y));
		if(tmp+0.000001<Min)return;
	}
	if(Min>res)res=Min;
}
 
int main()
{
    fio;
    cin>>n;
	for(i=1;i<=n;++i) cin>>x[i]>>y[i];
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	dist[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
	for(i=1;i<=n;++i)
	for(j=i+1;j<=n;++j)
	for(k=j+1;k<=n;++k)
	if(cal(i,j,k)>0&&cal(j,i,k)>0&&cal(k,i,j)>0)
	{
		a1=-2*(x[j]-x[i]);b1=-2*(y[j]-y[i]);c1=x[i]*x[i]-x[j]*x[j]+y[i]*y[i]-y[j]*y[j];
		a2=-2*(x[k]-x[i]);b2=-2*(y[k]-y[i]);c2=x[i]*x[i]-x[k]*x[k]+y[i]*y[i]-y[k]*y[k];
		if(x[i]==x[j])swap(a1,a2),swap(b1,b2),swap(c1,c2);
		b2-=b1*a2/a1;c2-=c1*a2/a1;a2=0;
		b=c2/b2;c1-=b*b1;b1=0;a=c1/a1;
		check(a,b,sqrt((x[i]-a)*(x[i]-a)+(y[i]-b)*(y[i]-b)));
	}
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)if(i!=j)
	for(k=1;k<=n;++k)if(i!=k&&j!=k)
	if(dist[i][j]==dist[i][k]&&dist[j][k]==2*dist[i][j])
	for(l=1;l<=n;++l)
	if(dist[j][l]==dist[i][j]&&dist[k][l]==dist[i][j]&&dist[i][l]==2*dist[i][j])
	check(0.5*(x[i]+x[l]),0.5*(y[i]+y[l]),sqrt(2*dist[i][j])/2);
	if(res<0.0001) cout<<-1;
	else cout<<fixed<<setprecision(10)<<res;
}