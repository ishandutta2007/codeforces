#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
#define N 3510
using namespace std;
ll t,n,m,k,a[N],ans,tot;
int main(){
	ll i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		ans=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		m--;
		k=min(k,m);
		for(i=0;i<=k;i++)
		{
			tot=INF127;
			for(j=0;j<=m-k;j++)
			{
				tot=min(tot,max(a[i+j],a[n-(m-j-i)-1]));
			}
			ans=max(ans,tot);
		}
		cout<<ans<<endl;
	}
	return 0;
}