#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
struct node
{
	int x,y;
	bool operator <(const node &a)const
	{
		return y<a.y;
	}
}a[N],b[N];
bool cmpx(node a,node b)
{
	return a.x<b.x;
}
int l[N*2],r[N*2];
ll solve(node *a,int n)
{
	ll ret=0;
	for (int i=1;i<=n;i++)
	{
		int tmpx=(a[i].y+a[i].x)/2;
		int tmpy=(a[i].y-a[i].x)/2;
		a[i].x=tmpx;
		a[i].y=tmpy;
//		print(tmpx,',');
//		print(tmpy);
	}
	sort(a+1,a+1+n);
	for (int i=-100000,L=1919810,R=-1919810,j=1;i<=100001;i++)
	{
		l[i+N]=L;
		r[i+N]=R;
		while (j<=n&&a[j].y==i)
		{
			L=min(L,a[j].x);
			R=max(R,a[j].x);
			j++;
		}
	}
	for (int i=100001,L=1919810,R=-1919810,j=n;i>=-100000;i--)
	{
		while (j>=1&&a[j].y==i)
		{
			L=min(L,a[j].x);
			R=max(R,a[j].x);
			j--;
		}
		l[i+N]=max(l[i+N],L);
		r[i+N]=min(r[i+N],R);
		ret+=max(r[i+N]-l[i+N],0);
//		if (r[i+N]-l[i+N]>0) print(l[i+N],' '),print(r[i+N]);
	}
	return ret;
}

signed main()
{
	int n=read(),cnt1=0,cnt2=0;
	for (int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		if ((x+y)%2==0) a[++cnt1]=(node){x,y};
				   else b[++cnt2]=(node){x+1,y};
	}
	print(solve(a,cnt1)+solve(b,cnt2));
	
	return 0;
}