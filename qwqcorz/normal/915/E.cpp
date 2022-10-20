#include<bits/stdc++.h>
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
#define update(w) t[w]=t[ls]+t[rs]
#define calc(l,r) (len[r]-len[l-1])
using namespace std;
const int N=6e5+1e3;

int read()
{
    int s=0;
    char c=getchar(),lc='+';
    while (c<'0'||c>'9') lc=c,c=getchar();
    while (c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
    return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
  write(x);
  putchar(c);
}
int a[N],t[N*8],tag[N*8],l[N],r[N],k[N],len[2*N];
void doing(int w,int l,int r,int v)
{
	tag[w]=v;
	t[w]=calc(l,r)*v;
}
void down(int w,int l,int r)
{
	if (tag[w]<0||l==r) return;
	doing(ls,l,mid,tag[w]);
	doing(rs,mid+1,r,tag[w]);
	tag[w]=-1;
}
void change(int w,int l,int r,int L,int R,int v)
{
	if (r<L||R<l) return;
	if (L<=l&&r<=R)
	{
		doing(w,l,r,v);
		return;
	}
	down(w,l,r);
	change(ls,l,mid,L,R,v);
	change(rs,mid+1,r,L,R,v);
	update(w);
}

int main()
{
	memset(t,0,sizeof(t));
	memset(tag,-1,sizeof(tag));
	int n=read(),q=read(),m,num;
	for (int i=1;i<=q;i++)
	{
		a[i]=l[i]=read();
		a[q+i]=r[i]=read();
		k[i]=read();
	}
	sort(a+1,a+1+2*q);
	m=unique(a+1,a+1+2*q)-a-1;
	num=2*m-1;
	len[0]=0;
	for (int i=1;i<=m;i++)
	{
		len[2*i-1]=1;
		if (i<m) len[2*i]=a[i+1]-a[i]-1;
	}
	for (int i=1;i<=num;i++) len[i]+=len[i-1];
	for (int i=1;i<=q;i++)
	{
		int L=lower_bound(a+1,a+1+m,l[i])-a;
		int R=lower_bound(a+1,a+1+m,r[i])-a;
		change(1,1,num,2*L-1,2*R-1,!(k[i]-1));
		print(n-t[1]);
	}
}