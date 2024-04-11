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
ll a,b,c,d,ans=0;
int main(){
	ll i,mx,mx2,aa,bb;
	cin>>a>>b>>c>>d;
	for(i=c;i<=d;i++)//z
	{
		mx=i-b+1;
		mx=c-mx+1;
		mx=max(mx,(ll)0);
		aa=min(mx,c-b+1);
		bb=max((ll)0,mx-b+a);
		//cout<<aa<<" "<<bb<<endl;
		if(bb<=aa)
		{
			ans+=(aa+bb)*(aa-bb+1)/2;
			if(mx>aa)
			{
				ans+=(mx-aa)*aa;
			}
		}
		else
		{
			ans+=aa*(mx-bb+1);
		}
	}
	cout<<ans<<endl;
	return 0;
}