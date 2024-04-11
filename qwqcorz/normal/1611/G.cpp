#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int n,m;
char s[N];
vector<int>a[N];
void dfs(int x,int y)
{
	if (x>n||y>m) return;
	if (!a[x+y].empty()&&a[x+y].back()>x||y==m) dfs(x+1,y-1);
										   else dfs(x+1,y+1);
	if (!a[x+y].empty()&&a[x+y].back()==x) a[x+y].pop_back();
}
void GreenDay()
{
	n=read(),m=read();
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for (int j=1;j<=m;j++) if (s[j]=='1') a[i+j].push_back(i);
	}
	for (int i=1;i<=n+m;i++) if (!a[i].empty()) dfs(a[i][0],i-a[i][0]),ans++;
	print(ans);
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}