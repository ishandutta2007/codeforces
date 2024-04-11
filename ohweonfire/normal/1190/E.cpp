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
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);
const double twopi=2*pi;

const double eps=1e-10;
const int maxn=200111;

int n,m,x[maxn],y[maxn];
double dist[maxn],rd[maxn],lv[maxn],rv[maxn];

int nxt[20][maxn];
bool check(double val)
{
	vector<pair<double,double> > vs,nvs;
	double cmn=100;
	for(int i=1;i<=n;i++)
	{
		double dlt=acos(val/dist[i]);
		lv[i]=rd[i]-dlt;
		rv[i]=rd[i]+dlt;
		if(lv[i]<-pi)
		{
			lv[i]+=twopi;
			rv[i]+=twopi;
		}
		vs.pb(mp(lv[i],rv[i]));
		cmn=min(cmn,rv[i]+twopi);
	}
	sort(vs.begin(),vs.end());
	for(int i=(int)vs.size()-1;i>=0;i--)
	{
		if(vs[i].ss<cmn)
		{
			cmn=vs[i].ss;
			nvs.pb(vs[i]);
		}
	}
	vs=nvs;reverse(vs.begin(),vs.end());
	
	int tot=(int)vs.size();
	for(int i=0;i<tot;i++)vs.pb(mp(vs[i].ff+twopi,vs[i].ss+twopi));tot*=2;
	int cur=0;
	for(int i=0;i<tot;i++)
	{
		while(cur<tot&&vs[cur].ff<=vs[i].ss)cur++;
		nxt[0][i]=cur;
	}
	nxt[0][tot]=tot;
	for(int i=1;i<20;i++)for(int j=0;j<=tot;j++)nxt[i][j]=nxt[i-1][nxt[i-1][j]];
	for(int i=0;i<tot/2;i++)
	{
		cur=i;
		for(int j=0;j<20;j++)if((m>>j)&1)cur=nxt[j][cur];
		if(cur>=i+tot/2)return true;
	}
	return false;
}

int main()
{
	get2(n,m);
	
	double ub=1e100,lb=0,mid;
	
	for(int i=1;i<=n;i++)
	{
		get2(x[i],y[i]);
		if(!x[i]&&!y[i])
		{
			puts("0");
			return 0;
		}
		ub=min(ub,dist[i]=sqrt((LL)x[i]*x[i]+(LL)y[i]*y[i]));
		rd[i]=atan2(y[i],x[i]);
	}
	for(int i=0;i<50;i++)
	{
		mid=(lb+ub)*0.5;
		if(check(mid))lb=mid;
		else ub=mid;
	}
	printf("%.10lf\n",lb);/**/
	return 0;
}