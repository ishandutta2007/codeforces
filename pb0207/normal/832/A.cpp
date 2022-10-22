#include<cstdio>
#include<iostream>
using namespace std;

long long a,b;

int main()
{
	cin>>a>>b;
	long long c=a/b;
	if(c&1)
		cout<<"YES";
	else
		cout<<"NO";
}