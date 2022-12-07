#include<bits/stdc++.h>
using namespace std;
char s[10010];
int num[200010],num2[10010],k[10010];
int main()
{
	int n,mod;
	cin>>n>>mod;
	if(n>mod)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>num[i];
	long long ans=1;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(num[i]>num[j])
				ans=ans*(num[i]-num[j])%mod;
			else
				ans=ans*(num[j]-num[i])%mod;
	cout<<ans;
}