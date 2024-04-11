#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const ll lim=(1e18);

const int N=1e5+1e3+7;

ll n,f[N];

int main()
{
	cin>>n;
	f[0]=1;
	f[1]=2;
	for(int i=2;;i++)
	{
		f[i]=f[i-1]+f[i-2];
		if(f[i]>n)
		{
			cout<<i-1;
			exit(0);
		}
	}
}