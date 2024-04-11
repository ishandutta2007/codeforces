#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
using namespace std;
ll n;
map<pair<ll,ll>,ll> sm;
int main(){
	ll l,r,mid,smx,tmx;
	cin>>n;
	l=1;
	r=n;
	cout<<"? "<<l<<" "<<r<<endl;
	fflush(stdout);
	cin>>smx;
	sm[make_pair(l,r)]=smx;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(smx>mid)
		{
			if(mid+1<n)
			{
				if(sm.count(make_pair(mid+1,n)))
				{
					tmx=sm[make_pair(mid+1,n)];
				}
				else
				{
					cout<<"? "<<mid+1<<" "<<n<<endl;
					fflush(stdout);
					cin>>tmx;
					sm[make_pair(mid+1,n)]=tmx;
				}
			}
			else
			{
				tmx=-LINF;
			}
			if(tmx==smx)
			{
				l=mid+1;
			}
			else
			{
				r=mid;
			}
		}
		else
		{
			if(1<mid)
			{
				if(sm.count(make_pair(1,mid)))
				{
					tmx=sm[make_pair(1,mid)];
				}
				else
				{
					cout<<"? "<<1<<" "<<mid<<endl;
					fflush(stdout);
					cin>>tmx;
					sm[make_pair(1,mid)]=tmx;
				}
			}
			else
			{
				tmx=-LINF;
			}
			if(tmx==smx)
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
	}
	cout<<"! "<<l<<endl;
	return 0;
}