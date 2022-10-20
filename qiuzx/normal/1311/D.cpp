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
int t,a,b,c,ans;
int main(){
	int aa,ab,ac,i,j,k;
	cin>>t;
	while(t--)
	{
		aa=1;
		ab=1;
		ac=1;
		cin>>a>>b>>c;
		ans=INF;
		for(i=1;i<=20000;i++)
		{
			for(j=i;j<=20000;j+=i)
			{
				for(k=j;k<=20000;k+=j)
				{
					if(ans>abs(a-i)+abs(b-j)+abs(c-k))
					{
						ans=abs(a-i)+abs(b-j)+abs(c-k);
						aa=i;
						ab=j;
						ac=k;
					}
				}
			}
		}
		cout<<ans<<endl<<aa<<" "<<ab<<" "<<ac<<endl;
	}
	return 0;
}