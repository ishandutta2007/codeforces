#include<iostream>
using namespace std;

int n;

int main()
{
	cin>>n;
	cout<<n+n/2<<endl;
	for(int i=2;i<=n;i+=2)
		cout<<i<<" ";
	for(int i=1;i<=n;i+=2)
		cout<<i<<" ";
	for(int i=2;i<=n;i+=2)
		cout<<i<<" ";	
}