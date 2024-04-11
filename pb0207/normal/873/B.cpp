#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

const int N=2e5+1e3+7;

int n,a[N],ans;

map<int,int>b;
map<int,bool>vis;

char s[N];

int main()
{
	cin>>n;
	scanf("%s",s+1);
	vis[0]++;
	for(int i=1;i<=n;i++)
	{
		a[s[i]-'0']++;
		if(vis[a[0]-a[1]]) 
			ans=max(ans,i-b[a[0]-a[1]]);
		else 
		{
			vis[a[0]-a[1]]=1;
			b[a[0]-a[1]]=i;
		}
	}
	cout<<ans;
}