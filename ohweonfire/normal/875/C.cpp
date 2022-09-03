// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

vector<int> g[100111];
int getid(int x)
{
	return x;
}
bool inst[100111],used[100111],ok;
int mn[100111],cap[100111],q[100111];
void dfs(int x)
{
	if(!ok)return;
	inst[x]=used[x]=1;
	for(int i=0;i<(int)g[x].size();i++)
		if(!used[g[x][i]])dfs(g[x][i]);
		else if(inst[g[x][i]])ok=0;
	inst[x]=0;
}

int n,m,l[100111],p[100111];
vector<int> w[100111];
int main()
{
	get2(n,m);
	for(int i=0;i<n;i++)
	{
		get1(l[i]);
		int x;for(int j=0;j<l[i];j++){get1(x);w[i].pb(x);}
	}
	for(int i=1;i<n;i++)
	{
		int len=0;
		while(len<l[i]&&len<l[i-1]&&w[i][len]==w[i-1][len])len++;
		if(len==l[i-1]||len==l[i])
		{
			if(l[i-1]>l[i])
			{
				puts("No");
				return 0;
			}
			continue;
		}
		p[i]=len;
		int idx=getid(w[i][len]),idy=getid(w[i-1][len]);
		g[idx].pb(idy);
		if(mn[idy]==0||mn[idy]<w[i][len])mn[idy]=w[i][len];
	}
	
	ok=1;int rear=0;
	for(int i=1;i<=m;i++)
	{
		if(!used[i])dfs(i);
		if(!ok)
		{
			puts("No");
			return 0;
		}
		if(mn[i]&&mn[i]<i){cap[i]=1;q[rear++]=i;}
	}
	for(int _=0,x;_<rear;_++)
	{
		x=q[_];
		for(int i=0;i<(int)g[x].size();i++)
		{
			if(!cap[g[x][i]])
			{
				cap[g[x][i]]=1;
				q[rear++]=g[x][i];
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		int idx=getid(w[i][p[i]]),idy=getid(w[i-1][p[i]]);
		if(cap[idx]==cap[idy]&&idx<idy)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");printendl(rear);for(int i=0;i<rear;i++)printf("%d ",q[i]);
	return 0;
}