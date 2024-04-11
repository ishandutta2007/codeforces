#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	cout<<1;
	for(int i=1;i<2000;i++) cout<<(i%2==0?9:0);
	cout<<9<<endl;
	cout<<8;
	for(int i=1;i<2000;i++) cout<<(i%2==0?0:9);
	cout<<1;
}