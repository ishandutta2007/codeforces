#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int mod = 1e9+7;
ll Qpow(ll a,ll p)
{
	ll res=1;
	while(p){if(p&1)res=res*a%mod;a=a*a%mod,p>>=1;}
	return res;
}
struct Mint
{
	int x;
	Mint(){x=0;}
	Mint(ll y){x=(0<=y&&y<mod?y:(y%mod+mod)%mod);}
	void operator+= (Mint a){x+=a.x;if(x>=mod)x-=mod;}
	void operator-= (Mint a){x-=a.x;if(x<0)x+=mod;}
	void operator*= (Mint a){x=ll(x)*a.x%mod;}
	Mint operator- (){return x?mod-x:0;}
	Mint operator++ (){return x+1==mod?0:x+1;}
};
Mint operator+ (Mint a,Mint b){int t=a.x+b.x;return t<mod?t:t-mod;}
Mint operator- (Mint a,Mint b){int t=a.x-b.x;return t>=0?t:t+mod;}
Mint operator* (Mint a,Mint b){return ll(a.x)*b.x%mod;}

const int MAXN = 400011;
std::vector<int>seq[MAXN];
int a[MAXN],stkv[MAXN],stkp[MAXN],n;
pii ord[MAXN];
struct BIT
{
#define lowb (i&-i)
	Mint t[MAXN];
	void clear()
	{
		for(int i=1;i<=n;++i)t[i]=0;
	}
	void modify(int i,Mint k)
	{
		while(i<=n)t[i]+=k,i+=lowb;
	}
	Mint Qsum(int i)
	{
		Mint res=0;
		while(i)res+=t[i],i-=lowb;
		return res;
	}
}bt;
Mint pref[MAXN],suff[MAXN],now[MAXN];
bool ins[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		//clear !!!!!!!
		n=read();
		for(int i=1;i<=n;++i)seq[i].clear(),ins[i]=0;
		for(int i=1;i<=n;++i)ord[i].first=read(),ord[i].second=-i;
		std::sort(ord+1,ord+n+1);
		for(int i=1;i<=n;++i)a[-ord[i].second]=i;
		bt.clear();
		for(int i=1;i<=n;++i)
		{
			pref[i]=bt.Qsum(a[i])+1;
			bt.modify(a[i],pref[i]);
		}
		bt.clear();
		for(int i=n;i;--i)
		{
			suff[i]=bt.Qsum(n-a[i]+1)+1;
			bt.modify(n-a[i]+1,suff[i]);
		}
		bt.clear();
		int sufmax=0,top=0;
		for(int i=n;i;--i)
			if(umax(sufmax,a[i]))++top,stkv[top]=a[i],stkp[top]=i,ins[i]=1;
		for(int i=n;i;--i)
		{
			if(ins[i])continue;
			int p=std::lower_bound(stkv+1,stkv+top+1,a[i])-stkv;
			seq[p].emplace_back(i);
		}
		Mint ans=0;
		for(int i=1;i<=top;++i)
		{
			int r=stkp[i];
			//printf("r=%d,a[r]=%d\n",r,a[r]);
			bt.modify(n-a[r]+1,1);
			for(auto j:seq[i])
			{
				now[j]=bt.Qsum(n-a[j]+1);
				//printf("Now[%d]=%d\n",j,now[j].x);
				ans+=pref[j]*(suff[j]-now[j]);
				bt.modify(n-a[j]+1,now[j]);
			}
			bt.modify(n-a[r]+1,-1);
			for(auto j:seq[i])bt.modify(n-a[j]+1,-now[j]);
		}
		printf("%d\n",ans.x);
	}
	return 0;
}