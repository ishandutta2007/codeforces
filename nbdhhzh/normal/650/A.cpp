#include<bits/stdc++.h>
using namespace std;
map<int,int>mp1,mp2;
map<pair<int,int>,int>mp;
int n,i,x,y;
long long ans;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		ans+=mp1[x]++;
		ans+=mp2[y]++;
		ans-=mp[make_pair(x,y)]++;
	}
	printf("%I64d\n",ans);
}