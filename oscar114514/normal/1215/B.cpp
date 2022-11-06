#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int pos=0,neg=0;
	long long ans1=0,ans2=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>0)pos++;
		else swap(pos,neg),neg++;
		ans1+=pos;ans2+=neg;
	}
	cout<<ans2<<' '<<ans1<<endl;
	return 0;
}