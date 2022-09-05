#include<bits/stdc++.h>
using namespace std;

long long Ans[200010];
int n,a[200010],Q,p[200010],x,po[200010],sta[200010],tp,Po[200010];
long long b[200010],dis[200010],B[200010];
set<int> s;
set<int>::iterator it,itt;
struct Que{int l,r,ord;};
vector<Que> V;

void getdis(int l,int r,int ord) {V.push_back((Que){l,r,ord});}

void solve(vector<Que> V,int l,int r)
{
	//cerr<<l<<" "<<r<<" "<<V.size()<<endl;
	if (l==r) return;
	vector<Que> Vl,Vr;
	Vl.clear(),Vr.clear();
	int mid=(l+r)>>1;
	for (int i=mid; i>=l; i--)
	{
		if (po[i]>mid) dis[i]=b[i],p[i]=po[i];
		else dis[i]=dis[po[i]]+b[i],p[i]=p[po[i]];
	}
	for (int i=mid+1; i<=r; i++)
	{
		if (Po[i]<=mid) dis[i]=B[i],p[i]=Po[i];
		else dis[i]=dis[Po[i]]+B[i],p[i]=p[Po[i]];
	}
	for (int i=0,sz=V.size(); i<sz; i++) 
		if (V[i].r<=mid) Vl.push_back(V[i]); else
		if (V[i].l>mid) Vr.push_back(V[i]); else
		{
			if (p[V[i].l]>V[i].r) 
			{
				if (V[i].ord>=0) Ans[V[i].ord]+=dis[V[i].r];
				else Ans[-V[i].ord]-=dis[V[i].r];
				Vl.push_back((Que){V[i].l,p[V[i].r],V[i].ord});
			} else
			{
				if (V[i].ord>=0) Ans[V[i].ord]+=dis[V[i].l];
				else Ans[-V[i].ord]-=dis[V[i].l];
				Vr.push_back((Que){p[V[i].l],V[i].r,V[i].ord});
			}
		}
	solve(Vl,l,mid),solve(Vr,mid+1,r);
}

int main()
{
	scanf("%d%d",&n,&Q),V.clear();
	for (int i=1; i<=n; i++) scanf("%d",&p[i]);
	p[n+1]=n+1,sta[tp=1]=n+1;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	for (int i=1; i<=n; i++) scanf("%lld",&b[i]);
	for (int i=n; i; i--)
	{
		long long nw=a[i];
		while (p[sta[tp]]<p[i]) nw+=b[sta[tp]],tp--;
		b[i]=min(nw,b[i]),po[i]=sta[tp],sta[++tp]=i;
		Po[po[i]]=i,B[po[i]]=b[i];
	}
	for (int i=2; i<=n+1; i++) if (!Po[i]) Po[i]=i-1,B[i]=a[i-1];
	s.clear();
	s.insert(1),s.insert(n+1);
	getdis(1,n+1,0);
	for (int T=1; T<=Q; T++)
	{
		scanf("%d",&x);
		if (x==1) continue;
		if (s.find(x)!=s.end())
		{
			it=s.find(x);
			int p1=(*--it); it++;
			int p2=(*++it); it--;
			s.erase(it),getdis(p1,x,-T),getdis(x,p2,-T),getdis(p1,p2,T);
		} else
		{
			it=s.lower_bound(x);
			int p2=(*it),p1=(*--it);
			s.insert(x),getdis(p1,p2,-T),getdis(p1,x,T),getdis(x,p2,T);
		}
	}
	solve(V,1,n+1);
	for (int i=1; i<=Q; i++)
	{
		Ans[i]+=Ans[i-1];
		printf("%lld\n",Ans[i]);
	}
	return 0;
}