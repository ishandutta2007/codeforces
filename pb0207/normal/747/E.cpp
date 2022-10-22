#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int N=1e6+1e3+7;

vector<pair<int,int> >ans[N];

char s[N];

int cur,n,mx;

void dfs(int now)
{
	int l,r;
	l=cur;
	while(s[cur]!=','&&cur<=n)
		cur++;
	r=cur-1;
	ans[now+1].push_back(make_pair(l,r));
	mx=max(mx,now+1);
	cur++;
	int x=0;
	while(s[cur]!=','&&cur<=n)
		x=x*10+s[cur]-'0',cur++;
	cur++;
	for(int i=1;i<=x;i++)
		dfs(now+1);
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	cur=1;
	while(cur<=n)
		dfs(0);
	cout<<mx<<endl;
	for(int i=1;i<=mx;i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			for(int k=ans[i][j].first;k<=ans[i][j].second;k++)
				cout<<s[k];
			cout<<" ";
		}
		cout<<endl;
	}
}