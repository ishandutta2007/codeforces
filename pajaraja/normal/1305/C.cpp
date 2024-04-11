#include <bits/stdc++.h>
#define MAXN 100007
#define MAXM 1007
using namespace std;
long long a[MAXN];
int main()
{
	int n,m;
	long long rez=1;
	cin>>n>>m;
	if(n>m) {cout<<0; return 0;}
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		for(int j=0;j<i;j++) rez=(rez*abs(a[i]-a[j]))%m;
	}
	cout<<rez;
}