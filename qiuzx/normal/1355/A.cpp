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
ll t,a,k,pw[20]; 
int main(){
	ll i,j,mn,mx;
	for(i=0;i<19;i++)
	{
		pw[i]=pow(10,i);
	}
	cin>>t;
	while(t--)
	{
		cin>>a>>k;
		k--;
		for(i=0;i<k;i++)
		{
			mn=10;
			mx=-1;
			for(j=0;j<19;j++)
			{
				if(a<pw[j])
				{
					break;
				}
				mn=min(mn,(a/pw[j]%10));
				mx=max(mx,(a/pw[j]%10));
			}
			if(mn*mx==0)
			{
				break;
			}
			a+=mn*mx;
		}
		cout<<a<<endl;
	}
	return 0;
}