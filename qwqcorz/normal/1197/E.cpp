#include<bits/stdc++.h>
#define mk make_pair
#define x first
#define y second
#define int long long
using namespace std;
const int N=2e5+5;
const int p=1e9+7;
const int inf=1ll<<60;

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
void add(int &x,int y)
{
	x+=y;
	if (x>=p) x-=p;
}
struct node
{
	int in,out;
	bool operator <(const node &a)const
	{
		return out==a.out?in<a.in:out<a.out;
	}
}a[N];
int f[N],g[N],Min[N];
map<int,vector<pair<int,int> > >sum;

signed main()
{
	memset(Min,0x3f,sizeof(Min));
	int n=read(),Max=0,ans=0,fans=inf;
	for (int i=1;i<=n;i++)
	{
		a[i].out=read();
		Max=max(Max,a[i].in=read());
	}
	sort(a+1,a+1+n);
	a[0].in=a[0].out=Min[0]=f[0]=0;
	g[0]=1;
	sum[0].push_back(mk(0,1));
	for (int i=1;i<=n;i++)
	{
//		print(a[i].in,' ');
//		print(a[i].out,':');
		f[i]=Min[upper_bound(a+1,a+i,(node){inf,a[i].in})-a-1]+a[i].in;
//		print(upper_bound(a+1,a+i,(node){0,a[i].in})-a-1);
		Min[i]=min(Min[i-1],f[i]-a[i].out);
		int pos=upper_bound(sum[f[i]-a[i].in].begin(),sum[f[i]-a[i].in].end(),mk(a[i].in,inf))-sum[f[i]-a[i].in].begin()-1;
		if (pos>=0) g[i]=sum[f[i]-a[i].in][pos].y;
		int Add=sum[f[i]-a[i].out].size()?sum[f[i]-a[i].out][sum[f[i]-a[i].out].size()-1].y:0;
		sum[f[i]-a[i].out].push_back(mk(a[i].out,(Add+g[i])%p));
		if (a[i].out>Max) fans=min(fans,f[i]);
//		print(f[i],' ');
//		print(g[i]);
	}
	for (int i=1;i<=n;i++) if (f[i]==fans&&a[i].out>Max) add(ans,g[i]);
	print(ans);

	return 0;
}