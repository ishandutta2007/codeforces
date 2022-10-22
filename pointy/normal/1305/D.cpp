// Author: Little09
// Problem: CF1305D Kuroni and the Celebration
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1305D
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int d[N];
vector<int>t[N];
queue<int>q;
bool used[N];

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}

int main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		t[x].push_back(y),t[y].push_back(x);
		d[x]++,d[y]++;
	}
	for (int i=1;i<=n;i++)
	{
		if (d[i]==1) q.push(i); 
	}
	for (int i=1;i<=n/2;i++)
	{
		int u=q.front();
		q.pop();
		int v=q.front();
		q.pop();
		used[u]=1,used[v]=1;
		printf("? %d %d\n",u,v);
		fflush(stdout);
		int x=read();
		if (x==u||x==v)
		{
			printf("! %d\n",x);
			return 0;
		}
		for (int j:t[u])
		{
			if (used[j]==0)
			{
				d[j]--;
				if (d[j]==1) q.push(j);
			}
		}
		for (int j:t[v])
		{
			if (used[j]==0)
			{
				d[j]--;
				if (d[j]==1) q.push(j);
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (used[i]==0)
		{
			printf("! %d\n",i);
			return 0;
		}
	}
	return 0;
}