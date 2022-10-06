#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 100005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int r,n,t[MN],x[MN],y[MN],f[MN],g[MN];
int main(){
	scanf("%d%d",&r,&n);
	F(i,1,n)scanf("%d%d%d",t+i,x+i,y+i);
	t[0]=0,x[0]=1,y[0]=1,f[0]=0;
	F(i,1,n){
		f[i]=-inf;
		int j=i-1;
		while(j>=0&&t[i]-t[j]<2*(r-1)){
			if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])
				f[i]=max(f[i],f[j]+1);
			--j;
		}
		if(j>=0)f[i]=max(f[i],g[j]+1);
		g[i]=max(f[i],g[i-1]);
	}
	printf("%d\n",g[n]);
	return 0;
}