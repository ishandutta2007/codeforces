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
long long num[300010];
stack<int> s[100];
vector<long long> v;
int hb[300010];
int main()
{
	int n;
	cin>>n;
	long long x=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&num[i]);
		x^=num[i];
		for(int j=60;j>=0;j--)
		{
			if((num[i]&(1ll<<j)))
			{
				hb[i]=j;
				break;
			}
		}
		s[hb[i]].push(i);
	}
	for(int i=1;i<=n;i++)
	{
		int can=0;
		for(int j=0;j<=60;j++)
			if(((x&(1ll<<j))!=0)&&(!s[j].empty()))
			{
				can=s[j].top();
				s[j].pop();
				break;
			}
		if(can==0)
		{
			cout<<"No";
			return 0;
		}
		v.push_back(num[can]);
		x^=num[can];
	}
	reverse(v.begin(),v.end());
	cout<<"Yes"<<endl;
	for(int i=0;i<n;i++)
		cout<<v[i]<<' ';
		
	

	
}