#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
int r[MAXN],a[2][MAXN],b[2][MAXN],val[2][MAXN],n,u[MAXN];
mt19937 rng(time(NULL));
void calc(int k)
{
	priority_queue<pair<int,int> > pq;
	for(int i=1;i<=n;i++) 
	{
		pq.push(make_pair(a[k][i],-i));
		pq.push(make_pair(b[k][i],i));
	}
	int hx=0,px=0;
	while(!pq.empty())
	{
		int t=pq.top().second;
		pq.pop();
		if(t<0) 
		{
			hx^=r[-t];
			val[k][-t]^=(px^u[-t]);
		}
		if(t>0)
		{
			u[t]=px;
			val[k][t]=hx;
			hx^=r[t];
			px^=r[t];
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) r[i]=rng();
	for(int i=1;i<=n;i++) scanf("%d%d%d%d",&a[0][i],&b[0][i],&a[1][i],&b[1][i]);
	calc(0); calc(1);
	for(int i=1;i<=n;i++) if(val[0][i]!=val[1][i]) {printf("NO"); return 0;}
	printf("YES");
}