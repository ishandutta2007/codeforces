#include<bits/stdc++.h>
using namespace std;

const int Mod=1e6+3;
int n,ans=1;

int main()
{
	cin>>n;
	for (int i=1;i<=n-1;i++)
		ans*=3,ans%=Mod;
	cout<<ans;
	return 0;
}