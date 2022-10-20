#include<bits/stdc++.h>// 
#define ls (w*2)// 
#define rs (w*2+1)// 
#define mid ((l+r)/2)//l,r 
#define update(w) t[w]=t[ls]+t[rs]// 
using namespace std;//std 
const int N=15e4+1e3;//n 

inline int read()// 
{
    int s=0;
    char c=getchar(),lc='+';
    while (c<'0'||c>'9') lc=c,c=getchar();
    while (c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
    return lc=='-'?-s:s;
}
void write(int x)// 
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
void print(int x)// 
{
	putchar(' ');
	write(x);
}
int n,m,p,a[N];// 
struct node// 
{
	int n,tag,num[6],HP[6];
	node &operator =(const node &a)// 
	{
		n=a.n;
		tag=0;
		memcpy(num,a.num,sizeof(num));
		memcpy(HP,a.HP,sizeof(HP));
		return *this;
	}
	node operator +(const node &a)
	{
		node ans;
		ans=a;
		for (int i=1;i<=n;i++)
		{
			bool tag=0;
			for (int j=1;j<=ans.n;j++)
			if (ans.num[j]==num[i])
			{
				ans.HP[j]+=HP[i];
				tag=1;
				break;
			}
			if (tag) continue;
			if (ans.n<p)
			{
				ans.num[++ans.n]=num[i];
				ans.HP[ans.n]=HP[i];
				continue;
			}
			int k=1;
			for (int j=2;j<=ans.n;j++) if (ans.HP[j]<ans.HP[k]) k=j;
			if (ans.HP[k]>HP[i]) for (int j=1;j<=ans.n;j++) ans.HP[j]-=HP[i];
			else
			{
				int dec=ans.HP[k];
				ans.num[k]=num[i];
				ans.HP[k]=HP[i];
				for (int j=1;j<=ans.n;j++) ans.HP[j]-=dec;
			}
		}
		return ans;
	}
}t[N*4];
void build(int w,int l,int r)
{
	if (l==r)
	{
		t[w].n=t[w].HP[1]=1;
		t[w].num[1]=a[l];
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(w);
}
void doing(int w,int l,int r,int v)
{
	t[w].n=1;
	t[w].tag=t[w].num[1]=v;
	t[w].HP[1]=r-l+1;
}
void down(int w,int l,int r)
{
	if (l>=r||!t[w].tag) return;
	doing(ls,l,mid,t[w].tag);
	doing(rs,mid+1,r,t[w].tag);
	t[w].tag=0;
}
void change(int w,int l,int r,int L,int R,int v)
{
	down(w,l,r);
	if (r<L||R<l) return;
	if (L<=l&&r<=R)
	{
		doing(w,l,r,v);
		down(w,l,r);
		return;
	}
	down(w,l,r);
	down(ls,l,mid);
	down(rs,mid+1,r);
	change(ls,l,mid,L,R,v);
	change(rs,mid+1,r,L,R,v);
	update(w);
}
node query(int w,int l,int r,int L,int R)
{
	down(w,l,r);
	down(ls,l,mid);
	down(rs,mid+1,r);
	if (L<=l&&r<=R) return t[w];
	if (R<=mid) return query(ls,l,mid,L,R);
	if (mid<L) return query(rs,mid+1,r,L,R);
	return query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
}

int main()
{
	memset(t,0,sizeof(t));
	n=read();
	m=read();
	p=100/read();
	for (int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		int Q=read(),l=read(),r=read(),v=Q==1?read():0;
		if (Q==1) change(1,1,n,l,r,v);
		if (Q==2)
		{
			node ans=query(1,1,n,l,r);
			write(ans.n);
			for (int i=1;i<=ans.n;i++) print(ans.num[i]);
			putchar('\n');
		}
	}
}