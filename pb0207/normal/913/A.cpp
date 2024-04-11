#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

long long n,m;

int main()
{
	cin>>m>>n;
	if(m>32)
		cout<<n;
	else
		cout<<(n%(1ll<<m));
}