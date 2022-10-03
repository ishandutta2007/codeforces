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
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,int e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,k;
int a[MN],b[MN];
void Calc(int lb,int rb,int &x0,int &x1,int &x2,int &x3){
	if(rb-lb+1==4){
		int e1=b[lb]+b[lb+1];
		int e2=b[rb]+b[rb-1];
		if(!e1&&!e2)x0=0,x1=x2=x3=-inf;
		else if(!e1||!e2){
			if(e1+e2==1)x1=2,x2=3,x0=x3=-inf;
			else x3=4,x1=2,x2=3,x0=-inf;
		}else x1=3,x2=4,x3=5,x0=-inf;
//		printf("[%d~%d] : (%d, %d, %d, %d)\n", lb, rb, x0, x1, x2, x3);
		return;
	}
	int mid=(lb+rb)/2;
	int lx0,lx1,lx2,lx3,rx0,rx1,rx2,rx3;
	Calc(lb,mid,lx0,lx1,lx2,lx3);
	Calc(mid+1,rb,rx0,rx1,rx2,rx3);
	x0=x1=x2=x3=-inf;
	x0=max(x0,lx0+rx0);
	x1=max({x1,lx0+rx1+1,lx1+rx0+1,lx1+rx1+1});
	x2=max({x2,lx0+rx2+2,lx2+rx0+2,lx2+rx2+2});
	x3=max({x3,lx0+rx3+3,lx3+rx0+3,lx1+rx2+3,lx2+rx1+3,lx1+rx3+3,lx3+rx1+3,lx2+rx3+3,lx3+rx2+3,lx3+rx3+3});
//	printf("[%d~%d] : (%d, %d, %d, %d)\n", lb, rb, x0, x1, x2, x3);
}
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&k);
	F(i,1,k)scanf("%d",a+i),b[a[i]]=1;
	int x0,x1,x2,x3;
	Calc(1,1<<n,x0,x1,x2,x3);
	printf("%d\n",max({x0,x1+1,x2+1,x3+1}));
}	return 0;
}