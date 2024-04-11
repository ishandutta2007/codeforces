#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct Node
{
	int next[7];
	int cnt,p;
}node[5200000];
int top;
char s[60];
int ans,n,m,qq;
int newnode()
{
	top++;
	for(int i=1;i<=5;i++)node[top].next[i]=0;
	node[top].cnt=node[top].p=0;
	return top;
}
void add(char *st)
{
	int len=strlen(st),x=1;
	for(int i=0;i<len;i++)
	{
		int ind=st[i]-'a'+1;
		if (!node[x].next[ind])
			node[x].next[ind]=newnode();
		x=node[x].next[ind];
	}
	node[x].cnt++;
}
void dfs(int now,char* s)
{
	if (now==0)return;
	if (! (*s))
	{
		if (node[now].p<qq){ ans+=node[now].cnt; node[now].p=qq; }
		return;
	}
	if (*s=='?')
	{
		dfs(now,s+1);
		for(int i=1;i<=5;i++)dfs(node[now].next[i],s+1);
	}
	else dfs(node[now].next[*s-'a'+1],s+1);
}
int main()
{
	cin>>n>>m;
	top=-1;
	newnode();
	newnode();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		add(s);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%s",s);
		ans=0;
		qq=i;
		dfs(1,s);
		printf("%d\n",ans);
	}
}