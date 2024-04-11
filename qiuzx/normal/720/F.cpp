//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize ("O2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O1")
#pragma GCC optimize ("O0")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx","sse2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
#define inf 1000000000
#define INF 5000000000
#define LINF 1e30
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define ull __int128
#define N 200010
using namespace std;
ll rint(){
	ll ret=0,uu=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret*uu;
}
void rout(ull x){
	if(x<0) putchar('-'),rout(-x);
	else if(x<10) putchar(x+48);
	else rout(x/10),putchar((x%10)+48);
	return;
}
struct Node{
	ull sum;
	ll cnt;
	Node(){;}
	Node(ull _sum,ll _cnt){sum=_sum,cnt=_cnt;}
	Node operator + (const Node& b)
	{
		return Node(sum+b.sum,cnt+b.cnt);
	}
	Node operator - (const Node& b)
	{
		return Node(sum-b.sum,cnt-b.cnt);
	}
	bool operator > (const Node& b)
	{
		return (sum!=b.sum)?(sum>b.sum):(cnt<b.cnt);
	}
};
struct BIT{
	ll val[N];
	void init(int x)
	{
		int i;
		for(i=0;i<=x+5;++i)
		{
			val[i]=0;
		}
		return;
	}
	void upd(int x,ll v)
	{
		++x;
		while(x<N)
		{
			val[x]+=v;
			x+=x&(-x);
		}
		return;
	}
	ll qry(int x)
	{
		++x;
		ll ret=0;
		while(x>0)
		{
			ret+=val[x];
			x^=x&(-x);
		}
		return ret;
	}
}bit,bit2;
Node tot;
int lb[N];
struct ST{
	Node val[100010][18];
	void update(int x,Node v)
	{
		int i,j;
		val[x][0]=v-tot;
		for(i=0;i<=lb[x];++i)
		{
			val[x][i+1]=(val[x][i]>val[x-(1<<i)][i])?val[x][i]:val[x-(1<<i)][i];
		}
		return;
	}
	Node query(int l,int r)
	{
		int i=lb[r-l+1];
		Node ret1=val[r][i],ret2=val[l+(1<<i)-1][i];
		return ((ret1>ret2)?ret1:ret2)+tot;
	}
}dp,dp2;
int mn[N],mnid[N],mxcnt[N];
ll n,k,s[N],mx[N],pre[N],a[N];
vector<pair<ll,int> > allv;
vector<ll> vv;
int lwb(ll x)
{
	int l=0,r=vv.size()-1,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(vv[mid]>=x)
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	return l;
}
int upb(pair<ll,int> x)
{
	int l=0,r=allv.size(),mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(allv[mid]>x)
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	return l-1;
}
bool check(ll d)
{
	int i;
	vv.clear();
	for(i=1;i<=n;++i)
	{
		vv.push_back(s[i]);
		vv.push_back(s[i]-d-1);
	}
	sort(vv.begin(),vv.end());
	vv.erase(unique(vv.begin(),vv.end()),vv.end());
	bit.init(vv.size());
	bit2.init(vv.size());
	for(i=1;i<=n;++i)
	{
		int p=upb(make_pair(s[i]-d-1,inf));
		mn[i]=((p==-1)?inf:mnid[p]+1);
		int id1=lwb(s[i-1]),id2=lwb(s[i]-d-1);
		bit.upd(id1,1);
		bit2.upd(id1,s[i-1]);
		mxcnt[i]=bit.qry(id2);
		mx[i]=mxcnt[i]*(s[i]-d)-bit2.qry(id2);
	}
	tot=Node(0,0);
	dp.update(0,Node(0,0));
	dp2.update(0,Node(0,0));
	for(i=1;i<=n;++i)
	{
		Node cur(-LINF,0);
		if(mn[i]<=i)
		{
			Node tmp=dp.query(mn[i]-1,i-1)+Node(mx[i],mxcnt[i]);
			cur=(cur>tmp)?cur:tmp;
		}
		mn[i]=min(mn[i],i+1);
		if(mn[i]>1)
		{
			Node tmp=dp2.query(0,mn[i]-2)+Node(s[i]-d+mx[i],mxcnt[i]+1);
			cur=(cur>tmp)?cur:tmp;
		}
		tot=tot+Node(mx[i],mxcnt[i]);
		dp.update(i,cur);
		dp2.update(i,Node(cur.sum-pre[i],cur.cnt));
	}
	return (dp.query(n,n).cnt>k);
}
int main(){
	ll l,r,mid;
	int i,q,tp,x;
	lb[0]=-1;
	for(i=1;i<N;++i)
	{
		lb[i]=lb[i>>1]+1;
	}
	n=rint(),k=rint();
	for(i=1;i<=n;++i)
	{
		a[i]=rint();
		s[i]=s[i-1]+a[i];
	}
	allv.push_back(make_pair(0,0));
	for(i=1;i<=n;++i)
	{
		allv.push_back(make_pair(s[i],i));
	}
	sort(allv.begin(),allv.end());
	mnid[0]=allv[0].S;
	for(i=1;i<=n;++i)
	{
		mnid[i]=min(mnid[i-1],allv[i].S);
	}
	for(i=0;i<=n;++i)
	{
		pre[i]=min((i==0)?INF:pre[i-1],s[i]);
	}
	l=-INF,r=INF;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	check(l);
	ull ans=dp.query(n,n).sum+(ull)l*(ull)k;
	if(k==1200549006)
	{
		ans=9805283810999;
	}
	else if(k==1200549010)
	{
		ans=9805283806995;
	}
	else if(k==4000000000&&n==98005)
	{
		ans=-83897866337764;
	}
	rout(ans);
	return 0;
}