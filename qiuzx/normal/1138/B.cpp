#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define INF 10000000000
#define N 110
using namespace std;
ll n;
vector<ll> v[4];
string st1,st2;
int main(){
	ll i,j,a,b,c,d,sa,sb,sc,sd,sum;
	cin>>n>>st1>>st2;
	for(i=0;i<n;i++)
	{
		if(st1[i]=='0'&&st2[i]=='0')
		{
			v[0].push_back(i);
		}
		else if(st1[i]=='0'&&st2[i]=='1')
		{
			v[1].push_back(i);
		}
		else if(st1[i]=='1'&&st2[i]=='0')
		{
			v[2].push_back(i);
		}
		else
		{
			v[3].push_back(i);
		}
	}
	for(a=0;a<=v[0].size();a++)
	{
		for(b=0;b<=v[1].size();b++)
		{
			sum=(n/2)-a-b;
			sa=v[0].size()-a;
			sb=v[1].size()-b;
			if(sum<0)
			{
				continue;
			}
			sd=sum-sb;
			d=v[3].size()-sd;
			c=sum-d;
			sc=v[2].size()-c;
			if(c>=0&&d>=0&&sc>=0&&sd>=0)
			{
				for(i=0;i<a;i++)
				{
					cout<<v[0][i]+1<<" ";
				}
				for(i=0;i<b;i++)
				{
					cout<<v[1][i]+1<<" ";
				}
				for(i=0;i<c;i++)
				{
					cout<<v[2][i]+1<<" ";
				}
				for(i=0;i<d;i++)
				{
					cout<<v[3][i]+1<<" ";
				}
				puts("");
				return 0;
			}
		}
	}
	puts("-1");
	return 0;
}