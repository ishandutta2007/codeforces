#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 110
using namespace std;
ll t,n,a[N],b[N];
int main(){
	ll i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		a[0]=b[0]=0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i];
		}
		for(i=1;i<=n;i++)
		{
			if(a[i]-a[i-1]<b[i]-b[i-1])
			{
				i=-1;
				break;
			}
			else if(a[i]<a[i-1]||b[i]<b[i-1])
			{
				i=-1;
				break;
			}
		}
		if(i==-1)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
		}
	}
	return 0;
}