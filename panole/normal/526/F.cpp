#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v[300010];
int n,p[300010],lmi[300010],lma[300010],rmi[300010],rma[300010],pmi[300010],pma[300010],t[600010];
pair<int,int> a[300010];
long long ans;

void work(int l,int r)
{
	for (int i=l; i<=r; i++)
		for (int j=0,sz=v[i].size(); j<sz; j++)
			if (v[i][j].second==0) t[v[i][j].first]++;
			else ans+=v[i][j].second*t[v[i][j].first];
	for (int i=l; i<=r; i++)
		for (int j=0,sz=v[i].size(); j<sz; j++)
			t[v[i][j].first]=0; 
}

void solve(int l,int r)
{
	if (l==r) return;
	int mid=(l+r)>>1;
	solve(l,mid),solve(mid+1,r);
	lmi[mid]=lma[mid]=p[mid],rmi[mid+1]=rma[mid+1]=p[mid+1];
	for (int i=mid-1; i>=l; i--) lmi[i]=min(lmi[i+1],p[i]),lma[i]=max(lma[i+1],p[i]);
	for (int i=mid+2; i<=r; i++) rmi[i]=min(rmi[i-1],p[i]),rma[i]=max(rma[i-1],p[i]);
	int nwmi=mid,nwma=mid;
	for (int i=mid; i>=l; i--)
	{
		while (nwmi<r&&rmi[nwmi+1]>lmi[i]) nwmi++;
		while (nwma<r&&rma[nwma+1]<lma[i]) nwma++;
		pmi[i]=nwmi,pma[i]=nwma;
	}
	for (int i=mid+1; i<=r; i++) 
		v[i].push_back(make_pair(i-rma[i]+rmi[i]+300000,0));
	for (int i=l; i<=mid; i++)
		v[r].push_back(make_pair(i+300000,1)),v[max(pmi[i],pma[i])].push_back(make_pair(i+300000,-1));
	work(mid+1,r);
	for (int i=mid; i<=r; i++) v[i].clear(); 
	for (int i=mid+1; i<=r; i++)
		v[i].push_back(make_pair(i-rma[i]+300000,0));
	for (int i=l; i<=mid; i++) if (pma[i]<pmi[i])
		v[pmi[i]].push_back(make_pair(i-lmi[i]+300000,1)),v[pma[i]].push_back(make_pair(i-lmi[i]+300000,-1));
	work(mid+1,r);
	for (int i=mid; i<=r; i++) v[i].clear();
	for (int i=mid+1; i<=r; i++)
		v[i].push_back(make_pair(rmi[i]+i,0));
	for (int i=l; i<=mid; i++) if (pmi[i]<pma[i])
		v[pma[i]].push_back(make_pair(lma[i]+i,1)),v[pmi[i]].push_back(make_pair(lma[i]+i,-1));
	work(mid+1,r);
	for (int i=mid; i<=r; i++) v[i].clear();
	for (int i=mid+1; i<=r; i++)
		v[i].push_back(make_pair(i,0));
	for (int i=l; i<=mid; i++)
		v[min(pmi[i],pma[i])].push_back(make_pair(i-lmi[i]+lma[i],1));
	work(mid+1,r);
	for (int i=mid; i<=r; i++) v[i].clear();
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d%d",&a[i].first,&a[i].second);
	sort(a+1,a+1+n),memset(t,0,sizeof(t));
	for (int i=1; i<=n; i++) p[i]=a[i].second,v[i].clear();
	ans=n,solve(1,n),printf("%I64d\n",ans);
	return 0;
}