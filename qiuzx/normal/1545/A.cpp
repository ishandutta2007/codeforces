#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 100010
using namespace std;
ll n,a[N],tp[N],op[N];
vector<ll> v;
int main(){
	ll T,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(tp,0,sizeof(tp));
		memset(op,0,sizeof(op));
		v.clear();
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			v.push_back(a[i]);
			if(i%2==0)
			{
				tp[a[i]]++;
			}
			else
			{
				op[a[i]]++;
			}
		}
		sort(v.begin(),v.end());
		for(i=0;i<n;i++)
		{
			if(i%2==0)
			{
				tp[v[i]]--;
			}
			else
			{
				op[v[i]]--;
			}
		}
		sort(tp,tp+N-1);
		reverse(tp,tp+N-1);
		sort(op,op+N-1);
		reverse(op,op+N-1);
		if(tp[0]>0||op[0]>0)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
		}
	}
	return 0;
}