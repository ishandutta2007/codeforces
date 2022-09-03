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

const int mod=998244353;

int n;map<LL,int> cnt,cnt2;

bool p[1300111];
int pr[1000111],tot;

LL a[555];

bool fac(LL&x)
{
	bool ret=0;
	for(int i=1;i<=tot;i++)
	{
		while(x%pr[i]==0)
		{
			cnt[pr[i]]++;
			x/=pr[i];
			ret=1;
		}
	}
	return ret;
}
int main()
{
	for(int i=2;i<1300111;i++)p[i]=1;
	for(int i=2;i<1300111;i++)if(p[i])
	{
		pr[++tot]=i;
		for(int j=i+i;j<1300111;j+=i)p[j]=0;
	}
	
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get1(a[i]);
		if(fac(a[i]))
		{
			if(a[i]>1)cnt[a[i]]++;
			a[i]=1;
		}
		if(a[i]>1)
		{
			LL tmp=sqrt(a[i])+0.5;
			if(tmp*tmp==a[i])
			{
				cnt[tmp]+=2;
				a[i]=1;
			}
			
		}
	}
	
	vector<LL>pp;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(a[i]>1&&a[j]>1&&a[i]!=a[j]&&__gcd(a[i],a[j])>1)
	{
		LL g=__gcd(a[i],a[j]);
		pp.pb(__gcd(a[i],a[j]));
		pp.pb(a[i]/g);
		pp.pb(a[j]/g);
	}
	sort(pp.begin(),pp.end());pp.erase(unique(pp.begin(),pp.end()),pp.end());
	for(int i=1;i<=n;i++)
	{
		for(auto&p:pp)if(a[i]%p==0)
		{
			cnt[p]++;
			cnt[a[i]/p]++;
			a[i]=1;
		}
		for(auto&p:cnt)if(a[i]%p.ff==0)
		{
			cnt[p.ff]++;
			cnt[a[i]/p.ff]++;
			a[i]=1;
		}
		if(a[i]>1)cnt2[a[i]]++;
	}
	
	int ans=1;
	for(auto&v:cnt)ans=(LL)ans*(v.ss+1)%mod;
	for(auto&v:cnt2)ans=(LL)ans*(v.ss+1)*(v.ss+1)%mod;
	printendl(ans);
	return 0;
}