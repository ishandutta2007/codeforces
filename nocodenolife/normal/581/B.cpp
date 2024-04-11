#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005],x[100005];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	x[n-1]=a[n-1];
	for(int i=n-1;i>=0;i--)
	x[i]=max(a[i],x[i+1]);
	for(int i=0;i<n-1;i++)
	{
		if(a[i]>x[i+1])
		cout<<0<<" ";
		else 
		cout<<x[i+1]-a[i]+1<<" ";
	}
	cout<<"0\n";
	return 0;
}