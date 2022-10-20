#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=55;

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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
void output(__int128 x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else output(x/10),putchar(x%10+'0');
}
int sum[N*3],len[4],c[N];
namespace sgt
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	int t[N*3*4],tag[N*3*4];
	void update(int w,int x)
	{
		t[w]+=x;
		tag[w]+=x;
	}
	void push_down(int w)
	{
		if (!tag[w]) return;
		update(ls,tag[w]);
		update(rs,tag[w]);
		tag[w]=0;
	}
	void build(int w,int l,int r)
	{
		if (l==r) return void(t[w]=sum[l]);
		build(ls,l,mid);
		build(rs,mid+1,r);
		t[w]=min(t[ls],t[rs]);
	}
	void add(int w,int l,int r,int ql,int qr,int x)
	{
		if (qr<l||r<ql) return;
		if (ql<=l&&r<=qr) return update(w,x);
		push_down(w);
		add(ls,l,mid,ql,qr,x);
		add(rs,mid+1,r,ql,qr,x);
		t[w]=min(t[ls],t[rs]);
	}
//	void output(int w,int l,int r)
//	{
//		if (l==r) return print(t[w]);
//		push_down(w);
//		output(ls,l,mid);
//		output(rs,mid+1,r);
//	}
	#undef mid
	#undef rs
	#undef ls
}
signed a[N],b[N],p[N];

signed main()
{
//	freopen("tryagain.in","r",stdin);
//	freopen("tryagain.out","w",stdout);
	
	int n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=a[i+n]=read();
	for (int i=1;i<=n;i++) b[i]=b[i+n]=read();
	if (n&1) n*=2,m/=2;
	int cnt=1,tmp=m-(len[1]=1);
	if (tmp>1) tmp-=len[++cnt]=tmp-1;
	if (tmp) tmp-=len[++cnt]=1;
//	int cnt=m;
//	for (int i=1;i<=m;i++) len[i]=1;
	for (int i=1,k=1;i<=cnt;i++)
	{
		sum[k]+=(len[i]-1)*n;
		for (int j=1;j<=n;j++,k++) sum[k]+=sum[k-1]+1;
	}
	sgt::build(1,1,n*cnt);
	for (int i=1;i<=n;i++) p[i]=i;
	sort(p+1,p+1+n,[&](int x,int y){return b[x]-a[x]<b[y]-a[y];});
	int sum=0;
	for (int t=1;t<=n;t++)
	{
		int now=p[t];
		for (int i=cnt;i>=1;i--)
		if (sum+len[i]<=n*m/2)
		{
//			print(len[i],','),print(sum);
			sgt::add(1,1,n*cnt,1+(i-1)*n,n*cnt,-2*(len[i]-1));
			sgt::add(1,1,n*cnt,now+(i-1)*n,n*cnt,-2);
//			sgt::output(1,1,n*cnt);
			if (sgt::t[1]<0)
			{
				sgt::add(1,1,n*cnt,1+(i-1)*n,n*cnt,2*(len[i]-1));
				sgt::add(1,1,n*cnt,now+(i-1)*n,n*cnt,2);
				break;
			}
			c[now]+=len[i];
			if ((sum+=len[i])>=n*m/2) break;
		}
		else break;
//		print(now,' '),print(sum);
		if (sum>=n*m/2) break;
	}
	if (sum>n*m/2) puts(">");
	if (sum<n*m/2) puts("<");
//	for (int i=1;i<=n;i++) print(c[i]," \n"[i==n]);
//	print(sum);
	__int128 ans=0;
	for (int i=1;i<=n;i++) ans+=c[i]*b[i]+(m-c[i])*a[i];
	output(ans);
	
	return 0;
}