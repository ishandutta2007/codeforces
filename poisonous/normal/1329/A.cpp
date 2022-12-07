#include<bits/stdc++.h>
using namespace std;
pair<int,int> num[100010];
int ou[100010];
int main()
{
	int n,m;
	cin>>n>>m;
	long long k=0;
	int nn=n;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&num[i].first);
		num[i].second=i;
		k+=num[i].first;
	}
	if(k<n)
	{
		cout<<-1<<endl;
		return 0;
	}
	if((m-1)+num[m].first>n)
	{
		cout<<-1<<endl;
		return 0;
	}
	int x=n+1,p=1;
	for(int i=1;i<=m;i++)
		if(k-num[i].first<=n-1)
		{
			for(int j=m;j>i;j--)
			{
				x-=num[j].first;
				ou[num[j].second]=x;
			}
			ou[num[i].second]=p;
			break;
		}
		else
		{
			ou[num[i].second]=p;
			n--;
			p++;
			k-=num[i].first;
		}
	int can=1;
	for(int i=1;i<=m;i++)
		if(ou[i]+num[i].first-1>nn)
			can=0;
	if(can==0)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=m;i++)
		cout<<ou[i]<<endl;
				
}