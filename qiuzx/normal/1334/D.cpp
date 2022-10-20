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
using namespace std;
ll t,n,l,r;
int main(){
	ll i,j,k,cnt1,cnt2;
	cin>>t;
	while(t--)
	{
		cin>>n>>l>>r;
		j=0;
		for(i=1;i<n;i++)
		{
			j+=2*(n-i);
			if(l<=j)
			{
				j-=2*(n-i);
				break;
			}
		}
		cnt1=i;
		cnt2=i+1;
		for(k=j+1;k<l;k++)
		{
			if(k%2==0)
			{
				cnt2++;
			}
			if(cnt2>n)
			{
				cnt1++;
				cnt2=cnt1+1;
			}
		}
		for(k=l;k<=r;k++)
		{
			if(k==n*(n-1)+1)
			{
				printf("1");
				break;
			}
			if(k%2==0)
			{
				printf("%I64d ",cnt2);
				cnt2++;
			}
			else
			{
				printf("%I64d ",cnt1);
			}
			if(cnt2>n)
			{
				cnt1++;
				cnt2=cnt1+1;
			}
		}
		puts("");
	}
	return 0;
}