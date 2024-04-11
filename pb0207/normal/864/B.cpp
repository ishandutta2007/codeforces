#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1e5+1e3+7;

char s[N*2+1];

int n,cnt,vis[201];

int main()
{
	cin>>n;
	scanf("%s",s);
	n=strlen(s);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			if(!vis[s[i]])
			{
				cnt++;
				vis[s[i]]=1;
			}
		}
		else
		{
			ans=max(ans,cnt),cnt=0;
			memset(vis,0,sizeof(vis));
		}
	}
	ans=max(ans,cnt);
	cout<<ans;
}