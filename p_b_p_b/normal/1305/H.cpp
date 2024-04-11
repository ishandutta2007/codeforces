#include<bits/stdc++.h>
namespace my_std{
	using namespace std;
	#define pii pair<int,int>
	#define fir first
	#define sec second
	#define MP make_pair
	#define rep(i,x,y) for (int i=(x);i<=(y);i++)
	#define drep(i,x,y) for (int i=(x);i>=(y);i--)
	#define go(x) for (int i=head[x];i;i=edge[i].nxt)
	#define templ template<typename T>
	#define sz 101010
	typedef long long ll;
	typedef double db;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	templ inline T rnd(T l,T r) {return uniform_int_distribution<T>(l,r)(rng);}
	templ inline bool chkmax(T &x,T y){return x<y?x=y,1:0;}
	templ inline bool chkmin(T &x,T y){return x>y?x=y,1:0;}
	templ inline void read(T& t)
	{
		t=0;char f=0,ch=getchar();double d=0.1;
		while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
		while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
		if(ch=='.'){ch=getchar();while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();}
		t=(f?-t:t);
	}
	template<typename T,typename... Args>inline void read(T& t,Args&... args){read(t); read(args...);}
	char __sr[1<<21],__z[20];int __C=-1,__zz=0;
	inline void Ot(){fwrite(__sr,1,__C+1,stdout),__C=-1;}
	inline void print(int x)
	{
		if(__C>1<<20)Ot();if(x<0)__sr[++__C]='-',x=-x;
		while(__z[++__zz]=x%10+48,x/=10);
		while(__sr[++__C]=__z[__zz],--__zz);__sr[++__C]='\n';
	}
	void file()
	{
		#ifdef NTFOrz
		freopen("a.in","r",stdin);
		#endif
	}
	inline void chktime()
	{
		#ifdef NTFOrz
		cerr<<clock()/1000.0<<'\n';
		#endif
	}
	#ifdef mod
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
	ll inv(ll x){return ksm(x,mod-2);}
	#else
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
	#endif
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n,m; ll T;
ll L[sz],R[sz];ll preL[sz],preR[sz];
ll pre[sz];
ll _s[sz],s[sz];
int ans1,ans2;

bool check(ll sum,ll *pre1,ll *pre)
{
	static int st[sz]; int tp=0;
	rep(j,1,n)
	{
		auto Cross=[&](int x1,ll y1,int x2,ll y2){return x1*y2-x2*y1;};
		while (tp>1&&Cross(j-st[tp],pre[j]-pre[st[tp]],j-st[tp-1],pre[j]-pre[st[tp-1]])>=0) --tp;
		st[++tp]=j;
	}
	auto clc=[&](int i,int j){return pre[j]-1ll*j*(m-i);};
	rep(i,0,m) { while (tp>1&&clc(i,st[tp])>clc(i,st[tp-1])) --tp; if (pre1[i]+1ll*n*(m-i)+clc(i,st[tp])<sum) return 0; }
	return 1;
}

bool Check(ll *w)
{
	ll _=0; rep(i,1,n) _+=w[i]; assert(_==T);
	reverse(w+1,w+n+1);
	rep(i,1,n) pre[i]=pre[i-1]+w[i];
	return check(T,preR,pre)&&check(preL[m],preL,pre); 
}

bool check(int len,int tp=1)
{
	rep(i,1,len) if (s[i]!=-1&&s[i]!=_s[1]) return 0;
	static ll w[sz]; static ll suf[sz];
	rep(i,1,n) w[i]=_s[i]; rep(i,2,len) w[i]=w[i-1];drep(i,n,1) suf[i]=suf[i+1]+w[i];
	ll res=T-suf[1]; if (res<0) return 0;
	vector<int>V; V.push_back(len); rep(i,len+1,n+1) if (s[i]!=-1) V.push_back(i);
	drep(i,(int)V.size()-2,0)
	{
		int l=V[i],r=V[i+1]; if (l==r-1) continue;
		ll t=(w[l]-w[r])*(r-l-1);
		if (t<=res) { rep(j,l+1,r-1) w[j]=w[l]; res-=t; continue; }
		t=r-l-1; ll tt=res/t; res%=t; if (tt>m) return 0;
		rep(j,l+1,r-1) w[j]+=tt+((j-l-1)<res);
		res=0; break;
	}
	if (!res) return Check(w);
	if (tp) { rep(i,1,len) if (s[i]!=-1) return 0; }
	ll dt=res/(V[1]-1); res%=V[1]-1;
	if (!res||res>=len) { rep(i,1,V[1]-1) w[i]+=dt; rep(i,1,res) ++w[i]; return Check(w); }
	rep(i,1,V[1]-1) w[i]+=dt; res=len-res;
	rep(i,0,(int)V.size()-2)
	{
		int l=V[i],r=V[i+1]; ll t=(w[l]-w[r])*(r-l-1);
		if (t<res) { rep(j,l+1,r-1) w[j]=w[r]; res-=t; continue; }
		t=r-l-1;
		rep(j,l+1,r-1) w[j]-=res/t; res%=t;
		drep(j,r-1,r-res) --w[j];
		res=0; break;
	}
	if (res) return 0;
	rep(i,1,len) w[i]++;
	return Check(w);
}
void work1(){for (int l=1,r=n,mid;(mid=(l+r)>>1,l<=r);) if (check(mid)) ans1=mid,l=mid+1; else r=mid-1;}
void work2()
{
	if (!ans1) exit(puts("-1 -1")&0);
	rep(i,1,ans1) if (s[i]!=-1) exit(printf("%d %lld\n",ans1,s[i])&0);
	for (int l=_s[1],r=m,mid;(mid=(l+r)>>1,l<=r);)
	{
		rep(i,1,ans1) _s[i]=mid;
		if (check(ans1,0)) ans2=mid,l=mid+1; else r=mid-1;
	}
	printf("%d %d\n",ans1,ans2);
}

int main()
{
	file();
	read(m,n);
	rep(i,1,m) read(L[i],R[i]); sort(L+1,L+m+1),sort(R+1,R+m+1); rep(i,1,m) preL[i]=preL[i-1]+L[i],preR[i]=preR[i-1]+R[i];
	rep(i,1,n) _s[i]=s[i]=-1;
	int x,y;
	int Q; read(Q); while (Q--) read(x,y),s[x]=_s[x]=y;
	drep(i,n,1) chkmax(_s[i],_s[i+1]);
	read(T);
	work1(),work2();
	return 0;
}