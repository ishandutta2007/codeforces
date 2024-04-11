#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct point
{
	double x,y;
	double operator *(point a){return x*a.y-y*a.x;}
	point operator -(point a){return (point){x-a.x,y-a.y};}
	bool operator <(const point &a)const
	{
		return x!=a.x?x<a.x:y<a.y;
	}
}st1[N],st2[N];
int top1=0,top2=0;
struct segment2{double l,r,y;}a[N];
struct segment{double l,r;};
double b[N*N];
int cnt=0,c[N*N];

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i].l=read(),a[i].r=read(),a[i].y=read();
	sort(a+1,a+1+n,[&](segment2 a,segment2 b){
		return a.y>b.y;
	});
	vector<segment>s;
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++)
	if (a[i].y!=a[j].y)
	{
		double A=(a[j].l-a[i].r)/(a[i].y-a[j].y);
		double B=(a[j].r-a[i].l)/(a[i].y-a[j].y);
		s.push_back({A,B});
		b[++cnt]=A,b[++cnt]=B;
	}
	b[++cnt]=0;
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	for (auto [l,r]:s)
	{
		int L=lower_bound(b+1,b+1+cnt,l)-b;
		int R=lower_bound(b+1,b+1+cnt,r)-b;
		if (L<R) c[L+1]++,c[R]--;
	}
	for (int i=1;i<=cnt;i++) c[i]+=c[i-1];
	
	vector<point>A,B;
	for (int i=1;i<=n;i++) A.push_back((point){a[i].y,a[i].r});
	sort(A.begin(),A.end());
	for (point i:A)
	{
		while (top1>1&&(i-st1[top1-1])*(st1[top1]-st1[top1-1])<0) top1--;
		st1[++top1]=i;
	}
	for (int i=1;i<=n;i++) B.push_back((point){a[i].y,a[i].l});
	sort(B.begin(),B.end());
	for (point i:B)
	{
		while (top2>1&&(i-st2[top2-1])*(st2[top2]-st2[top2-1])>0) top2--;
		st2[++top2]=i;
	}
	
	double ans=1e18;
	for (int i=1,u=1,v=top2;i<=cnt;i++)
	if (!c[i])
	{
		double k=b[i];
		while (u<top1&&st1[u].x*k+st1[u].y<st1[u+1].x*k+st1[u+1].y) u++;
		while (v>1&&st2[v].x*k+st2[v].y>st2[v-1].x*k+st2[v-1].y) v--;
		ans=min(ans,(st1[u].x*k+st1[u].y)-(st2[v].x*k+st2[v].y));
	}
	printf("%.10lf\n",ans);
	
	return 0;
}