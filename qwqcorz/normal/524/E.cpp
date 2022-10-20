#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int LOG=20;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct point{int x,y;}a[N],b[N];
struct hjtree
{
	#define mid ((l+r)/2)
	struct node{int mn,ls,rs;}t[N*LOG];
	int rt[N],cnt;
	int change(int w,int l,int r,int x,int y)
	{
		int now=++cnt; t[now]=t[w]; 
		if (l==r) return t[now].mn=y,now;
		if (x<=mid) t[now].ls=change(t[w].ls,l,mid,x,y);
			   else t[now].rs=change(t[w].rs,mid+1,r,x,y);
		t[now].mn=min(t[t[now].ls].mn,t[t[now].rs].mn);
		return now;
	}
	int query(int w,int l,int r,int ql,int qr)
	{
		if (ql<=l&&r<=qr) return t[w].mn;
		if (qr<=mid) return query(t[w].ls,l,mid,ql,qr);
		if (ql>mid) return query(t[w].rs,mid+1,r,ql,qr);
		return min(query(t[w].ls,l,mid,ql,qr),query(t[w].rs,mid+1,r,ql,qr));
	}
	#undef mid
}tx,ty;
bool Query(int k,int n,int m,int x1,int y1,int x2,int y2)
{
    auto cmpx=[&](point u,point v){return u.x<v.x;};
    auto cmpy=[&](point u,point v){return u.y<v.y;};
	int L=lower_bound(a+1,a+1+k,(point){x1,0},cmpx)-a;
	int R=upper_bound(a+1,a+1+k,(point){x2,0},cmpx)-a-1;
	if (tx.query(tx.rt[R],1,m,y1,y2)>=L) return 1;
	L=lower_bound(b+1,b+1+k,(point){0,y1},cmpy)-b;
	R=upper_bound(b+1,b+1+k,(point){0,y2},cmpy)-b-1;
	if (ty.query(ty.rt[R],1,n,x1,x2)>=L) return 1;
	return 0;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
    auto cmpx=[&](point u,point v){return u.x<v.x;};
    auto cmpy=[&](point u,point v){return u.y<v.y;};
	int n=read(),m=read(),k=read(),q=read();
	for (int i=1;i<=k;i++) b[i].x=a[i].x=read(),b[i].y=a[i].y=read();
	sort(a+1,a+1+k,cmpx);
	sort(b+1,b+1+k,cmpy);
	for (int i=1;i<=k;i++) tx.rt[i]=tx.change(tx.rt[i-1],1,m,a[i].y,i);
	for (int i=1;i<=k;i++) ty.rt[i]=ty.change(ty.rt[i-1],1,n,b[i].x,i);
	for (int i=1;i<=q;i++)
	{
		int x1=read(),y1=read(),x2=read(),y2=read();
		puts(Query(k,n,m,x1,y1,x2,y2)?"YES":"NO");
	}
	
	return 0;
}