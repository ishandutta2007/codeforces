#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
pair<int,int> num[500010];
int main()
{
	int n,p,q;
	cin>>n>>p>>q;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i].first);
		num[i].second=i;
	}
	sort(num+1,num+n+1);
	int np=0,nq=0;
	for(int i=1;i<n;i++)
	{
		if(num[n+1-i].first>=(p/i+(p%i!=0)))
		{
			np=i;
			break;
		}
	}
	for(int i=1;i<n;i++)
	{
		if(num[n+1-i].first>=(q/i+(q%i!=0)))
		{
			nq=i;
			break;
		}
	}
	if(np==0||nq==0)
	{
		cout<<"No";
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int x=(p/i+(p%i!=0));
		int l=0,r=n;
		while(l!=r)
		{
			int mid=(l+r+1)>>1;
			if(mid==0||num[n+1-mid].first>=x)
				l=mid;
			else
				r=mid-1;
		}
		if(l>=i+nq)
		{
			cout<<"Yes\n";
			cout<<i<<' '<<nq<<endl;
			for(int j=n+1-i-nq;j<=n-nq;j++)
				cout<<num[j].second<<' ';
			cout<<endl;
			for(int j=n+1-nq;j<=n;j++)
				cout<<num[j].second<<' ';
			return 0;
		}
	}
	for(int i=1;i<n;i++)
	{
		int x=(q/i+(q%i!=0));
		int l=0,r=n;
		while(l!=r)
		{
			int mid=(l+r+1)>>1;
			if(mid==0||num[n+1-mid].first>=x)
				l=mid;
			else
				r=mid-1;
		}
		if(l>=i+np)
		{
			cout<<"Yes\n";
			cout<<np<<' '<<i<<endl;
			for(int j=n+1-np;j<=n;j++)
				cout<<num[j].second<<' ';
			cout<<endl;
			for(int j=n+1-np-i;j<=n-np;j++)
				cout<<num[j].second<<' ';
			return 0;
		}
	}
	cout<<"No";
}