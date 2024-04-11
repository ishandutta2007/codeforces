#include <bits/stdc++.h>
#define MAXN 1007
using namespace std;
int main()
{
	int n;
	cin>>n;
	int np=1,p=2;
	while(n>p && n>np)
	{
		if(p>np) {p=2*p; np=p+1;}
		else {p=2*np; np=p-1;}
	}
	if(n==np || n==p) cout<<1;
	else cout<<0;
}