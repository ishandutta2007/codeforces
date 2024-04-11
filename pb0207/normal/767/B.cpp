#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct node{
	long long st,ed;
}gue[100001];

long long ts,tf,t,tim=1e12+1,ans;

int n;

int main()
{
	cin>>ts>>tf>>t;
	cin>>n;
	gue[0].ed=ts-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&gue[i].st);
		gue[i].ed=max(gue[i-1].ed+t,gue[i].st+t-1);
	}
	for(int i=1;i<=n;i++)
	{
		if(gue[i].st-gue[i-1].ed>1&&gue[i].st-1<=tf-t)
		{
			cout<<gue[i].st-1;
			return 0;
		}
		if(gue[i].st-gue[i-1].st>1&&gue[i].st-1<=tf-t)
			if(gue[i-1].ed-gue[i].st+1<tim)
				ans=gue[i].st-1,tim=gue[i-1].ed-gue[i].st+1;
	}
	if(gue[n].ed<=tf-t)
	{
		cout<<gue[n].ed+1;
		return 0;
	}
	if(gue[1].st>tf-t)
	{
		cout<<ts;
		return 0;
	}
	if(tim<ts-gue[1].st+1&&ans)
		cout<<ans;
	else
		cout<<gue[1].st-1;
}