#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
	cin>>n;
	if (n%2==1)
		cout<<n/2<<' '<<n-n/2;
	else if (n%4==2)
		cout<<n/2-2<<' '<<n/2+2;
	else
		cout<<n/2-1<<' '<<n/2+1;
	return 0;
}