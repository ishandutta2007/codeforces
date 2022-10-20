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
using namespace std;
ll n,m,s,ans=0;
int main(){
	ll i,j,a,b,c,d;
	cin>>n>>m>>s;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			for(a=0;a<=j&&a<m-j;a++)
			{
				if(s%(2*a+1)==0&&(s/(2*a+1))%2==1)
				{
					b=(s/(2*a+1)-1)/2;
					if(b<=i&&b<n-i)
					{
						ans++;
						ans+=2*a*max((ll)0,b);
						ans+=2*max((ll)0,b);
						ans+=2*a;
					}
				}
			}
		}
	}
	for(a=0;2*a+1<=m;a++)
	{
		for(b=0;2*b+1<=n;b++)
		{
			for(c=0;c<a;c++)
			{
				if((s-4*a*b-2*a+4*b*c-1)%(4*c+2)==0)
				{
					d=(s-4*a*b-2*a+4*b*c-1)/(4*c+2);
					if(b<d&&2*d+1<=n)
					{
						ans+=2*(m-2*a)*(n-2*d);
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}