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
inline int qpow(int b,ll e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,l;
int a[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&l);
	F(i,1,n)scanf("%d",a+i);
	a[0]=0,a[n+1]=l;
	double t1=0,t2=0;
	int j1=0,j2=n+1;
	while(j2-j1>=2){
		double nt1,nt2;
		nt1=t1+(a[j1+1]-a[j1])/(double)(j1+1);
		nt2=t2+(a[j2]-a[j2-1])/(double)(n-j2+2);
		if(nt1<nt2)++j1,t1=nt1;
		else --j2,t2=nt2;
	}
	printf("%.15lf\n",t1+(a[j2]+(t2-t1)*(n-j2+2)-a[j1])/(n+2));
}	return 0;
}