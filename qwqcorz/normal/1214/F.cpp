#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct node
{
	int x,id;
	bool operator <(const node &a)const
	{
		return x<a.x;
	}
}A[N],B[N];
int a[N+N],b[N+N],n,m,p[N];
ll c[N],ans=1e18;
void add(int l,int r,int x){c[l]+=x,c[r+1]-=x;/*cout<<"    ";print(l,' '),print(r,':'),print(x);*/}
void solve1(int x,int l,int r)
{
//	putchar('A'),putchar(' '),print(x,':'),puts("");
	if (l>r) return;
	if (a[x]>m/2)
	{
		int pos=lower_bound(b+l,b+r+1,a[x]-m/2)-b-1;
		if (pos>=l) add(l-x,pos-x,m-a[x]),l=pos+1;
	}
	{
		int pos=lower_bound(b+l,b+r+1,a[x])-b-1;
		if (pos>=l) add(l-x,pos-x,a[x]),l=pos+1;
	}
	{
		int pos=lower_bound(b+l,b+r+1,a[x]+m/2+1)-b-1;
		if (pos>=l) add(l-x,pos-x,-a[x]),l=pos+1;
	}
	if (a[x]+m/2+1<=m) add(l-x,r-x,m+a[x]);
}
void solve2(int x,int l,int r)
{
//	putchar('B'),putchar(' '),print(x,':'),puts("");
	if (l>r) return;
	if (b[x]>m/2)
	{
		int pos=lower_bound(a+l,a+r+1,b[x]-m/2)-a-1;
		if (pos>=l) add(x-pos,x-l,-b[x]),l=pos+1;
	}
	{
		int pos=lower_bound(a+l,a+r+1,b[x]+1)-a-1;
		if (pos>=l) add(x-pos,x-l,b[x]),l=pos+1;
	}
	{
		int pos=lower_bound(a+l,a+r+1,b[x]+m/2+1)-a-1;
		if (pos>=l) add(x-pos,x-l,-b[x]),l=pos+1;
	}
	if (b[x]+m/2+1<=m) add(x-r,x-l,b[x]);
}

signed main()
{
	m=read(),n=read();
	for (int i=1;i<=n;i++) A[i].x=read(),A[i].id=i;
	for (int i=1;i<=n;i++) B[i].x=read(),B[i].id=i;
	sort(A+1,A+1+n);
	sort(B+1,B+1+n);
	for (int i=1;i<=n;i++) a[i]=a[i+n]=A[i].x;
	for (int i=1;i<=n;i++) b[i]=b[i+n]=B[i].x;
	for (int i=1;i<=n;i++) solve1(i,i,n),solve1(i,n+1,i+n-1);
	for (int i=1;i<=n+n;i++) solve2(i,max(i-n+1,1),min(i,n));
	for (int i=1;i<n;i++) c[i]+=c[i-1];
//	for (int i=0;i<n;i++) ans=min(ans,c[i]),print(c[i]);
	int x=0;
	for (int i=0;i<n;i++)
	if (ans>c[i]) ans=c[i],x=i;
	print(ans);
	for (int i=1;i<=n;i++)
	{
		int k=i+x;
		if (k>n) k-=n;
		p[A[i].id]=B[k].id;
	}
	for (int i=1;i<=n;i++) print(p[i]," \n"[i==n]);
	
	return 0;
}