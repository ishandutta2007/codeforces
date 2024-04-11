#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

ll n,a[N],k,ans;

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		while(k*2<a[i])
		{
			k<<=1;
			ans++;
		}
		k=max(a[i],k);
	}
	cout<<ans;
}