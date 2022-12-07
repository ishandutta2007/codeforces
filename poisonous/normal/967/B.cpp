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
pair<int,int> num[100010];
int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	long long sum=0;
	long long n1=0;
	for(int i=1;i<=n;i++)
	{
		int t1;
		scanf("%d",&t1);
		if(i==1)
			n1=t1;
		num[i].second=i;
		sum+=t1;
		num[i].first=t1;
	}
	sort(num+1,num+n+1);
	int t=0;
	for(int i=n;i>=1;i--)
	{
		if(sum*b<=n1*a)
		{
			cout<<t<<endl;
			return 0;
		}
		if(num[i].second!=1)
		{
			t++;
			sum-=num[i].first;
		}
	}
	cout<<n-1<<endl;
}