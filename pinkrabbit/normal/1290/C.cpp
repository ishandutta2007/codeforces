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
int n,k,ans;
int a[MN],d[MN];
vector<int>g[MN];
int fa[MN],siz[MN],col[MN],cnt1[MN],cnt2[MN];
inline int ff(int x,int&c){
	c=0;
	while(fa[x])c^=col[x],x=fa[x];
	return x;
}
inline void merge(int x,int y,int c){
//	printf("%d <-> %d : %d\n", x, y, c);
	int c1,c2,C;
	x=ff(x,c1),y=ff(y,c2);
	if(x==y)return;
	C=c^c1^c2;
	if(y==k+1)swap(x,y);
	if(x!=k+1&&siz[x]<siz[y])swap(x,y);
	if(x==k+1)ans-=cnt1[x];
	else ans-=min(cnt1[x],cnt2[x]);
	ans-=min(cnt1[y],cnt2[y]);
	if(C)cnt1[x]+=cnt2[y],cnt2[x]+=cnt1[y];
	else cnt1[x]+=cnt1[y],cnt2[x]+=cnt2[y];
	siz[x]+=siz[y];
	fa[y]=x,col[y]=C;
	if(x==k+1)ans+=cnt1[x];
	else ans+=min(cnt1[x],cnt2[x]);
//	printf("(cnt1, cnt2)[%d] = (%d, %d)\n", x, cnt1[x], cnt2[x]);
}
int main(){
	scanf("%d%d",&n,&k);
	F(i,1,n)scanf("%1d",a+i);
	F(i,1,k){
		int c,x;
		scanf("%d",&c);
		F(j,1,c)scanf("%d",&x),++d[x],g[x].push_back(i);
	}
	F(i,1,k+1)siz[i]=1,cnt1[i]=1;
	cnt1[k+1]=0;
	F(i,1,n){
		if(!d[i]){printf("%d\n",ans);continue;}
		if(d[i]==1){merge(g[i][0],k+1,a[i]);printf("%d\n",ans);continue;}
		merge(g[i][0],g[i][1],!a[i]);
		printf("%d\n",ans);
	}
	return 0;
}