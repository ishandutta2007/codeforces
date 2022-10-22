#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int inf=1e18;
const int M=150010;
int n1,n2,n3,n4,f1[M],f2[M],f3[M],f4[M];
vector<int>v1[M],v2[M],v3[M];
multiset<int>s;

signed main()
{
	n1=read(),n2=read(),n3=read(),n4=read();
	for (int i=1;i<=n1;i++)f1[i]=read(),s.insert(f1[i]);
	for (int i=1;i<=n2;i++)f2[i]=read();
	for (int i=1;i<=n3;i++)f3[i]=read();
	for (int i=1;i<=n4;i++)f4[i]=read();
	int m1=read();
	for (int i=1;i<=m1;i++)
	{
		int u=read(),v=read();
		v1[v].pb(u);
	}
	for (int i=1;i<=n2;i++)
	{
		int tmp=f2[i];f2[i]=inf;
		for (auto to:v1[i])s.erase(s.find(f1[to]));
		if (s.begin()!=s.end())f2[i]=tmp+*s.begin();
		for (auto to:v1[i])s.insert(f1[to]);
	}s.clear();
	for (int i=1;i<=n2;i++)s.insert(f2[i]);
	int m2=read();
	for (int i=1;i<=m2;i++)
	{
		int u=read(),v=read();
		v2[v].pb(u);
	}
	for (int i=1;i<=n3;i++)
	{
		int tmp=f3[i];f3[i]=inf;
		for (auto to:v2[i])s.erase(s.find(f2[to]));
		if (s.begin()!=s.end())f3[i]=tmp+*s.begin();
		for (auto to:v2[i])s.insert(f2[to]);
	}s.clear();
	for (int i=1;i<=n3;i++)s.insert(f3[i]);
	int m3=read();
	for (int i=1;i<=m3;i++)
	{
		int u=read(),v=read();
		v3[v].pb(u);
	}
	for (int i=1;i<=n4;i++)
	{
		int tmp=f4[i];f4[i]=inf;
		for (auto to:v3[i])s.erase(s.find(f3[to]));
		if (s.begin()!=s.end())f4[i]=tmp+*s.begin();
		for (auto to:v3[i])s.insert(f3[to]);
	}int res=inf;
	for (int i=1;i<=n4;i++)res=min(res,f4[i]);
	if (res==inf)puts("-1");
	else cout<<res<<endl;
	return 0;
}