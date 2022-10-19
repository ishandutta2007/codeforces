//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,m,sum=0;
string cur;
vector<pair<ll,ll> > v;
int main(){
	ll i,j,x;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cout<<"? ";
		for(j=0;j<m;j++)
		{
			putchar('0'+(i==j));
		}
		puts("");
		fflush(stdout);
		cin>>x;
		v.push_back(make_pair(x,i));
	}
	sort(v.begin(),v.end());
	cur="";
	for(i=0;i<m;i++)
	{
		cur+='0';
	}
	for(i=0;i<v.size();i++)
	{
		cur[v[i].S]='1';
		cout<<"? "<<cur<<endl;
		fflush(stdout);
		cin>>x;
		if(x==sum+v[i].F)
		{
			sum=x;
		}
		else
		{
			cur[v[i].S]='0';
		}
	}
	cout<<"! "<<sum<<endl;
	return 0;
}