#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;
typedef long long LL;
const int maxn=50005;
priority_queue<pair<int,int> >pq;
pair<int,int> task[maxn];
int id,n,page[maxn],s[maxn],p[maxn];
LL t,t2,T,e[maxn];
vector<int> P,V;
void check()
{
	for(int i=1;i<=n;i++)page[i]=s[i];
	int next=1;
	t=0;
	while(true)
	{
		while(next!=n+1&&task[next].ff==t)
		{
			pq.push(mp(p[task[next].ss],task[next].ss));
			next++;
		}
		if(pq.empty())
		{
			if(next==n+1)return;
			t=task[next].ff;
			continue;
		}
		int x=pq.top().ss;
		t2=t+page[x];
		if(next!=n+1)t2=min(t2,task[next].ff*1ll);
		page[x]-=t2-t;
		if(page[x]==0)
		{
			pq.pop();
			e[x]=t2;
		}
		t=t2;
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&task[i].ff,s+i,p+i);
		task[i].ss=i;
		P.push_back(p[i]);
		if(p[i]==-1)id=i;
	}
	scanf("%I64d",&T);
	sort(task+1,task+n+1);
	P.push_back(0);
	P.push_back(1000000053);
	sort(P.begin(),P.end());
	for(int i=1;i<(int)P.size();i++)
		if(P[i]-P[i-1]>=2)V.push_back(P[i-1]+1);
	int l=0,r=V.size(),mid;
	while(l<r-1)
	{
		mid=l+r>>1;
		p[id]=V[mid];
		check();
		if(e[id]>=T)l=mid;else r=mid;
		if(e[id]==T)break;
	}
	printf("%d\n",V[l]);
	for(int i=1;i<=n;i++)printf("%I64d ",e[i]);
	return 0;
}