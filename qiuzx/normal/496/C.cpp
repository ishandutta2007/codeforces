#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define INF 10000000000
#define N 110
using namespace std;
ll n,m,ans=0;
bool vis[N];
string s[N];
int main(){
	ll i,j,lst,chs;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(i=0;i<m;i++)
	{
		for(j=1;j<n;j++)
		{
			if(vis[j])
			{
				continue;
			}
			if(s[j][i]<s[j-1][i])
			{
				j=-1;
				break;
			}
		}
		if(j==-1)
		{
			ans++;
		}
		else
		{
			for(j=1;j<n;j++)
			{
				if(s[j][i]>s[j-1][i])
				{
					vis[j]=true;
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}