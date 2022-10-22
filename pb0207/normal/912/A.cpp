#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

long long a,b,x,y,z;

int main()
{
	cin>>a>>b>>x>>y>>z;
	cout<<max(x*2+y-a,0ll)+max(z*3+y-b,0ll);
}