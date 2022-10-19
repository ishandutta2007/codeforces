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
#define N 110
using namespace std;
ll n,k;
vector<ll> a;
ll runs()
{
	ll ret=0,i,mx;
	set<ll> st;
	while(a[a.size()-1]!=0)
	{
	    if(ret>1000)
	    {
	        return -1;
	    }
		if(a[0]==0&&k==1)
		{
			return -1;
		}
		st.clear();
		for(i=0;i<a.size();i++)
		{
			mx=a[i];
			st.insert(a[i]);
			a[i]=0;
			if(st.size()>=k)
			{
				break;
			}
		}
		for(i++;i<a.size();i++)
		{
			a[i]-=mx;
		}
		ret++;
	}
	return ret;
}
int main(){
	ll T,i,x;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&k);
		a.clear();
		for(i=0;i<n;i++)
		{
			scanf("%lld",&x);
			a.push_back(x); 
		}
		a.erase(unique(a.begin(),a.end()),a.end());
		if(a[0]==0&&k==1)
		{
			puts("-1");
			continue;
		}
		printf("%lld\n",runs());
	}
	return 0;
}