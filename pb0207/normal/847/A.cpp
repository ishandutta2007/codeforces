#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

int n,l[101],r[101],vis[101],cnt;

vector<int>ans[101];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>l[i]>>r[i];
	for(int i=1;i<=n;i++)
		l[r[i]]=i,r[l[i]]=i;
	for(int i=1;i<=n;i++)
		if(!vis[i]&&l[i]==0)
		{
			++cnt;
			for(int j=i;j;j=r[j])
				ans[cnt].push_back(j),vis[j]=true;
		}
	if(cnt>1)
	{
		l[ans[1][0]]=0,r[ans[1][ans[1].size()-1]]=ans[2][0];
		l[ans[cnt][0]]=ans[cnt-1][ans[cnt-1].size()-1],r[ans[cnt][ans[cnt].size()-1]]=0;
	}
	for(int i=2;i<=cnt-1;i++)
		l[ans[i][0]]=ans[i-1][ans[i-1].size()-1],r[ans[i][ans[i].size()-1]]=ans[i+1][0];
	for(int i=1;i<=n;i++)
		cout<<l[i]<<" "<<r[i]<<endl;
}