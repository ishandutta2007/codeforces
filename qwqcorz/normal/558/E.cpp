#include<bits/stdc++.h>
#define mid ((l+r)/2)
#define ls (w*2)
#define rs (w*2+1)
using namespace std;
const int N=1e5+5;

inline int read()
{
	register int s=0;
	register char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(register int x)
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
inline void print(const register int x,const register char c='\n')
{
	write(x);
	putchar(c);
}
char get()
{
	char c=getchar();
	while (c<'a'||'z'<c) c=getchar();
	return c;
}
struct node
{
	int v[27],tag,len;
	node():tag(0),len(0){for (int i=1;i<=26;i++) v[i]=0;}
	void update(int c)
	{
		tag=c;
		for (int i=1;i<=26;i++) v[i]=0;
		v[c]=len;
	}
	node operator +(const node &a)const
	{
		node ret;
		ret.len=len+a.len;
		for (int i=1;i<=26;i++) ret.v[i]=v[i]+a.v[i];
		return ret;
	}
}t[N*4],null;
char a[N];
int n,q;
void build(int w,int l,int r)
{
	if (l==r)
	{
		t[w].len=1;
		t[w].v[a[l]-'a'+1]=1;
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[w]=t[ls]+t[rs];
}
void push_down(int w)
{
	if (t[w].tag==0) return;
	t[ls].update(t[w].tag);
	t[rs].update(t[w].tag);
	t[w].tag=0;
}
void cover(int w,int l,int r,int L,int R,int x)
{
	if (L>R) return;
	if (r<L||R<l) return;
	if (L<=l&&r<=R) return t[w].update(x);
	push_down(w);
	cover(ls,l,mid,L,R,x);
	cover(rs,mid+1,r,L,R,x);
	t[w]=t[ls]+t[rs];
}
node query(int w,int l,int r,int L,int R)
{
	if (r<L||R<l) return null;
	if (L<=l&&r<=R) return t[w];
	push_down(w);
	return query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
}
void Sort(int l,int r,int op)
{
	node tmp=query(1,1,n,l,r);
	if (op) for (int i=1,now=l;i<=26;now+=tmp.v[i++]) cover(1,1,n,now,now+tmp.v[i]-1,i);
	   else for (int i=1,now=r;i<=26;now-=tmp.v[i++]) cover(1,1,n,now-tmp.v[i]+1,now,i);
}
void out(int w,int l,int r)
{
	if (l==r) for (int i=1;i<=26;i++) if (t[w].v[i]) return void(putchar('a'+i-1));
	push_down(w);
	out(ls,l,mid);
	out(rs,mid+1,r);
}

int main()
{
	n=read();
	q=read();
	for (int i=1;i<=n;i++) a[i]=get();
	build(1,1,n);
	for (int i=1;i<=q;i++)
	{
		int l=read(),r=read(),op=read();
		Sort(l,r,op);
	}
	out(1,1,n);

	return 0;
}