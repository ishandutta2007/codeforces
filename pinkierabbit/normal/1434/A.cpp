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
int n,a[7],b[MN];
int x[MN*6],y[MN*6],p[MN*6],c;
int k[MN];
int main(){
	F(j,1,6)scanf("%d",&a[j]);
	sort(a+1,a+6+1);
	scanf("%d",&n);
	F(i,1,n)scanf("%d",&b[i]);
	sort(b+1,b+n+1);
	F(i,1,n)F(j,1,6){
		++c;
		x[c]=i;
		y[c]=j;
		p[c]=c;
	}
	sort(p+1,p+c+1,[](int i,int j){
		return b[x[i]]-a[y[i]]<b[x[j]]-a[y[j]];
	});
	F(i,1,n)k[i]=6;
	int mxv=b[n]-a[6],ans=inf;
	F(i,1,c){
		debug("(%d,%d,%d),mxv=%d\n",b[x[p[i]]],a[y[p[i]]],b[x[p[i]]]-a[y[p[i]]],mxv);
		int now=b[x[p[i]]]-a[y[p[i]]];
		ans=min(ans,mxv-now);
		int id=x[p[i]];
		if(!--k[id])break;
		mxv=max(mxv,b[id]-a[k[id]]);
	}
	printf("%d\n",ans);
	return 0;
}