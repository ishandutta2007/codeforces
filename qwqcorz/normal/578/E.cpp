#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char s[N];
int a[N],cnt=0;
vector<int>p[N];

signed main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for (int i=1;i<=n;i++) a[i]=s[i]=='R';
	vector<int>id[2];
	for (int i=1;i<=n;i++)
	if (id[!a[i]].empty()) p[++cnt]=vector<int>({i}),id[a[i]].push_back(cnt);
	else
	{
		int x=id[!a[i]].back();
		id[!a[i]].pop_back();
		p[x].push_back(i);
		id[a[i]].push_back(x);
	}
	print(cnt-1);
	deque<int>tmp;
	vector<int>k[2][2];
//	for (int i=1;i<=cnt;i++,puts(""))
//	for (int j:p[i]) print(j,' ');
//	for (int i=1;i<=cnt;i++) print(a[p[i][0]],'|'),print(a[p[i].back()]);
	int l=-1,r=-1;
	for (int i=1;i<=cnt;i++) l=a[p[i][0]],r=!a[p[i][0]],k[a[p[i][0]]][a[p[i].back()]].push_back(i);
	while (1)
	{
		bool flag=0;
		for (int i=0;i<=1;i++)
		if (!k[!r][i].empty())
		{
			tmp.push_back(k[!r][i].back());
			k[!r][i].pop_back();
			r=i,flag=1;
		}
		for (int i=0;i<=1;i++)
		if (!k[i][!l].empty())
		{
			tmp.push_front(k[i][!l].back());
			k[i][!l].pop_back();
			l=i,flag=1;
		}
		if (!flag) break;
	}
	for (int i=0;i<=1;i++)
	while (k[i][!i].size()>1)
	{
		for (int j:p[k[i][!i].back()])
		p[k[i][!i][0]].push_back(j);
		k[i][!i].pop_back();
	}
	vector<int>ans;
	for (int i:tmp)
	for (int j:p[i]) ans.push_back(j);
//	for (int i:ans) print(i,',');;puts("");
//	print(l,' '),print(r);
	for (int i=0;i<=1;i++)
	for (int j=0;j<=1;j++)
	if (!k[i][j].empty())
	{
		int x=k[i][j][0];
		if (p[x].back()<ans.back()) swap(p[x],ans);
		ans.push_back(p[x].back());
		p[x].pop_back();
		for (int t:p[x]) ans.push_back(t);
	}
	for (int i:ans) print(i,' ');
	
	return 0;
}
/*
LLLLRRRRRRLLLLLLRRRRR
LRRLLR
RRLLRLR
*/