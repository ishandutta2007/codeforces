#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

const int mod=1e9+7;
int qpow(int x,int y)
{
	int ret=1;
	while(y)
	{
		if(y&1)ret=(LL)ret*x%mod;
		x=(LL)x*x%mod;
		y>>=1;
	}
	return ret;
}

vector<int>ps;
void decomp(int x)
{
	for(int i=2;i*i<=x;i++)if(x%i==0)
	{
		ps.pb(i);
		while(x%i==0)x/=i;
	}
	if(x>1)ps.pb(x);
}

struct Geo_prog
{
	vector<int>ca,cb;
	bool is_constant()
	{
		for(int i=0;i<(int)cb.size();i++)if(cb[i])return false;
		return true;
	}
	void setv(int a,int b)
	{
		ca.clear();cb.clear();
		for(int i=0;i<(int)ps.size();i++)
		{
			int cnt;
			cnt=0;while(a%ps[i]==0){cnt++;a/=ps[i];}ca.pb(cnt);
			cnt=0;while(b%ps[i]==0){cnt++;b/=ps[i];}cb.pb(cnt);
		}
	}
	int calcv(LL val=0)
	{
		int ret=1;
		for(int i=0;i<(int)ps.size();i++)ret=(LL)ret*qpow(ps[i],(ca[i]+cb[i]*val)%(mod-1))%mod;
		return ret;
	}
	void set_const(LL val)
	{
		for(int i=0;i<(int)ps.size();i++)
		{
			ca[i]+=cb[i]*val;
			cb[i]=0;
		}
	}
};

const int maxn=111;
int n,a[maxn],b[maxn];
Geo_prog p[maxn];

bool check(Geo_prog x,Geo_prog y)
{
	int candidate=-1;
	for(int i=0;i<(int)ps.size();i++)
	{
		if(y.ca[i]>x.ca[i]||(y.cb[i]==0&&y.ca[i]!=x.ca[i])||(y.cb[i]&&(x.ca[i]-y.ca[i])%y.cb[i]))return false;
		if(y.cb[i])
		{
			int now=(x.ca[i]-y.ca[i])/y.cb[i];
			if(candidate!=-1&&now!=candidate)return false;
			candidate=now;
		}
	}
	return true;
}
void check(Geo_prog x,int coef=1)
{
	assert(x.is_constant());
	for(int i=1;i<=n;i++)if(!check(x,p[i]))
	{
		puts("-1");
		exit(0);
	}
	printf("%d\n",(LL)x.calcv()*coef%mod);
	exit(0);
}

bool ok[maxn];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",a+i,b+i);
		decomp(a[i]);
		decomp(b[i]);
	}
	sort(ps.begin(),ps.end());ps.erase(unique(ps.begin(),ps.end()),ps.end());
	if((int)ps.size()==0)
	{
		puts("1");
		return 0;
	}
	
	for(int i=1;i<=n;i++)p[i].setv(a[i],b[i]);
	
	int coef=1;
	for(int j=0;j<(int)ps.size();j++)for(int i=1;i<=n;i++)if(p[i].cb[j]==0)
	{
		for(int k=1;k<=n;k++)if(p[k].cb[j])
		{
			if(p[k].ca[j]>p[i].ca[j]||(p[i].ca[j]-p[k].ca[j])%p[k].cb[j])
			{
				puts("-1");
				return 0;
			}
			int v=(p[i].ca[j]-p[k].ca[j])/p[k].cb[j];
			p[k].set_const(v);
			check(p[k]);
		}
		for(int k=1;k<=n;k++)if(p[k].ca[j]!=p[i].ca[j])
		{
			puts("-1");
			return 0;
		}
		coef=(LL)coef*qpow(ps[j],p[i].ca[j])%mod;
		ok[j]=1;
		break;
	}
	
	vector<int> nps;
	for(int i=(int)ps.size()-1;i>=0;i--)if(!ok[i])nps.pb(ps[i]);ps=nps;
	for(int j=1;j<=n;j++)
	{
		vector<int>nca,ncb;
		for(int i=(int)p[j].ca.size()-1;i>=0;i--)if(!ok[i])
		{
			nca.pb(p[j].ca[i]);
			ncb.pb(p[j].cb[i]);
		}
		p[j].ca=nca;p[j].cb=ncb;
	}
	if((int)ps.size()==0)
	{
		printf("%d\n",coef);
		return 0;
	}
	for(int i=1;i<(int)ps.size();i++)for(int j=2;j<=n;j++)
	{
		// k1 * p[1].cb[0] + k2 * p[j].cb[0] = p[j].ca[0] - p[1].ca[0]
		// k1 * p[1].cb[i] + k2 * p[j].cb[i] = p[j].ca[i] - p[1].ca[i]
		int det1=(p[1].cb[0]*p[j].cb[i]-p[1].cb[i]*p[j].cb[0]);
		int det2=-(p[j].cb[0]*(p[j].ca[i]-p[1].ca[i])-p[j].cb[i]*(p[j].ca[0]-p[1].ca[0]));
		if(det1)
		{
			if(det1<0&&det2<0)
			{
				det1=-det1;
				det2=-det2;
			}
			if(det2<0||det2%det1)
			{
				puts("-1");
				return 0;
			}
			p[1].set_const(det2/det1);
			check(p[1],coef);
		}
		else if(det2)
		{
			puts("-1");
			return 0;
		}
	}
	LL cand=0,cur=1;
	for(int i=1;i<=n;i++)
	{
		if((cand-p[i].ca[0])%__gcd(cur,(LL)p[i].cb[0]))
		{
			puts("-1");
			return 0;
		}
		while(cand<p[i].ca[0]||(cand-p[i].ca[0])%p[i].cb[0])cand+=cur;
		cur=cur/__gcd(cur,(LL)p[i].cb[0])*p[i].cb[0];
	}
	printf("%d\n",(LL)p[1].calcv((cand-p[1].ca[0])/p[1].cb[0])*coef%mod);
	return 0;
}