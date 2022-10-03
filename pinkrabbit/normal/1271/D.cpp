#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 5005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,m,k,ans;
int a[MN],b[MN],c[MN],p[MN];
int col[MN],num[MN];
int main(){int x,y;
	scanf("%d%d%d",&n,&m,&k);
	F(i,1,n)scanf("%d%d%d",a+i,b+i,c+i),col[i]=i,p[i]=i;
	F(i,1,m)scanf("%d%d",&x,&y),col[y]=max(col[y],x);
	sort(p+1,p+n+1,[](int i,int j){return c[i]>c[j];});
	F(i,1,n)num[i]=k,k+=b[i];
	F(i,1,n)if(num[i]<a[i])return puts("-1"),0;
	F(i,1,n){
		int pos=col[p[i]],ok=1;
		F(j,pos+1,n)--num[j];
		F(j,1,n)if(num[j]<a[j])ok=0;
		if(!ok)F(j,pos+1,n)++num[j];
		else ans+=c[p[i]];
//		F(j,1,n)printf("(%d,%d),",num[j],a[j]);puts("");
	}
	printf("%d\n",ans);
	return 0;
}