#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

const int maxn=200111;

int n,k;
LL a[maxn],b[maxn];

LL ta[maxn];
int last[maxn];
bool check(LL val)
{
	priority_queue<pii,vector<pii>,greater<pii> >pq;
	for(int i=1;i<=n;i++)
	{
		ta[i]=a[i];
		last[i]=0;
		if(ta[i]/b[i]<k)pq.push(mp(ta[i]/b[i]+1,i));
	}
	for(int i=1;i<=k;i++)
	{
		if(pq.empty())return true;
		if(pq.top().ff<i)return false;
		int x=pq.top().ss;pq.pop();
		ta[x]-=b[x]*(i-last[x]);ta[x]+=val;if(ta[x]<0)return false;
		last[x]=i;
		if(ta[x]/b[x]+i<k)pq.push(mp(ta[x]/b[x]+i+1,x));
	}
	if(pq.empty())return true;else return false;
}

int main()
{
	scanf("%d%d",&n,&k);k--;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<=n;i++)scanf("%lld",b+i);
	
	LL l=-1,r=2000000000002ll,mid;
	while(l<r-1)
	{
		mid=(l+r+1)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	if(r>2000000000000ll)r=-1;
	printf("%lld\n",r);
	return 0;
}