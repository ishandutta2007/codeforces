#include<bits/stdc++.h>
using namespace std;

int n,m,k,mn,po[100010],ansn,ans[100010];
pair<int,int> mul[100010],ma[100010];
pair<long double,int> M[100010];
struct node{int ord,po,b;}b[100010];
vector<pair<int,int> > v[100010];
long long nw[100010];
set<pair<long double,int> > s;

bool cmp(pair<int,int> a,pair<int,int> b) {return a>b;}
bool Cmp(pair<long double,int> a,pair<long double,int> b) {return a>b;}

int main()
{
	scanf("%d%d%d",&n,&k,&m),mn=0;
	for (int i=1; i<=n; i++) scanf("%I64d",&nw[i]),ma[i]=make_pair(0,0);
	for (int i=1; i<=k; i++) 
	{
		scanf("%d%d%d",&b[i].ord,&b[i].po,&b[i].b);
		if (b[i].ord==3) {if (b[i].b>1) mul[++mn]=make_pair(b[i].b,i);} else
		if (b[i].ord==1) ma[b[i].po]=max(ma[b[i].po],make_pair(b[i].b,i)); else
		v[b[i].po].push_back(make_pair(b[i].b,i));
	}
	int cnt=0;
	for (int i=1; i<=n; i++) 
	{
		if (nw[i]<ma[i].first) v[i].push_back(make_pair(ma[i].first-nw[i],ma[i].second));
		sort(v[i].begin(),v[i].end(),cmp);
		if (!v[i].empty()&&v[i][0].first>=nw[i]) cnt++;
	}
	if (cnt+mn>=m)
	{
		for (int i=1; i<=mn; i++) M[i]=make_pair((long double)mul[i].first,mul[i].second);
		for (int i=1; i<=n; i++)
			if (!v[i].empty()&&v[i][0].first>=nw[i]) 
				M[++mn]=make_pair(((long double)nw[i]+v[i][0].first)/nw[i],v[i][0].second);
		sort(M+1,M+1+mn,Cmp);
		printf("%d\n",m);
		for (int i=1; i<=m; i++) if (b[M[i].second].ord<=2) printf("%d ",M[i].second);
		for (int i=1; i<=m; i++) if (b[M[i].second].ord==3) printf("%d ",M[i].second);
	} else
	{
		s.clear(),ansn=0;
		for (int i=1; i<=mn; i++) ans[++ansn]=mul[i].second;
		for (int i=1; i<=n; i++)
		{
			po[i]=0;
			if (!v[i].empty()) s.insert(make_pair(((long double)nw[i]+v[i][0].first)/nw[i],i));
		}
		for (int i=1,x; i<=m-mn; i++)
		{
			if (s.empty()) break;
			x=(*s.rbegin()).second,s.erase(--s.end());
			ans[++ansn]=v[x][po[x]].second,nw[x]+=v[x][po[x]].first;
			if ((++po[x])<v[x].size()) s.insert(make_pair(((long double)nw[x]+v[x][po[x]].first)/nw[x],x));
		}
		printf("%d\n",ansn);
		for (int i=1; i<=ansn; i++) if (b[ans[i]].ord==1) printf("%d ",ans[i]);
		for (int i=1; i<=ansn; i++) if (b[ans[i]].ord==2) printf("%d ",ans[i]);
		for (int i=1; i<=ansn; i++) if (b[ans[i]].ord==3) printf("%d ",ans[i]);
	}
	return puts(""),0;
}