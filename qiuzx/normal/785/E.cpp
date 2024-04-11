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
#define N 200010
#define SQ 1800 
using namespace std;
ll n,q,ans=0,a[N];
vector<ll> seg[SQ];
int main(){
	ll i,pos,x,y;
	scanf("%lld%lld",&n,&q);
	for(i=0;i<n;i++)
	{
		a[i]=i;
		seg[i/SQ].push_back(i);
	}
	while(q--)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		if(x>y)
		{
			swap(x,y);
		}
		if(x==y)
		{
			printf("%lld\n",ans);
			continue;
		}
		if(x/SQ==y/SQ)
		{
			for(i=x%SQ+1;i<y%SQ;i++)
			{
				if(a[i+(x/SQ)*SQ]>a[x])
				{
					ans++;
				}
				else
				{
					ans--;
				}
				if(a[i+(x/SQ)*SQ]<a[y])
				{
					ans++;
				}
				else
				{
					ans--;
				}
			}
		}
		else
		{
			for(i=x%SQ+1;i<SQ;i++)
			{
				if(i>=n)
				{
					break;
				}
				if(a[i+(x/SQ)*SQ]>a[x])
				{
					ans++;
				}
				else
				{
					ans--;
				}
				if(a[i+(x/SQ)*SQ]<a[y])
				{
					ans++;
				}
				else
				{
					ans--;
				}
			}
			for(i=0;i<y%SQ;i++)
			{
				if(a[i+(y/SQ)*SQ]>a[x])
				{
					ans++;
				}
				else
				{
					ans--;
				}
				if(a[i+(y/SQ)*SQ]<a[y])
				{
					ans++;
				}
				else
				{
					ans--;
				}
			}
		}
		for(i=x/SQ+1;i<y/SQ;i++)
		{
			pos=lower_bound(seg[i].begin(),seg[i].end(),a[x])-seg[i].begin();
			ans+=seg[i].size()-pos;
			ans-=pos;
			pos=lower_bound(seg[i].begin(),seg[i].end(),a[y])-seg[i].begin();
			ans-=seg[i].size()-pos;
			ans+=pos;
		}
		pos=lower_bound(seg[x/SQ].begin(),seg[x/SQ].end(),a[x])-seg[x/SQ].begin();
		seg[x/SQ].erase(seg[x/SQ].begin()+pos);
		pos=lower_bound(seg[y/SQ].begin(),seg[y/SQ].end(),a[y])-seg[y/SQ].begin();
		seg[y/SQ].erase(seg[y/SQ].begin()+pos);
		pos=lower_bound(seg[x/SQ].begin(),seg[x/SQ].end(),a[y])-seg[x/SQ].begin();
		seg[x/SQ].insert(seg[x/SQ].begin()+pos,a[y]);
		pos=lower_bound(seg[y/SQ].begin(),seg[y/SQ].end(),a[x])-seg[y/SQ].begin();
		seg[y/SQ].insert(seg[y/SQ].begin()+pos,a[x]);
		if(a[x]<a[y])
		{
			ans++;
		}
		else if(a[x]>a[y])
		{
			ans--;
		}
		swap(a[x],a[y]);
		printf("%lld\n",ans);
	}
	return 0;
}