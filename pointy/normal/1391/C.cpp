#include<bits/stdc++.h>
using namespace std;
int n;
long long x=1,y=1,mod=1e9+7;
int main()
{
    cin >> n;
    for (int i=1;i<=n;i++) 
    {
    	x=(x*i)%mod;
	}
	for (int i=1;i<n;i++)
	{
		y=(y*2)%mod;
	}
	long long z=x-y;
	z%=mod;
	z+=mod;
	z%=mod;
	cout << z;
    return 0;
}