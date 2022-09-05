#include<bits/stdc++.h>
using namespace std;

int n,k,a[200010],ans,cnt,vn,t[200010];
long long sum[200010],ss[200010],s[200010],nw;
pair<long long,int> val[200010];
struct P{long long x,y; int p;};
bool cmp(P a,P b) {return a.y>b.y;}
vector<int> Ans;

void add(int x,int v){for (; x<=cnt; x+=(x&-x)) t[x]=max(t[x],v);}
int query(int x){int T=-1; for (; x; x-=(x&-x)) T=max(t[x],T); return T;}

void work(vector<P> A,vector<P> B)
{
	int nA=A.size(),nB=B.size();
	vn=cnt=0;
	for (int i=0; i<nA; i++) val[++vn]=make_pair(-A[i].x,i+1);
	for (int i=0; i<nB; i++) val[++vn]=make_pair(-B[i].x,-i-1);
	sort(val+1,val+1+vn);
	for (int i=1; i<=vn; i++)
	{
		if (i==1||val[i].first!=val[i-1].first) cnt++;
		if (val[i].second<0) B[-val[i].second-1].x=cnt;
		else A[val[i].second-1].x=cnt;
	}
	for (int i=0; i<=cnt; i++) t[i]=-1;
	sort(A.begin(),A.end(),cmp);
	sort(B.begin(),B.end(),cmp);
	for (int i=0,p=0; i<nA; i++)
	{
		while (p<nB&&B[p].y>=A[i].y) add(B[p].x,B[p].p),p++;
		Ans[A[i].p]=query(A[i].x);
	}
}

void solve(int l,int r)
{
	if (l==r) return;
	int mid=(l+r)>>1;
	solve(l,mid),solve(mid+1,r),nw=0;
	for (int i=mid; i>=l; i--) 
	{
		if (nw<0) nw=a[i];
		else nw+=a[i];
		if (i==mid) ss[i]=max(nw,0ll);
		else ss[i]=max(ss[i+1],nw);
	}
	nw=0;
	for (int i=mid+1; i<=r; i++)
	{
		if (nw<0) nw=a[i];
		else nw+=a[i];
		if (i==mid+1) ss[i]=max(nw,0ll);
		else ss[i]=max(ss[i-1],nw);
	}
	nw=0;
	for (int i=mid; i>=l; i--)
	{
		nw+=a[i];
		if (i==mid) s[i]=max(nw,0ll);
		else s[i]=max(s[i+1],nw);
	}
	nw=0;
	for (int i=mid+1; i<=r; i++)
	{
		nw+=a[i];
		if (i==mid+1) s[i]=max(nw,0ll);
		else s[i]=max(s[i-1],nw);
	}
	nw=0;
	for (int i=mid; i>=l; i--)
	{
		nw=max(nw,-1ll*a[i]);
		ss[i]=max(ss[i],nw);
	}
	nw=0;
	for (int i=mid+1; i<=r; i++)
	{
		nw=max(nw,-1ll*a[i]);
		ss[i]=max(ss[i],nw);
	}
	vector<P> v1,v2;
	v1.clear(),v2.clear();
	for (int i=l; i<=mid; i++) v1.push_back((P){sum[i-1]-k,sum[i-1]+s[i]-k,i-l});
	for (int i=mid+1; i<=r; i++) v2.push_back((P){sum[i]-ss[i],sum[i]-s[i],i});
	Ans.resize(mid-l+1),work(v1,v2);
	for (int i=0; i<=mid-l; i++) 
		if (Ans[i]!=-1&&ss[Ans[i]]>=ss[l+i]) ans=max(ans,Ans[i]-i-l+1);
	v1.clear(),v2.clear();
	for (int i=mid+1; i<=r; i++) v1.push_back((P){-sum[i]-k,-sum[i]+s[i]-k,i-mid-1});
	for (int i=l; i<=mid; i++) v2.push_back((P){-sum[i-1]-ss[i],-sum[i-1]-s[i],n-i+1});
	Ans.resize(r-mid),work(v1,v2);
	for (int i=0; i<r-mid; i++)
		if (Ans[i]!=-1&&ss[n-Ans[i]+1]>=ss[mid+1+i]) ans=max(ans,mid+1+i-(n-Ans[i]+1)+1);
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1; i<n; i++) scanf("%d",&a[2*i]),a[2*i]=-a[2*i];
	for (int i=1; i<=n; i++) scanf("%d",&a[2*i-1]);
	n=2*n-1,sum[0]=0,ans=1;
	for (int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
	solve(1,n),printf("%d\n",(ans+1)/2);
	return 0;
}