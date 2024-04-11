#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 500005
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
int n,a[MN],d1[MN],d2[MN];
int lpf[(int)1e7+5];
int main(){
	int v=1e7;
	F(i,2,v)if(!lpf[i]){
		for(int j=i;j<=v;j+=i)
			if(!lpf[j]) lpf[j]=i;
	}
//	F(i,1,100)printf("%d:%d\n",i,lpf[i]);
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),d1[i]=d2[i]=-1;
	
	F(i,1,n){
		int x=a[i],p=lpf[a[i]];
		while(x%p==0)x/=p;
		if(x!=1){
			d1[i]=p;
			d2[i]=x;
		}
	}
	
	F(i,1,n)printf("%d%c",d1[i]," \n"[i==n]);
	F(i,1,n)printf("%d%c",d2[i]," \n"[i==n]);
	return 0;
}