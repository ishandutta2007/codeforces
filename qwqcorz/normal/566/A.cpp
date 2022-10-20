#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=8e5+5;

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
int f(int x)
{
	if (x>0) return 1;
	if (x<0) return -1;
	return 0;
}
struct node
{
	int son[26],deep;
	vector<int>s;
}t[M];
int ans=0,p[N],cnt=0;
char a[M];
void insert(char *a,int id)
{
	int n=strlen(a+1),now=0;
	#define to t[now].son[a[i]-'a']
	for (int i=1;i<=n;i++)
	{
		if (!to) t[to=++cnt].deep=t[now].deep+1;
		now=to;
	}
	t[now].s.push_back(id);
	#undef to
}
vector<int>dfs(int now)
{
	vector<int>ret(0);
	for (int j:t[now].s)
	if (!ret.empty()&&f(j)!=f(ret.back()))
	{
		ans+=t[now].deep;
		int x=j,y=ret.back();
		if (x<y) swap(x,y);
		p[x]=-y;
		ret.pop_back();
	}
	else ret.push_back(j);
	#define to t[now].son[i]
	for (int i=0;i<26;i++)
	if (to)
	{
		vector<int>tmp=dfs(to);
		for (int j:tmp)
		if (!ret.empty()&&f(j)!=f(ret.back()))
		{
			ans+=t[now].deep;
			int x=j,y=ret.back();
			if (x<y) swap(x,y);
			p[x]=-y;
			ret.pop_back();
		}
		else ret.push_back(j);
	}
	#undef to
	return ret;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read();
	for (int i=1;i<=n;i++)
	{
		scanf("%s",a+1);
		insert(a,i);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%s",a+1);
		insert(a,-i);
	}
	dfs(0);
	print(ans);
	for (int i=1;i<=n;i++) print(i,' '),print(p[i]);
	
	return 0;
}