#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

#define inc orzfizzydavid
#define dec wxhtxdy

const int maxn=200111;

struct frac
{
	LL a,b;// equals to \frac{a}{b}
	double eval(){return 1.0*a/b;}
	frac(LL k1=0,LL k2=1){a=k1;b=k2;}
	bool operator <(const frac&t)const{return a*(t.b)<b*(t.a);}
};

int p[maxn],l[maxn],n,t,q,a[maxn];
set<pair<frac,int> >inc,dec;

double ans;int tot;
void add_all(int x)
{
	if(a[x]<l[x])inc.insert(mp(frac(p[x]*l[x],(LL)(l[x]+a[x])*(l[x]+a[x]+1)),x));
	if(a[x])dec.insert(mp(frac(p[x]*l[x],(LL)(l[x]+a[x])*(l[x]+a[x]-1)),x));
}
void del_all(int x)
{
	if(a[x]<l[x])inc.erase(mp(frac(p[x]*l[x],(LL)(l[x]+a[x])*(l[x]+a[x]+1)),x));
	if(a[x])dec.erase(mp(frac(p[x]*l[x],(LL)(l[x]+a[x])*(l[x]+a[x]-1)),x));
}

inline double getv(int x){return 1.0*p[x]*a[x]/(l[x]+a[x]);}

void modify(int x,int v)
{
	del_all(x);
	ans-=getv(x);
	l[x]+=v;
	if(a[x])
	{
		a[x]--;tot--;
		ans+=getv(x);
	}
	
	if(dec.size())
	{
		int val=dec.begin()->ss;
		del_all(val);
		ans-=getv(val);
		a[val]--;
		ans+=getv(val);
		add_all(val);
		tot--;
	}
	
	add_all(x);
	while(inc.size()&&tot<t)
	{
		int val=inc.rbegin()->ss;
		tot++;
		del_all(val);
		ans-=getv(val);
		a[val]++;
		add_all(val);
		ans+=getv(val);
	}
	
	add_all(x);
}

int main()
{
	scanf("%d%d%d",&n,&t,&q);
	for(int i=1;i<=n;i++)scanf("%d",p+i);
	for(int i=1;i<=n;i++)scanf("%d",l+i);
	
	for(int i=1;i<=n;i++)add_all(i);
	
	while(inc.size()&&tot<t)
	{
		int val=inc.rbegin()->ss;
		tot++;
		del_all(val);
		a[val]++;
		add_all(val);
	}
	
	for(int i=1;i<=n;i++)ans+=1.0*p[i]*a[i]/(l[i]+a[i]);
	
//	printf("%.10lf\n",ans);
	for(int i=1,tp,x;i<=q;i++)
	{
		scanf("%d%d",&tp,&x);
		if(tp==1)modify(x,1);
		else modify(x,-1);
		printf("%.10lf\n",ans);
	}
	
	return 0;
}