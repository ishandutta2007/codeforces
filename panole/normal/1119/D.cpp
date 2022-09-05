#include<bits/stdc++.h>
using namespace std;

int n,Q;
struct node{long long len; int po;}q[100001];
long long a[100001],ans[100001],nwk,nwb;
multiset<long long> s;

bool cmp(node a,node b) {return a.len<b.len;}

int main()
{
	scanf("%d",&n),s.clear();
	for (int i=1; i<=n; i++) scanf("%I64d",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1; i<n; i++) s.insert(a[i+1]-a[i]);
	scanf("%d",&Q);
	for (int i=1; i<=Q; i++) scanf("%I64d%I64d",&nwk,&nwb),q[i].len=nwb-nwk+1,q[i].po=i;
	sort(q+1,q+1+Q,cmp),nwk=n,nwb=0;
	for (int i=1; i<=Q; i++)
	{
		while (s.size()&&(*s.begin())<=q[i].len)
			nwb+=(*s.begin()),nwk--,s.erase(s.begin());
		ans[q[i].po]=nwk*q[i].len+nwb;
	}
	for (int i=1; i<=Q; i++) printf("%I64d ",ans[i]);
	return puts(""),0;
}