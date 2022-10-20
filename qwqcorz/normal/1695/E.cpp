#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=6e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

vector<int>e[N];
int ans[N][2];
char ans1[N][2],ans2[N][2];
void dfs(int now,vector<int>&a)
{
	while (e[now].size())
	{
		int to=e[now].back();
		e[now].pop_back();
		dfs(to,a);
		a.push_back(to);
	}
}

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int cnt=0;
	for (int i=1;i<=n*2;i++)
	if (e[i].size())
	{
		vector<int>a;
		dfs(i,a);
		if (a.size()==2) return puts("-1"),0;
		int m=a.size()/2;
		for (int i=0;i<m;i++) ans[cnt+1+i][0]=a[i];
		for (int i=0;i<m;i++) ans[cnt+m-i][1]=a[m+i];
		if (m&1)
		{
			for (int i=0;i<m-1;i++) ans1[cnt+1+i][0]=i%2?'R':'L';
			for (int i=0;i<m-1;i++) ans1[cnt+1+i][1]=i%2?'R':'L';
			ans1[cnt+m][0]='U';
			ans1[cnt+m][1]='D';
			for (int i=0;i<m-1;i++) ans2[cnt+1+i+1][0]=i%2?'R':'L';
			for (int i=0;i<m-1;i++) ans2[cnt+1+i+1][1]=i%2?'R':'L';
			ans2[cnt+1][0]='U';
			ans2[cnt+1][1]='D';
		}
		else
		{
			for (int i=0;i<m;i++) ans1[cnt+1+i][0]=i%2?'R':'L';
			for (int i=0;i<m;i++) ans1[cnt+1+i][1]=i%2?'R':'L';
			for (int i=1;i<m-1;i++) ans2[cnt+1+i][0]=i%2?'L':'R';
			for (int i=1;i<m-1;i++) ans2[cnt+1+i][1]=i%2?'L':'R';
			ans2[cnt+1][0]='U';
			ans2[cnt+1][1]='D';
			ans2[cnt+m][0]='U';
			ans2[cnt+m][1]='D';
		}
		cnt+=m;
	}
	print(2,' '),print(n);
	puts("");
	for (int i=1;i<=n;i++) print(ans[i][0]," \n"[i==n]);
	for (int i=1;i<=n;i++) print(ans[i][1]," \n"[i==n]);
	puts("");
	for (int i=1;i<=n;i++) putchar(ans1[i][0]);;puts("");
	for (int i=1;i<=n;i++) putchar(ans1[i][1]);;puts("");
	puts("");
	for (int i=1;i<=n;i++) putchar(ans2[i][0]);;puts("");
	for (int i=1;i<=n;i++) putchar(ans2[i][1]);;puts("");
	
	return 0;
}