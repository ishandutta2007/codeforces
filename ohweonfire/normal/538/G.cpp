// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=200111;
const int maxl=2000111;
void nosol()
{
	puts("NO");
	exit(0);
}

int n,l;
LL t[maxn];

inline LL div_down(LL a,LL b)
{
	if(a>=0)return (a/b);
	else return -((-a+b-1)/b);
}

void calc(LL a,LL b,LL l,LL r,LL&lb,LL&rb)//l <= ax+b <= r
{
	l-=b;r-=b;
	if(a==0)
	{
		if(l>0||r<0)lb=l+1;
		return;
	}
	// l <= ax <= r
	if(a<0)
	{
		l=-l;r=-r;swap(l,r);
		a=-a;
	}
	// up(l/a) <= x <= down(r/a)
	lb=max(lb,div_down(l+a-1,a));
	rb=min(rb,div_down(r,a));
}

int lim[maxl];

void solve(LL*x,int*ans)
{
	vector<pair<int,pair<LL,LL> > >vs;
	vs.pb(mp(l,mp(1,0)));
	vs.pb(mp(0,mp(0,0)));
	for(int i=1;i<=n;i++)
	{
		if(x[i]<-t[i]||x[i]>t[i])nosol();
		x[i]+=t[i];if(x[i]%2==1)nosol();
		x[i]/=2;
//		printf("i= %d x= %lld\n",i,x[i]);
		vs.pb(mp(t[i]%l,mp(-(t[i]/l),x[i])));
	}
	sort(vs.begin(),vs.end());
	LL lb=0,rb=l;
	for(int i=0;i<(int)vs.size()-1;i++)
	{
		calc(vs[i+1].ss.ff-vs[i].ss.ff,vs[i+1].ss.ss-vs[i].ss.ss,0,vs[i+1].ff-vs[i].ff,lb,rb);
		if(lb>rb)nosol();
	}
	memset(lim,inf,sizeof(lim));
	for(int i=0;i<(int)vs.size();i++)
	{
		int val=vs[i].ss.ff*lb+vs[i].ss.ss;
		lim[vs[i].ff]=min(lim[vs[i].ff],val);
	}
	for(int i=l-1;i>=1;i--)if(lim[i]==inf)lim[i]=lim[i+1];
	int sum=0;
	for(int i=1;i<=l;i++)
	{
		ans[i]=-1;
		if(sum<lim[i])
		{
			ans[i]=1;
			sum++;
		}
	}
}
LL x[maxn],y[maxn];
int ansx[maxl],ansy[maxl];

int main()
{
	get2(n,l);
	for(int i=1;i<=n;i++)
	{
		get3(t[i],x[i],y[i]);
		x[i]+=y[i];
		y[i]=x[i]-y[i]-y[i];
	}
	
	solve(x,ansx);
	solve(y,ansy);
	
	for(int i=1;i<=l;i++)
	{
		if(ansx[i]==1&&ansy[i]==1)putchar('R');
		else if(ansx[i]==-1&&ansy[i]==1)putchar('D');
		else if(ansx[i]==-1&&ansy[i]==-1)putchar('L');
		else putchar('U');
	}
	puts("");
	
	return 0;
}