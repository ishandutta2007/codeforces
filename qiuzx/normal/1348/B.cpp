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
#define N 10010
using namespace std;
ll t,n,k,a[N];
vector<ll> v;
bool book[110];
int main(){
	ll i,j;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		memset(book,0,sizeof(book));
		v.clear();
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}	
		for(i=0;i<n;i++)
		{
			if(!book[a[i]])
			{
				book[a[i]]=true;
				v.push_back(a[i]);
			}
		}
		if(v.size()>k)
		{
			puts("-1");
			continue;
		}
		printf("%lld\n",n*k);
		for(i=0;i<n;i++)
		{
			for(j=0;j<k;j++)
			{
				if(j<v.size())
				{
					printf("%lld ",v[j]);
				}
				else
				{
					printf("1 ");
				}
			}
		}
		puts("");
	}
	return 0;
}