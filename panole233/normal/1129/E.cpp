#include<bits/stdc++.h>
using namespace std;

int siz[501],n,hd[501],sz[501],id[501],cnt,x,qa,s[501];
struct node{int to,next;}e[1001];
bool bo[501],boo[501];

bool cmp(int a,int b) {return siz[a]>siz[b];}
void addedge(int x,int y) {e[++cnt]=(node){y,hd[x]},hd[x]=cnt;}

void getsz(int x,int fa)
{
	sz[x]=1,boo[x]=1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa&&!bo[e[i].to]) getsz(e[i].to,x),sz[x]+=sz[e[i].to]; 
}

int Find(vector<int> v,int y,int x)
{
	if (v.size()==1) return v[0];
	int l=1,r=v.size(),mid,ans;
	s[0]=0; bool bo;
	for (int i=1; i<=r; i++) s[i]=s[i-1]+sz[v[i-1]];
	while (l<r)
	{
		for (mid=l; mid<=r; mid++) if (s[mid]-s[l-1]>(s[r]-s[l-1])/2) break;
		if (mid==r||mid!=l&&(s[r]-s[l-1])/2-(s[mid-1]-s[l-1])<(s[mid]-s[l-1])-(s[r]-s[l-1])/2) mid--;
		bo=0; for (int i=l; i<=mid; i++) if (v[i-1]==x) {bo=1; break;}
		if (!bo)
		{
			puts("1"); printf("%d\n",y); printf("%d\n",mid-l+1);
			for (int i=l; i<=mid; i++) printf("%d ",v[i-1]); puts("");
			printf("%d\n",x); fflush(stdout); scanf("%d",&qa);
			if (qa==mid-l) r=mid; else l=mid+1;
		} else
		{
			puts("1"); printf("%d\n",y); printf("%d\n",r-mid);
			for (int i=mid+1; i<=r; i++) printf("%d ",v[i-1]); puts("");
			printf("%d\n",x); fflush(stdout); scanf("%d",&qa);
			if (qa==r-mid) r=mid; else l=mid+1;
		}
	}
	return v[l-1];
}

int find(int x,int y)
{
	memset(boo,0,sizeof(boo));
	getsz(x,0);
	if (sz[x]==1) return x;
	if (sz[x]==2)
	{
		int z;
		for (int i=1; i<=n; i++) if (boo[i]&&i!=x) z=i;
		puts("1"); printf("%d\n",y); puts("1"); printf("%d\n%d\n",x,z); fflush(stdout);
		scanf("%d",&qa); if (qa==1) return z; return x;
	}
	int mi=sz[x]+1,mii,ma;
	for (int i=1; i<=n; i++) if (boo[i]) 
	{
		ma=0;
		for (int j=hd[i]; j; j=e[j].next)
			if (!bo[e[j].to])
			{
				if (sz[e[j].to]>sz[i]) ma=max(sz[x]-sz[i],ma);
				else ma=max(sz[e[j].to],ma);
			}
		if (ma<mi) mi=ma,mii=i; 
	}
	x=mii; getsz(x,0);
	vector<int> v; v.clear();
	for (int i=hd[x]; i; i=e[i].next)
		if (!bo[e[i].to]) v.push_back(e[i].to);
	mi=sz[x]+1;
	for (int i=0; i<v.size(); i++) if (sz[v[i]]<mi) mi=sz[v[i]],mii=i;
	sz[x]=sz[v[mii]]+1; v[mii]=x;
	int z=Find(v,y,x);
	if (z==x) 
	{
		for (int j=0; j<v.size(); j++) if (j!=mii) bo[v[j]]=1;
	} else bo[x]=1;
	return find(z,y);
}

int main()
{
	scanf("%d",&n); siz[1]=n,cnt=0;
	for (int i=2; i<=n; i++)
	{
		puts("1"),puts("1");
		printf("%d\n",n-1);
		for (int j=2; j<=n; j++) printf("%d ",j); puts("");
		printf("%d\n",i); fflush(stdout);
		scanf("%d",&siz[i]);
	}
	for (int i=1; i<=n; i++) id[i]=i;
	sort(id+1,id+1+n,cmp);
	addedge(id[1],id[2]),addedge(id[2],id[1]);
	for (int i=3; i<=n; i++) 
	{
		memset(bo,0,sizeof(bo));
		x=find(1,id[i]);
		addedge(x,id[i]),addedge(id[i],x);
	}
	puts("ANSWER");
	for (int i=1; i<=n; i++)
		for (int j=hd[i]; j; j=e[j].next)
			if (e[j].to>i) printf("%d %d\n",i,e[j].to);
	fflush(stdout);
	return 0;
}