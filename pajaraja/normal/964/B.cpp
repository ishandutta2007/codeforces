#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b,c,t,g;
	long long sk=0;
	cin>>n>>a>>b>>c>>t;
	for(int i=0;i<n;i++)
	{
		cin>>g;
		sk+=(fmax(a,a-(t-g)*(b-c)));
	}
	cout<<sk;
}