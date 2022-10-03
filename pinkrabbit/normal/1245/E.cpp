#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int a[15][15],id[15][15],x[105],y[105],cnt;
double f[105];
int main(){
	F(i,1,10)F(j,1,10)scanf("%d",&a[i][j]);
	F(i,1,10)if(i&1)F(j,1,10)id[i][j]=++cnt,x[cnt]=i,y[cnt]=j;else dF(j,10,1)id[i][j]=++cnt,x[cnt]=i,y[cnt]=j;
	f[1]=0;
	F(i,2,100){
		double A=6;int B=6;
		F(j,1,6)if(i-j<=0)--B;else A+=std::min(f[i-j],f[id[x[i-j]-a[x[i-j]][y[i-j]]][y[i-j]]]);
		f[i]=A/B;
	}
	printf("%.10lf",f[100]);
	return 0;
}