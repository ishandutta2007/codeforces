#include <bits/stdc++.h>
#define N 20
using namespace std;
int n,a[N];
int main(){
	int i,j,deg;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<(1<<n);i++)
	{
		deg=0;
		for(j=0;j<n;j++)
		{
			if((i>>j)&1==1)
				deg+=a[j];
			else
				deg-=a[j];
			if(deg<0)
				deg+=360;
		}
		if(deg%360==0)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}