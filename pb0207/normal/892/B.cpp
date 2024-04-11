#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=1e6+1e3+7;

int n,a[N],ans;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[max(i-x,1)]++;
		a[i]--;
	}
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	for(int i=1;i<=n;i++)
		if(!a[i])
			ans++;
	cout<<ans;
}