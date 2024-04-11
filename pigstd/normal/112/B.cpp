#include<bits/stdc++.h>
using namespace std;

int n,x,y;

int main()
{
	cin>>n>>x>>y;
	if ((x==n/2||x==n/2+1)&&(y==n/2||y==n/2+1))
		cout<<"NO";
	else
		cout<<"YES";
	return 0;
}