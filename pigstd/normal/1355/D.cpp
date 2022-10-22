#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,s;
	cin>>n>>s;
	if (s<2*n)
		{cout<<"NO";return 0;}
	cout<<"YES"<<endl;
	for (int i=1;i<n;i++)
		cout<<1<<' ',s--;
	cout<<s<<endl;
	cout<<s-1<<endl;
	return 0;
}