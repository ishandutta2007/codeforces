#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(long long x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(long long x,char c='\n')
{
	write(x);
	putchar(c);
}
void up(int &x,int y){if (x>y) x=y;}
int mn[N],a[N],nxt[N];
void ysgs(int n)
{
	mn[1]=1;
	for (int i=2;i<=n;i++) if (!mn[i])
	for (int j=i;j<=n;j+=i) if (!mn[j]) mn[j]=i;
}
char op[N];
vector<pair<int,int>>b[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	ysgs(1e6);
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	scanf("%s",op+1);
	for (int i=1;i<=n;i++)
	{
		nxt[i]=i;
		int now=a[i];
		while (now>1)
			b[mn[now]].push_back(make_pair(op[i]=='*'?1:-1,i)),
			now/=mn[now];
	}
	for (int t=1;t<=1e6;t++)
	if (!b[t].empty())
	{
		stack<int>st;
		for (auto i:b[t])
		if (i.first>0) st.push(i.second);
		else if (!st.empty()) up(nxt[i.second],st.top()),st.pop();
		else nxt[i.second]=0;
	}
	static int st[N],top=0;
	st[0]=n+1;
	long long ans=0;
	for (int i=n;i>=1;i--)
	{
		st[++top]=i;
		while (top&&nxt[st[top]]>=i) top--;
		ans+=st[top]-i;
	}
	print(ans);
	
	return 0;
}