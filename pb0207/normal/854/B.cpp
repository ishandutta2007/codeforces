#include<iostream>
using namespace std;

int n,k;

int main()
{
	cin>>n>>k;
	if(n==k||k==0)
		cout<<0<<" "<<0;
	else
		cout<<1<<" "<<min(n-k,k*2);
}