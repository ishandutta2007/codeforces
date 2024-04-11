#include<bits/stdc++.h>
#define N 4000010
using namespace std;
int n,m,V[N],g[N],b[N],ff,i,a[N],ln,f[N],j,ap,gs[N],ans[N];
struct mjj{int x,y,z,a;}c[N];
bool cmp(mjj x,mjj y){return x.x<y.x;}
int ask(int l,int r,int L,int R,int cur)
{
	int mid=(l+r)>>1,ans=0,aa=0;
	if(L<=l&&R>=r)return V[cur];
	if(L<=mid)ans=ask(l,mid,L,R,cur<<1);
	if(R>mid)
	{
		aa=ask(mid+1,r,L,R,cur<<1|1);
		if(g[aa]>g[ans])ans=aa;else
		if(g[aa]==g[ans])ans=ff?aa:ans;
	}
	return ans;
}
void add(int l,int r,int x,int y,int cur)
{
	if(l==r){if(g[y]>=g[V[cur]])V[cur]=y;return;}
	int mid=(l+r)>>1;
	if(x<=mid)add(l,mid,x,y,cur<<1);
	else add(mid+1,r,x,y,cur<<1|1);
	V[cur]=V[cur<<1];
	if(g[V[cur<<1|1]]>g[V[cur]])V[cur]=V[cur<<1|1];
	else if(g[V[cur<<1|1]]==g[V[cur]]&&ff)V[cur]=V[cur<<1|1];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[++ln]=a[i];
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&c[i].x,&c[i].y);
		b[++ln]=c[i].y;c[i].z=i;
	}
	sort(c+1,c+m+1,cmp);j=1;
	sort(b+1,b+ln+1);ff=0;
	ln=unique(b+1,b+ln+1)-b-1;
	for(i=1;i<=n;i++)
	{
		a[i]=lower_bound(b+1,b+ln+1,a[i])-b;
		f[i]=a[i]>1?ask(1,ln,1,a[i]-1,1):0;g[i]=g[f[i]]+1;
		for(;c[j].x==i&&j<=m;j++)
		{
			c[j].y=lower_bound(b+1,b+ln+1,c[j].y)-b;
			c[j].a=c[j].y>1?g[ask(1,ln,1,c[j].y-1,1)]:0;
		}
		add(1,ln,a[i],i,1);
	}
	memset(V,0,sizeof(V));
	ap=0;
	for(i=n;i>=1;i--)if(g[i]>ap)ap=g[i];
	for(i=n;i>=1;i--)if(g[i]==ap)break;
	for(;i;i=f[i])gs[i]++;
	j=m;ff=1;
	for(i=n;i>=1;i--)
	{
		f[i]=a[i]<ln?ask(1,ln,a[i]+1,ln,1):0;
		g[i]=g[f[i]]+1;
		for(;c[j].x==i&&j>0;j--)
			c[j].a+=(c[j].y<ln?g[ask(1,ln,c[j].y+1,ln,1)]:0)+1;
		add(1,ln,a[i],i,1);
	}
	for(i=1;i<=n;i++)if(g[i]==ap)break;
	for(;i;i=f[i])gs[i]++;
	for(i=1;i<=m;i++)
	{
		if(gs[c[i].x]==2)ans[c[i].z]=max(c[i].a,ap-1);
		else ans[c[i].z]=max(c[i].a,ap);
	}
	for(i=1;i<=m;i++)
		printf("%d\n",ans[i]);
}