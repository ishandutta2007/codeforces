#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
map<int,int> m;
vector<int> zb,b;
pair<int,pair<int,int>> a[MAXN];
int lk[MAXN],rk[MAXN],seg[2][12*MAXN],iq[MAXN],rg[MAXN],x[MAXN];
bool cmp(int p,int q) {return rg[p]>rg[q];}
void upd(int k,int l,int r,int v,int t,int ind)
{
	if(l==r) {seg[k][ind]+=v; return;}
	int s=(l+r)/2;
	if(t<=s) upd(k,l,s,v,t,2*ind);
	else upd(k,s+1,r,v,t,2*ind+1);
	seg[k][ind]+=v;
}
int nsum(int k,int l,int r,int lt,int rt,int ind)
{
	if(l>=lt && r<=rt) return seg[k][ind];
	if(r<lt || l>rt) return 0;
	int s=(l+r)/2;
	return nsum(k,l,s,lt,rt,2*ind)+nsum(k,s+1,r,lt,rt,2*ind+1);
}
int main()
{
	int n,k;
	long long res=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) {scanf("%d%d%d",&a[i].second.second,&a[i].second.first,&a[i].first);}
	for(int i=0;i<n;i++) {zb.push_back(a[i].second.second); zb.push_back(a[i].second.second-a[i].second.first); zb.push_back(a[i].second.second+a[i].second.first);} 
	sort(zb.begin(),zb.end()); for(int i=0;i<zb.size();i++) m[zb[i]]=i;
	sort(a,a+n);
	for(int i=0;i<n;i++) {iq[i]=a[i].first; rg[i]=a[i].second.first; x[i]=m[a[i].second.second]; lk[i]=m[a[i].second.second-rg[i]]; rk[i]=m[a[i].second.second+rg[i]];}
	for(int i=0;i<n;i++) if(i==n-1 || iq[i]!=iq[i+1])
	{
		b.clear();
		for(int j=i;j>=0 && iq[i]-iq[j]<=k;j--) b.push_back(j);
		sort(b.begin(),b.end(),cmp);
		for(int j=0;j<b.size();j++)
		{
			if(iq[b[j]]==iq[i]) {res+=nsum(0,0,3*n,lk[b[j]],rk[b[j]],1)+nsum(1,0,3*n,lk[b[j]],rk[b[j]],1); upd(0,0,3*n,1,x[b[j]],1);}
			else {res+=nsum(0,0,3*n,lk[b[j]],rk[b[j]],1); upd(1,0,3*n,1,x[b[j]],1);}
		}
		for(int j=0;j<b.size();j++)
		{
			if(iq[b[j]]==iq[i]) upd(0,0,3*n,-1,x[b[j]],1);
			else upd(1,0,3*n,-1,x[b[j]],1);
		}
	}
	printf("%I64d",res);
}