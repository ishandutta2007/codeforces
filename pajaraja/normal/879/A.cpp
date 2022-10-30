#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,d=1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int t1,t2;
		cin>>t1>>t2;
		while(d<t1||d%t2!=t1%t2) d++;
		d++;
	}
	d--;
	cout<<d;
}