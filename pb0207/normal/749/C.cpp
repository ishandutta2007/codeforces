#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
ll n,a,b;
char s[222222];
set<ll>x,y;
int main()
{
	cin>>n;
	scanf("%s",s);
	for(ll i=0;i<n;i++)
		if(s[i]=='D')
			x.insert(i+1);
		else
			y.insert(i+1);
	for(;!x.empty()&&!y.empty();)
	{
		a=*x.begin();
		b=*y.begin();
		x.erase(x.begin());
		y.erase(y.begin());
		if(a<b)
			x.insert(a+n);
		else
			y.insert(b+n);
	}
	if(!x.empty())
		cout<<"D";
	else
		cout<<"R";
}