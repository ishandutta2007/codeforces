#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int p=998244353;

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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int ans;
inline void Mul(int x)
{
	ans*=x;
	if (ans>=p) ans-=p;
}
bool t[N];
int n,k,a[N],b[N],pre[N],nxt[N];
void del(int x)
{
	nxt[pre[x]]=nxt[x];
	pre[nxt[x]]=pre[x];
	pre[x]=0;
	nxt[x]=n+1;
}

signed main()
{
	memset(t,0,sizeof(t));
	int T=read();
	while (T--)
	{
		ans=1;
		n=read();
		k=read();
		for (int i=1;i<=n;i++) a[read()]=i;
		for (int i=1;i<=k;i++) t[b[i]=a[read()]]=1;
		for (int i=1;i<=n;i++)
		{
			pre[i]=i-1;
			nxt[i]=i+1;
		}
		for (int i=1;i<=k;i++)
		{
			t[b[i]]=0;
			int Pre=pre[b[i]],Nxt=nxt[b[i]],mul=0;
//			print(Pre,' ');print(Nxt);
			if (Pre>=1&&!t[Pre]) mul++;
			if (Nxt<=n&&!t[Nxt]) mul++;
//			print(mul);
			Mul(mul);
			if (Pre>=1&&!t[Pre]) del(Pre);
			else if (Nxt<=n&&!t[Nxt]) del(Nxt);
		}
		print(ans);
	}

	return 0;
}