#include<iostream>
using namespace std;
int main()
{
	long long ans,n,m,k,n1,m1;
	cin>>n>>m>>k;
	n--;
	m--;
	n1=n-4*(k-1);
	m1=m-4*(k-1);
	ans=(n+n1+m+m1)*k;
	cout<<ans;
}