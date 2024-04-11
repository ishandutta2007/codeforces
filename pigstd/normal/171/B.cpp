#include<bits/stdc++.h>
using namespace std;

int ans=1,n;

int main()
{
	cin>>n;
	ans=(2*n-1)*(2*n-1)+4*(n-1)*(n)/2;
	cout<<ans;
	return 0;
}