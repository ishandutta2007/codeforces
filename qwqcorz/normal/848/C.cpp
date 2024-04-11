#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;

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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
const int p=15000017;
struct BIT
{
	struct hash
	{
		signed keyx[p],keyy[p];
		int val[p];
		hash(){memset(keyx,-1,sizeof(keyx));}
		void add(signed x,signed y,int z)
		{
			signed k=(x+y*1145141LL)%p;
			while (~keyx[k]&&(keyx[k]!=x||keyy[k]!=y)) k+=5,k>=p?k-=p:0;
			keyx[k]=x;
			keyy[k]=y;
			val[k]+=z;
		}
		int query(signed x,signed y)
		{
			signed k=(x+y*1145141LL)%p;
			while (~keyx[k]&&(keyx[k]!=x||keyy[k]!=y)) k+=5,k>=p?k-=p:0;
			return val[k];
		}
	}h;
	int n;
	void send(int _n)
	{
		n=_n+5;
	}
	void add(int x,int y,int z)
	{
		x++;
		y++;
		for (int i=x;i<=n;i+=i&-i)
		for (int j=y;j<=n;j+=j&-j)
		h.add(i,j,z);
	}
	int query(int x,int y)
	{
		x++;
		y++;
		int ret=0;
		for (int i=x;i;i-=i&-i)
		for (int j=y;j;j-=j&-j) ret+=h.query(i,j);
		return ret;
	}
}t;
set<int>s[N];
int a[N],l[N],n,m;
void change(int x,int y)
{
	if (x>n) return;
	t.add(l[x],x,-(x-l[x]));
	l[x]=y;
	t.add(l[x],x,x-l[x]);
}

signed main()
{
	n=read(),m=read();
	t.send(n+1);
	for (int i=1;i<=n;i++) s[i].insert(0);
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		l[i]=*s[a[i]].rbegin();
		t.add(l[i],i,i-l[i]);
		s[a[i]].insert(i);
	}
	for (int i=1;i<=n;i++) s[i].insert(n+1);
	for (int i=1;i<=m;i++)
	{
		int opt=read(),x=read(),y=read();
		if (opt==1)
		{
			if (a[x]==y) continue;
			auto u=s[a[x]].lower_bound(x);
			auto v=s[y].lower_bound(x);
			v--;
			auto L=u,R=u;
			L--,R++;
			change(*R,*L);
			change(x,*v);
			change(*++v,x);
			s[a[x]].erase(x);
			s[y].insert(x);
			a[x]=y;
		}
		else print(t.query(y,y)-t.query(x-1,y));
	}
	
	return 0;
}