#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int d[110];
int ab(int t)
{
	return max(t,-t);
}
int main()
{
	memset(d,0,sizeof(d));
	int ans=0;
	int m,n,t1,t2,t3,t4;
	cin>>m>>n;
	for(t1=1;t1<=n;t1++)
	{
		scanf("%d%d%d",&t2,&t3,&t4);
		ans+=t4;
		if(d[t2]<0)
		{
			ans-=min(ab(d[t2]),t4);
		}
		d[t2]+=t4;
		if(d[t3]>0)
		{
			ans-=min(d[t3],t4);
		}
		d[t3]-=t4;
	}
	cout<<ans;
}