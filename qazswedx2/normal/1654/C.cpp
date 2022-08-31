#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int T,n,a[1000005];
priority_queue<ll> pq;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		while(!pq.empty()) pq.pop();
		ll sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		sort(a+1,a+n+1);
		pq.push(sum);
		int fl=1;
		for(int k=n;k>=1;k--)
		{
			while(1)
			{
				ll u=pq.top();
				pq.pop();
				if(u<a[k])
				{
					fl=0;
					break;
				}
				if(u==a[k]) break;
				pq.push(u/2);
				pq.push((u+1)/2);
			}
			if(!fl) break;
		}
		if(fl) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}