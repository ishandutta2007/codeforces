#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;

struct mat
{
	int a[2][2];
	mat operator *(mat A)
	{
		mat B;
		B.a[0][0]=(1ll*a[0][0]*A.a[0][0]+1ll*a[0][1]*A.a[1][0])%mod;
		B.a[0][1]=(1ll*a[0][0]*A.a[0][1]+1ll*a[0][1]*A.a[1][1])%mod;
		B.a[1][0]=(1ll*a[1][0]*A.a[0][0]+1ll*a[1][1]*A.a[1][0])%mod;
		B.a[1][1]=(1ll*a[1][0]*A.a[0][1]+1ll*a[1][1]*A.a[1][1])%mod;
		return B;
	}
};

struct node{int l,r; mat v;}t[400010];
struct eve{int va,vb,s,x;}a[200010];
bool cmp(const eve &a,const eve &b) {return 1ll*a.va*b.vb<1ll*a.vb*b.va;}

int n,x[100010],v[100010],p[100010],cnt,ans;

int quickmi(int a,int b)
{
	int t=1;
	for (; b; b>>=1,a=1ll*a*a%mod)
		if (b&1) t=1ll*t*a%mod;
	return t;
}

void build(int i,int l,int r)
{
	t[i].l=l,t[i].r=r;
	if (l==r)
	{
		t[i].v.a[0][0]=t[i].v.a[1][0]=(p[l+1]<=1?1-p[l+1]:mod+1-p[l+1]);
		t[i].v.a[0][1]=t[i].v.a[1][1]=p[l+1]; return;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
	t[i].v=(t[i<<1].v*t[i<<1|1].v);
}

void change(int i,int x,int s)
{
	if (t[i].l==t[i].r)
	{
		t[i].v.a[s>>1][s&1]=0;
		return;
	}
	int mid=(t[i].l+t[i].r)>>1;
	change(i<<1|(x>mid),x,s);
	t[i].v=(t[i<<1].v*t[i<<1|1].v);
}

int main()
{
	scanf("%d",&n);
	if (n==1) return puts("0"),0;
	for (int i=1; i<=n; i++) scanf("%d%d%d",&x[i],&v[i],&p[i]),p[i]=1ll*p[i]*quickmi(100,mod-2)%mod;
	for (int i=1; i<n; i++)
	{
		a[++cnt]=(eve){x[i+1]-x[i],v[i]+v[i+1],2,i};
		if (v[i]!=v[i+1])
		{
			if (v[i]<v[i+1]) a[++cnt]=(eve){x[i+1]-x[i],v[i+1]-v[i],0,i};
			else a[++cnt]=(eve){x[i+1]-x[i],v[i]-v[i+1],3,i};
		}
	}
	sort(a+1,a+1+cnt,cmp);
	ans=1ll*a[1].va*quickmi(a[1].vb,mod-2)%mod,build(1,1,n-1);
	for (int i=1; i<=cnt; i++)
	{
		change(1,a[i].x,a[i].s);
		int nw=(1ll*p[1]*(t[1].v.a[1][0]+t[1].v.a[1][1])+1ll*(mod+1-p[1])*(t[1].v.a[0][0]+t[1].v.a[0][1]))%mod;
		ans=(ans+1ll*a[i].va*quickmi(a[i].vb,mod-2)%mod*(mod-nw))%mod;
		if (i!=cnt) ans=(ans+1ll*a[i+1].va*quickmi(a[i+1].vb,mod-2)%mod*nw)%mod;
	}
	printf("%d\n",ans);
	return 0;
}