#include<bits/stdc++.h>
using namespace std;

bool bo[100010];
int n,m,b[100010],g[100010],B,G,p[100010],gc,pn,pb,pg,np;
vector<int> vb[200010],vg[200010];
pair<int,int> po[200010];
map<int,int> Ma;
long long ans;

int gcd(int a,int b) {return (!b)?a:gcd(b,a%b);}

int quickmi(int a,int b,int mod)
{
	int t=1;
	for (; b; b>>=1,a=1ll*a*a%mod)
		if (b&1) t=1ll*t*a%mod;
	return t;
}

int getphi(int n)
{
	int ans=n;
	for (int i=1; i<=pn; i++)
		if (n%p[i]==0)
		{
			ans=ans/p[i]*(p[i]-1);
			while (n%p[i]==0) n/=p[i];
		}
	if (n!=1) ans=ans/n*(n-1);
	return ans;
}

long long solve(vector<int> b,vector<int> g)
{
	long long ans=-1;
	n=b.size(),m=g.size(),np=0,Ma.clear();
	for (int i=0; i<n; i++) Ma[b[i]]=b[i]+1;
	for (int i=0; i<m; i++)
		if (!Ma[g[i]%B]) Ma[g[i]%B]=g[i]+1,ans=max(ans,1ll*g[i]);
	for (map<int,int>::iterator it=Ma.begin(); it!=Ma.end(); it++)
		po[++np]=make_pair((int)(1ll*(*it).first*pb%B),(*it).second-1);
	sort(po+1,po+1+np),po[np+1]=po[1];
	for (int i=1; i<=np; i++) 
		if (po[i+1].first!=((po[i].first==B-1)?0:(po[i].first+1)))
			ans=max(ans,1ll*G*(po[i+1].first<=po[i].first?po[i+1].first+B-po[i].first-1:po[i+1].first-po[i].first-1)+po[i].second);
	np=0,Ma.clear();
	for (int i=0; i<m; i++) Ma[g[i]]=g[i]+1;
	for (int i=0; i<n; i++)
		if (!Ma[b[i]%G]) Ma[b[i]%G]=b[i]+1,ans=max(ans,1ll*b[i]);
	for (map<int,int>::iterator it=Ma.begin(); it!=Ma.end(); it++)
		po[++np]=make_pair((int)(1ll*(*it).first*pg%G),(*it).second-1);
	sort(po+1,po+1+np),po[np+1]=po[1];
	for (int i=1; i<=np; i++) 
		if (po[i+1].first!=((po[i].first==G-1)?0:(po[i].first+1)))
			ans=max(ans,1ll*B*(po[i+1].first<=po[i].first?po[i+1].first+G-po[i].first-1:po[i+1].first-po[i].first-1)+po[i].second);
	return ans;
}

int main()
{
	memset(bo,0,sizeof(bo)),pn=0;
	for (int i=2; i<=100000; i++) if (!bo[i])
	{
		p[++pn]=i;
		for (int j=(i<<1); j<=100000; j+=i) bo[j]=0;
	}
	scanf("%d%d",&B,&G);
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&b[i]);
	scanf("%d",&m);
	for (int i=1; i<=m; i++) scanf("%d",&g[i]);
	sort(b+1,b+1+n),sort(g+1,g+1+m);
	if ((gc=gcd(B,G))>n+m) return puts("-1"),0;
	B/=gc,G/=gc,ans=0,pb=getphi(B),pg=getphi(G);
	pb=quickmi(G%B,pb-1,B),pg=quickmi(B%G,pg-1,G);
	for (int i=1; i<=n; i++) vb[b[i]%gc].push_back(b[i]/gc);
	for (int i=1; i<=m; i++) vg[g[i]%gc].push_back(g[i]/gc);
	for (int i=0; i<gc; i++)
	{
		if (!vb[i].size()&&!vg[i].size()) return puts("-1"),0;
		ans=max(ans,1ll*gc*solve(vb[i],vg[i])+i);
	}
	printf("%I64d\n",ans);
	return 0;
}