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
int n;
int a[MN],v[MN],p[MN];
int stk[MN],tp;
int h[MN];
int m,x[MN],y[MN];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	dF(i,n,1){
		if(a[i]==1)stk[++tp]=i;
		else if(a[i]==2){
			if(tp)p[i]=stk[tp],v[stk[tp]]=1,--tp;
			else return puts("-1"),0;
		}
	}
	tp=0;
	dF(i,n,1){
		if(a[i]==2||(a[i]==1&&!v[i]))stk[++tp]=i;
		else if(a[i]==3){
			if(tp)p[i]=stk[tp--];
			else return puts("-1"),0;
			stk[++tp]=i;
		}
	}
	F(i,1,n)debug("%d%c",a[i]," \n"[i==n]);
	F(i,1,n)debug("%d%c",v[i]," \n"[i==n]);
	F(i,1,n)debug("%d%c",p[i]," \n"[i==n]);
	int r=n;
	dF(i,n,1){
		if(a[i]==1){
			++m,x[m]=r,y[m]=i;
			h[i]=r;
			--r;
		}else if(a[i]==2){
			++m,x[m]=h[p[i]],y[m]=i;
		}else if(a[i]==3){
			++m,x[m]=r,y[m]=i;
			++m,x[m]=r,y[m]=p[i];
			--r;
		}
	}
	printf("%d\n",m);
	F(i,1,m)printf("%d %d\n",x[i],y[i]);
	return 0;
}