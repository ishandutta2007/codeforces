#include<bits/stdc++.h>
using namespace std;

const double pi=acos(-1.0);
int n,x[100010],y[100010],tot,rt,l[100010],r[100010],id[100010];
pair<double,int> p[200010];
double L,R,mid;
long long k;

struct node{int ls,rs,val;}t[10000010];
bool cmp(int x,int y) {return r[x]<r[y];}

int query(int i,int l,int r,int ql,int qr)
{
	if (l==ql&&r==qr) return t[i].val;
	int mid=(l+r)>>1;
	if (qr<=mid) return t[i].ls?query(t[i].ls,l,mid,ql,qr):0;
	if (ql>mid) return t[i].rs?query(t[i].rs,mid+1,r,ql,qr):0;
	return (t[i].ls?query(t[i].ls,l,mid,ql,mid):0)+(t[i].rs?query(t[i].rs,mid+1,r,mid+1,qr):0);
}

void add(int i,int I,int l,int r,int x,int v)
{
	if (l==r) {t[i].val+=v; return;}
	int mid=(l+r)>>1;
	if (x<=mid) add(t[i].ls=(++tot),t[I].ls,l,mid,x,v),t[i].rs=t[I].rs;
	else add(t[i].rs=(++tot),t[I].rs,mid+1,r,x,v),t[i].ls=t[I].ls;
	t[i].val=t[t[i].ls].val+t[t[i].rs].val;
}

bool check(double R)
{
	int cnt=0,num=0;
	long long ans=0;
	for (int i=1; i<=n; i++) 
	{
		if (x[i]*x[i]+y[i]*y[i]<R*R+(1e-8)) 
		{
			num++;
			p[++cnt]=make_pair(-num,i); 
			p[++cnt]=make_pair(10*num,-i);
			continue;
		}
		double ang1=atan2(y[i],x[i]),ang2=acos(R/sqrt((double)(x[i]*x[i]+y[i]*y[i])));
		ang1+=ang2,ang2=ang1-2*ang2;
		if (ang1<0) ang1+=2*pi;
		if (ang1>=2*pi) ang1-=2*pi;
		if (ang2<0) ang2+=2*pi;
		if (ang2>=2*pi) ang2-=2*pi;
		p[++cnt]=make_pair(ang1,i);
		p[++cnt]=make_pair(ang2,-i);
	}
	sort(p+1,p+1+cnt);
	for (int i=1; i<=cnt; i++) 
		if (p[i].second<0) l[-p[i].second]=i;
		else r[p[i].second]=i;
	for (int i=1; i<=n; i++) 
	{
		id[i]=i;
		if (l[i]>r[i]) swap(l[i],r[i]);
	}
	sort(id+1,id+1+n,cmp);
	tot=rt=1;
	for (int I=1; I<=n; I++)
	{
		int i=id[I];
		ans+=query(rt,1,cnt,l[i],r[i]);
		int Rt=++tot;
		add(Rt,rt,1,cnt,l[i],-1);
		rt=Rt,Rt=++tot;
		add(Rt,rt,1,cnt,r[i],1);
		rt=Rt;
	}
	for (int i=1; i<=tot; i++) t[i].ls=t[i].rs=t[i].val=0;
	ans=1ll*n*(n-1)/2-ans;
	return ans>=k;
}

int main()
{
	scanf("%d%lld",&n,&k);
	for (int i=1; i<=n; i++) scanf("%d%d",&x[i],&y[i]);	
	L=0,R=100000;
	for (int i=1; i<=50; i++)
	{
		mid=(L+R)/2.0;
		if (check(mid)) R=mid; else L=mid;
	}
	printf("%.10lf\n",mid);
	return 0;
}