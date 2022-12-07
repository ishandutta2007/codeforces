#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n%2==0)
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	for(int i=1;i<=2*n;i+=2)
		if(i%4==3)
			cout<<i+1<<' ';
		else
			cout<<i<<' ';
	for(int i=2;i<=2*n;i+=2)
		if(i%4==0)
			cout<<i-1<<' ';
		else
			cout<<i<<' ';
}