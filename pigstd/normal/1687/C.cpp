#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
	int num=0,f=1;char ch=getchar();
	while(!(ch=='-'||(ch<='9'&&ch>='0')))ch=getchar();
	if (ch=='-')f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')num=num*10+ch-'0',ch=getchar();
	return num*f;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=2e5+10;
int n,m,a[M],s[M],l[M],r[M],c[M]; 
vector<int>e[M];
set<int>t;

void solve()
{
	n=read(),m=read();e[0].clear();t.clear();
	for (int i=1;i<=n;i++)a[i]=read(),e[i].clear();
	for (int i=1;i<=n;i++)a[i]-=read(),s[i]=s[i-1]+a[i];
	for (int i=1;i<=n;i++)
		if (s[i]!=0)t.insert(i);
	queue<int>q;
	for (int i=1;i<=m;i++)
	{
		l[i]=read()-1,r[i]=read(),c[i]=(s[l[i]]==0)+(s[r[i]]==0);
		e[l[i]].pb(i),e[r[i]].pb(i);
		if (c[i]==2)q.push(i);
	}
	while(!q.empty())
	{
		int u=q.front();q.pop();
		auto p=t.upper_bound(l[u]);
		while(p!=t.end()&&(*p)<=r[u])
		{
			int x=(*p);t.erase(x);p=t.upper_bound(l[u]);
			for (auto y:e[x])
			{
				c[y]++;
				if (c[y]==2)q.push(y);
			}
		}
	}
	if (t.empty())YES
	else NO
}

signed main()
{
	WT solve(); 
	return 0;
}