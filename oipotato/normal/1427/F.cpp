#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<set>
#include<map>
#include<cassert>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define hash hsh
typedef long long LL;
const int N=210;
struct data
{
	int a,b,c;
	void clear(){a=b=c=0;}
	void add(int x)
	{
		if(!a)a=x;
		else if(!b)b=x;
		else c=x;
	}
	void print(){printf("%d %d %d\n",a,b,c);}
}val[N<<1],a[N<<1];
struct STACK
{
	int top,stk[N];
	bool empty(){return !top;}
	void push(int x){stk[++top]=x;}
	int pop(){return stk[top--];}
}stk[2][2];
vector<int>g[N<<1];
bool vis[6*N],typ[N<<1];
int n,id[N<<1],cnt,top,ans[N<<1];
int main()
{
	scanf("%d",&n);
	rep(i,3*n){int x;scanf("%d",&x);vis[x]=1;}
	rep(i,6*n)
	if(top&&vis[i]==typ[top])
	{
		val[top].add(i);
		if(val[top].c)
		{
			a[id[top]]=val[top];
			top--;
			if(top)g[id[top]].pb(id[top+1]);else stk[vis[i]][!!g[id[top+1]].size()].push(id[top+1]);
		}
	}
	else
	{
		id[++top]=++cnt;
		typ[top]=vis[i];
		val[top].clear();
		val[top].add(i);
	}
	for(int i=2*n;i;i--)
	{
		ans[i]=stk[i&1][1].empty()?stk[i&1][0].pop():stk[i&1][1].pop();
		for(auto j:g[ans[i]])stk[(i&1)^1][!!g[j].size()].push(j);
	}
	rep(i,2*n)a[ans[i]].print();
    return 0;
}