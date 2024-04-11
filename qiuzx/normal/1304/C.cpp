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
#define N 110
using namespace std;
ll n,m,t[N],lo[N],hi[N];
int main(){
	ll q,l,r,i;
	cin>>q;
	while(q--)
	{
		cin>>n>>m;
		l=m;
		r=m;
		t[0]=0;
		for(i=1;i<=n;i++)
		{
			cin>>t[i]>>lo[i]>>hi[i];
		}
		for(i=1;i<=n;i++)
		{
			l-=t[i]-t[i-1];
			r+=t[i]-t[i-1];
			l=max(l,lo[i]);
			r=min(r,hi[i]);
			if(l>r)
			{
				l=100;
				r=-100;
				break;
			}
		}
		if(l>r)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}