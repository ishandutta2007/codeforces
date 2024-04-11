#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

typedef long long ll;

ll n,k;

vector<ll>d;

int main()
{
	cin>>n>>k;
	for(ll i=1ll;i*i<=n;i++)
		if(n%i==0)
			d.push_back(i);
	ll sn=sqrt(n);
	ll tag=0;
	if(sn*sn==n)
		tag=1;
	if(d.size()*2-tag<k)
	{
		cout<<"-1";
		exit(0);
	}
	if(d.size()>=k)
		cout<<d[k-1];
	else
		cout<<n/d[d.size()-(k-d.size())-tag];
}