#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;

int fa[M],val[M],id[M],size[M];
int find(int a){return fa[a]==a?a:fa[a]=find(fa[a]);}
void merge(int x,int y)
{
	if(id[y])fa[id[x]]=id[y];
	else
	{
		id[y]=id[x];
		val[id[y]]=y;
	}
	size[y]+=size[x];
	id[x]=size[x]=0;
}

int pl,pr,Maxn,tag,a[M];
int n,q,op[M],l[M],r[M],x[M],ans[M];
int bl,sl;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

void Build()
{
	Maxn=0;
	for (int i=pl;i<=pr;i++)
	{
		Maxn=max(Maxn,a[i]);
		if (id[a[i]]==0)
			fa[i]=id[a[i]]=i,val[i]=a[i];
		else fa[i]=id[a[i]];
		size[a[i]]++;
	}
}

void Break()
{
	for (int i=pl;i<=pr;i++)
	{
		a[i]=val[find(i)];
		size[a[i]]=id[a[i]]=0;
		a[i]-=tag;
	}
	for (int i=pl;i<=pr;i++)fa[i]=0;
	tag=0;
}

int main()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=q;i++)
		op[i]=read(),l[i]=read(),r[i]=read(),x[i]=read();
	bl=sqrt(n);sl=(n-1)/bl+1;
	for (int num=1;num<=sl;num++)
	{
		pl=pr+1,pr=min(n,num*bl);
		Build();
		for (int i=1;i<=q;i++)
		{
			if (op[i]==1)
			{
				if (r[i]<pl||l[i]>pr)continue;
				if (pr<=r[i]&&pl>=l[i])
				{
					if(Maxn-tag>=x[i]*2)
					{
						for(int j=tag+1;j<=tag+x[i];j++)
							if(id[j])
								merge(j,j+x[i]);
						tag+=x[i];
					}
					else
					{
						for(int j=Maxn;j>tag+x[i];j--)
							if(id[j])
								merge(j,j-x[i]);
						Maxn=min(tag+x[i],Maxn);
					}
				}
				else
				{
					Break();
					for (int j=max(pl,l[i]);j<=min(pr,r[i]);j++)
						if (a[j]>x[i])a[j]-=x[i];
					Build();
				}
			}
			else
			{
				if (r[i]<pl||l[i]>pr)continue;
				if (pr<=r[i]&&pl>=l[i])
				{
					if (x[i]+tag<=1e5+1)
						ans[i]+=size[x[i]+tag];
				}
				else
				{
					for (int j=max(pl,l[i]);j<=min(pr,r[i]);j++)
						if (val[find(j)]-tag==x[i])
							ans[i]++;
				}
			}
		}
		Break();
	}
	for (int i=1;i<=q;i++)
		if (op[i]==2)cout<<ans[i]<<endl;
	return 0;
}