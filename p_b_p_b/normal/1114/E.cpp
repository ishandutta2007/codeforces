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
	#define sz 6600000
	typedef long long ll;
	template<typename T>
	inline void read(T& t)
	{
		t=0;char f=0,ch=getchar();
		double d=0.1;
		while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
		while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
		if(ch=='.')
		{
			ch=getchar();
			while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();
		}
		t=(f?-t:t);
	}
	template<typename T,typename... Args>
	inline void read(T& t,Args&... args){read(t); read(args...);}
	void file()
	{
		#ifndef ONLINE_JUDGE
		freopen("a.txt","r",stdin);
		#endif
	}
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int gcd(int x,int y){return y?gcd(y,x%y):x;}

int n;
bool vis[sz];
const int B=30;
int D;
int t[sz];
int remain=60;

int main()
{
//	file();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	#define rnd() (uniform_int_distribution<int>(1,n)(rng))
	read(n);
	int l=0,r=1e9,MX=0,c;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		printf("> %d\n",mid);fflush(stdout);
		read(c);
		if (c) l=mid+1;
		else MX=mid,r=mid-1;
		--remain;
	}
	printf("? 1\n");fflush(stdout);
	read(t[1]);vis[1]=1;
	printf("? 2\n");fflush(stdout);
	read(t[2]);vis[2]=1;
	D=abs(t[1]-t[2]);
	rep(i,3,min(n,remain))
	{
		int x=rnd();
		while (vis[x]) x=rnd();
		printf("? %d\n",x);fflush(stdout);
		read(t[i]);vis[x]=1;
		rep(j,1,i-1) D=gcd(D,abs(t[i]-t[j]));
	}
	printf("! %I64d %d",MX-1ll*(n-1)*D,D); fflush(stdout);
	return 0;//
}