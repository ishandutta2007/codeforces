#include<bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N=2e5+5; 

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int n,m,tx,ty;
int a[N],b[N],px[N],py[N],sx[N],sy[N];
ll sumx(int l,int r){return sx[r]-sx[l-1];}
ll sum(int x,int y,bool cut)
{
	bool flag=0;
	if (px[x]<y)
	{
		int ret=1LL*py[y]*y+1LL*sumx(py[y]+1,x)+1LL*(n-x)*(m-y);
		if (cut)
			flag|=tx<=x&&ty<=y&&ty<=px[tx],
			flag|=tx>x&&ty>y;
		return ret-flag;
	}
	else
	{
		int ret=1LL*x*y+1LL*((py[y]-x)*m-sumx(x+1,py[y]))+1LL*(n-py[y])*(m-y);
		if (cut)
			flag|=tx>x&&ty>y&&ty>px[tx],
			flag|=tx<=x&&ty<=y;
		return ret-flag;
	}
}
bool check(int mid)
{
	for (int i=1,j=px[0]=m;i<=n;i++)
	{
		while (j&&a[i]+b[j]>mid) j--;
		px[i]=j;
	}
	for (int i=1;i<=n;i++) sx[i]=sx[i-1]+px[i];
	for (int i=1,j=py[0]=n;i<=m;i++)
	{
		while (j&&a[j]+b[i]>mid) j--;
		py[i]=j;
	}
	ll t0=max(sumx(1,n),1LL*n*m-sumx(1,n));
	for (int i=1,p=1;i<=n;i++)
	{
		while (p<m&&sum(i,p,0)<=sum(i,p+1,0)) p++;
		t0=max(t0,sum(i,p,0));
	}
	ll t1=max(sumx(1,n)-(ty<=px[tx]),1LL*n*m-sumx(1,n)-(ty>px[tx]));
	for (int i=1,p=1;i<=n;i++)
	{
		while (p<m&&sum(i,p,1)<=sum(i,p+1,1)) p++;
		t1=max(t1,sum(i,p,1));
	}
	return t0!=t1+1;
}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++) b[i]=read();
	int sx=a[1],sy=b[1];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	for (int i=1;i<=n;i++) if (sx==a[i]){tx=i;break;}
	for (int i=1;i<=m;i++) if (sy==b[i]){ty=i;break;}
	
	int l=a[1]+b[1],r=a[tx]+b[ty],ans=r;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid)) r=mid-1,ans=mid;
				   else l=mid+1;
	}
	print(ans);
	
	return 0;
}