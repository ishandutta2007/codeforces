#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

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
int l[N],r[N];
struct ACAM
{
	struct node
	{
		int son[26];
		int fail,tot;
	}t[N];
	int cnt;
	void insert(char *a)
	{
		int now=0,n=strlen(a+1);
		#define to t[now].son[a[i]-'a']
		for (int i=1;i<=n;i++)
		{
			if (!to) to=++cnt;
			now=to;
		}
		#undef to
		t[now].tot++;
	}
	int q[N],H=1,T=0;
	void build()
	{
		for (int i=0;i<26;i++) if (t[0].son[i]) q[++T]=t[0].son[i];
		while (H<=T)
		{
			int now=q[H++];
			t[now].tot+=t[t[now].fail].tot;
			for (int i=0;i<26;i++)
			if (t[now].son[i])
			{
				t[t[now].son[i]].fail=t[t[now].fail].son[i];
				q[++T]=t[now].son[i];
			}
			else t[now].son[i]=t[t[now].fail].son[i];
		}
	}
}t1,t2;
char a[N],b[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	scanf("%s",a+1);
	int n=strlen(a+1),m=read();
	for (int i=1;i<=m;i++)
	{
		scanf("%s",b+1);
		t1.insert(b);
		reverse(b+1,b+1+strlen(b+1));
		t2.insert(b);
	}
	t1.build();
	t2.build();
	for (int i=1,now=0;i<=n;i++)
	{
		now=t1.t[now].son[a[i]-'a'];
		l[i]=t1.t[now].tot;
	}
	for (int i=n,now=0;i>=1;i--)
	{
		now=t2.t[now].son[a[i]-'a'];
		r[i]=t2.t[now].tot;
	}
	ll ans=0;
	for (int i=1;i<n;i++) ans+=1LL*l[i]*r[i+1];
	print(ans);
	
	return 0;
}