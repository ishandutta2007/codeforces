#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,i,j;
	cin>>n;
	for(i=n/7;i>=0;i--)
	{
		if((n-i*7)%4==0)
		{
			for(j=0;j<(n-i*7)/4;j++)
			{
				cout<<"4";
			}
			for(j=0;j<i;j++)
			{
				cout<<"7";
			}
			cout<<endl;
			return 0;
		}
	}
	cout<<"-1"<<endl;
	return 0;
}