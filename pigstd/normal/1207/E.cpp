#include<bits/stdc++.h>
using namespace std;

int main()
{
	cout<<"? ";
	for (int i=1;i<=100;i++)cout<<i<<' ';
	cout<<endl;int c;cin>>c;
	cout<<"? ";
	for (int i=1;i<=100;i++)cout<<(i<<7)<<' ';
	cout<<endl;int d;cin>>d;
	int b=((c^d)>>7)<<7;
	cout<<"! "<<(b^d)<<endl;
	return 0;
}