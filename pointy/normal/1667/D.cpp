#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int>t[N];
int n,fa[N],d[N];
bool flag;
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
void dfs(int x,int f)
{
	fa[x]=f;
	int w[2]={0,0};
	for (int i:t[x])
	{
		if (i==fa[x]) continue;
		dfs(i,x);
		w[d[i]]++;
	}
	if (x!=1)
	{
		if (w[0]>=w[1]) d[x]=1;
		else d[x]=0;
		w[d[x]]++;
	}
	if (w[0]>w[1]||w[1]>w[0]+1) flag=0;
}
void build(int x)
{
	vector<int>w[2];
	w[0].clear(),w[1].clear();
	if (x!=1) w[d[x]].push_back(x);
	for (int i:t[x])
	{
		if (i==fa[x]) continue;
		w[d[i]].push_back(i);
	}
	int p=(w[0].size()+w[1].size())%2;
	while (w[0].size()||w[1].size())
	{
		int u=w[p].back();
		w[p].pop_back();
		if (u==x) printf("%d %d\n",x,fa[x]);
		else build(u);
		p^=1;
	}
}
void work()
{
	n=read();
	for (int i=0;i<=n;i++) t[i].clear();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		t[x].push_back(y),t[y].push_back(x);
	}
	flag=1;
	dfs(1,0);
	if (flag==0)
	{
		printf("NO\n");
		return;
	}
	printf("YES\n");
	build(1);
}
int main()
{
	// freopen("gorgon.in","r",stdin);
	// freopen("gorgon.out","w",stdout);
	int T=read();
	while (T--) work();
	return 0;
}