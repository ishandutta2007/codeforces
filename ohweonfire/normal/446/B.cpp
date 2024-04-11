#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1003;
priority_queue<ll> q1,q2;
ll s1[maxn],s2[maxn],c1[maxn*maxn],c2[maxn*maxn],best,tmp;
int n,m,k,p;
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			scanf("%I64d",&tmp);
			s1[i]+=tmp;
			s2[j]+=tmp;
		}
	for(int i=0;i<n;++i)
		q1.push(s1[i]);
	for(int j=0;j<m;++j)
		q2.push(s2[j]);
	for(int i=1;i<=k;++i)
	{
		tmp=q1.top();
		q1.pop();
		c1[i]=c1[i-1]+tmp;
		q1.push(tmp-m*p);
		tmp=q2.top();
		q2.pop();
		c2[i]=c2[i-1]+tmp;
		q2.push(tmp-n*p);
	}
	best=-100000000000000000ll;
	for(int i=0;i<=k;++i)
		best=max(best,c1[i]+c2[k-i]-(k-i)*1ll*i*p);
	printf("%I64d\n",best);
	return 0;
}