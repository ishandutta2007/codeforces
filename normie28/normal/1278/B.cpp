#include <bits/stdc++.h>
using namespace std;

long long t,k,n,m,i,j,res=0,cnt[26];
long long a,b;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for (k=1;k<=t;k++)
	{
		res=0; i=0;
		cin>>a>>b;
		while (true)
		{
			if ((!((res+a+b)%2))and(res+a+b>=a*2)and(res+a+b>=b*2)) break;
			i++; res+=i;
		}
		cout<<i<<endl;
	}
}