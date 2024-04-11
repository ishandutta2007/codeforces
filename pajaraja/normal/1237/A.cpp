#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
	int n; cin>>n; int d=-1;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0) cout<<a[i]/2<<endl;
		else {cout<<(a[i]+d)/2<<endl; d*=-1;}
	}
}