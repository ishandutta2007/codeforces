#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,ws=1,maxx,maxi,a,b;
	long long k;
	cin>>n>>k;
	cin>>a>>b;
	ws=1;
	if(a>b) maxi=1;
	else maxi=2;
	maxx=fmax(a,b);
	for(int i=3;i<=n;i++)
	{
		int t;
		cin>>t;
		if(t>maxx)
		{
			maxi=i;
			maxx=t;
			ws=0;
		}
		ws++;
		if(ws>=k)
		{
			cout<<maxx;
			return 0;
		}
	}
	cout<<maxx;
}