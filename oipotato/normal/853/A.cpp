#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int c[300010],n,k,ansp[300010];
long long ans;
struct data
{
	int id,num;
	friend bool operator <(data a,data b)
	{
		return a.num<b.num;
	}
};
priority_queue<data> q;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=k;i++)
		q.push((data){i,c[i]});
	for(int i=k+1;i<=k+n;i++)
	{
		if(i<=n)
			q.push((data){i,c[i]});
		data u=q.top();
		q.pop();
		ans+=1ll*(i-u.id)*u.num;
		ansp[u.id]=i;
	}
	printf("%I64d\n",ans);
	for(int i=1;i<n;i++)
		printf("%d ",ansp[i]);
	printf("%d\n",ansp[n]);
	return 0;
}