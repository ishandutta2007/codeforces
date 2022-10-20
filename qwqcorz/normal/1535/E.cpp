#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;
const int B=750;
const pair<int,int>inf=make_pair(1145141,-1);

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
bool c[N];
vector<int>son[N];
int fa[N],top[N],siz[N],id[N];
pair<int,int>a[N],mn[N];
int find(int x)
{
	pair<int,int>ret=inf;
	while (~x)
	{
		ret=min(ret,mn[x]);
		x=fa[top[x]];
	}
	return ret.second;
}
void erase(int x)
{
	c[x]=1;
	x=top[x];
	for (int i:son[x]) mn[i]=min(i!=x?mn[fa[i]]:inf,c[i]?inf:make_pair(a[i].second,i));
}

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int q=read(),n=0;
	a[0].first=read();
	a[0].second=read();
	siz[0]=1;
	fa[0]=-1;
	mn[0]=make_pair(a[0].second,0);
	son[0].push_back(0);
	for (int i=1;i<=q;i++)
	{
		int opt=read();
		if (opt==1)
		{
			id[i]=++n;
			fa[n]=id[read()];
			a[n].first=read();
			a[n].second=read();
			if (siz[top[fa[n]]]<B) siz[top[n]=top[fa[n]]]++,mn[n]=min(mn[fa[n]],make_pair(a[n].second,n));
							  else siz[top[n]=n]=1,mn[n]=make_pair(a[n].second,n);
			son[top[n]].push_back(n);
		}
		else
		{
			int x=id[read()],w=read();
			int ans1=0;
			ll ans2=0;
			do
			{
				int now=find(x);
				if (now<0) break;
				int tmp=min(a[now].first,w);
				w-=tmp,a[now].first-=tmp;
				ans1+=tmp;
				ans2+=1LL*tmp*a[now].second;
				if (!a[now].first) erase(now);
//				print(now,' ');print(w,' '),print(a[now].first);
			}while (w);
			print(ans1,' '),print(ans2);
			fflush(stdout);
		}
	}
	
	return 0;
}