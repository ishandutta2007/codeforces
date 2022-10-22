// Author: Little09
// Problem: CF1693C Keshi in Search of AmShZ
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1693C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
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
int a[N];
vector<int>t[N];
int d[N],f[N];
bool used[N];
struct point
{
	int x,dis;
	bool operator < (point const &o) const
	{
		return dis>o.dis;
	}
};
priority_queue<point>q;
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
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		t[y].push_back(x);
		d[x]++;
	}
	point l;
	l.x=n,l.dis=0;
	q.push(l);
	memset(f,20,sizeof(f));
	f[n]=0;
	while (!q.empty())
	{
		point u=q.top();
		q.pop();
		if (used[u.x]) continue;
		used[u.x]=1;
		for (int i:t[u.x])
		{
			if (f[u.x]+d[i]<f[i])
			{
				f[i]=f[u.x]+d[i];
				q.push((point){i,f[i]});
			}
			d[i]--;
		}
	}
	cout << f[1];
	return 0;
}