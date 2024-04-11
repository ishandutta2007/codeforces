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
	#define sz 233
	typedef long long ll;
	typedef double db;
	mt19937 rng(2333);
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

//string sss[sz];

int n,B;
char s[sz];
int cur=-1;

int query(int x)
{
//	rep(i,0,B-1) if (s[i]!=sss[x][i]) return s[i]<sss[x][i];
//	return 0;
	printf("%d %s\n",x,s);fflush(stdout);
	static char ss[5];cin>>ss;
	return ss[0]=='y';
}

int main()
{
//	file();
	read(n,B);
//	rep(i,1,n) { sss[i].resize(B); rep(k,0,B-1) sss[i][k]=rnd('0','1'); }
	vector<int>V; rep(i,1,n) V.push_back(i);
	while (cur!=B-1)
	{
		stack<int>st;
		for (auto x:V)
		{
			while (st.size())
			{
				int k=cur+st.size(); chkmin(k,B-1);
				rep(i,k+1,B-1) s[i]='1';
				if (query(x)) st.pop(); else break;
			}
			int k=cur+st.size(); chkmin(k,B-1);
			if (k==B-1) { st.push(x); continue; }
			s[k+1]='0'; rep(i,k+2,B-1) s[i]='1';
			if (query(x)) s[k+1]='1'; else s[k+1]='0';
			st.push(x);
		}
		int m=cur+st.size(); chkmin(m,B-1);
		vector<int>VV; VV.push_back(st.top()); st.pop();
		while (st.size())
		{
			int x=st.top(); st.pop();// cout<<"! "<<sss[x]<<'\n';
			rep(i,m+1,B-1) s[i]='1';
			if (query(x)) VV.clear(),m=cur+st.size()+1; VV.push_back(x);
			chkmin(m,B-1);
		}
		cur=m,V=VV;
	}
//	string mx=sss[1]; rep(i,2,n) chkmax(mx,sss[i]);
//	rep(i,0,B-1) assert(mx[i]==s[i]);
//	cout<<mx<<'\n'<<s;
	printf("0 %s\n",s);fflush(stdout);
	return 0;
}