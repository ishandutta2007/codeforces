#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+1;

int n,a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	bool flag=1;
	int d=a[2]-a[1];
	for(int i=2;i<=n;++i)if(a[i]-a[i-1]!=d)flag=0;
	if(!flag)cout<<a[n];
	else    cout<<a[n]+d;
}