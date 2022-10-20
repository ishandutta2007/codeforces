#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int B=300;
const int sizB=N/B+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int L[sizB],R[sizB],bel[N],cnt[sizB],tag[sizB],fa[N],b[N],n,m,q;
void dec(int x,int y){fa[x]=max(fa[x]-y,1);}
void fix(int x)
{
	for (int i=L[x];i<=R[x];i++) dec(i,tag[x]);
	for (int i=L[x];i<=R[x];i++)
	if (fa[i]<L[x]) b[i]=fa[i];
			   else b[i]=b[fa[i]];
	tag[x]=0;
}
int getb(int x){return max(b[x]-tag[bel[x]],1);}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	n=read(),q=read();
	for (int i=2;i<=n;i++) fa[i]=read();
	for (int i=2;i<=n;i++) bel[i]=(i-2)/B+1;
	for (int i=2;i<=n;i++) R[bel[i]]=i;
	for (int i=n;i>=2;i--) L[bel[i]]=i;
	m=bel[n];
	for (int i=1;i<=m;i++) fix(i);
	while (q--)
	{
		int opt=read();
		if (opt==1)
		{
			int l=read(),r=read(),x=read();
			if (bel[l]==bel[r])
			{
				for (int i=l;i<=r;i++) dec(i,x);
				fix(bel[l]);
				continue;
			}
			for (int i=l;i<=R[bel[l]];i++) dec(i,x); fix(bel[l]);
			for (int i=L[bel[r]];i<=r;i++) dec(i,x); fix(bel[r]);
			for (int i=bel[l]+1;i<bel[r];i++)
			{
				tag[i]=min(tag[i]+x,n);
				cnt[i]++;
				if (cnt[i]<B) fix(i);
			}
		}
		else
		{
			int u=read(),v=read();
			while (u!=v)
			{
				if (bel[u]!=bel[v])
				{
					if (bel[u]<bel[v]) swap(u,v);
					u=getb(u);
				}
				else if (getb(u)!=getb(v)) u=getb(u),v=getb(v);
				else
				{
					if (u<v) swap(u,v);
					u=max(fa[u]-tag[bel[u]],1);
				}
			}
			print(u);
		}
	}
	
	return 0;
}