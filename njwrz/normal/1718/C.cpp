#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
#define int long long
#define ll long long
#define lb long double
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int a[200005],n,q;
int d[200005],len;
V<int> val[200005];
multiset<ll> s[200005];

void read(int &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}

ll query(){
	ll re=0;
	FOR(i,1,len){
		ll now=*s[i].rbegin();
		gmax(re,now*d[i]);
	}
	RE re;
}
int td[200005],tl;
void solve(){
	read(n);read(q);
//	n=166320;q=200000;
	rep(i,0,n)read(a[i]);
//	rep(i,0,n)a[i]=10;
	len=0;tl=0;
	rep(i,1,n)if(n%i==0)td[++tl]=i;
	FOR(i,1,tl){
		bool f=0;
		FOR(j,i+1,tl)if(td[j]%td[i]==0){
			f=1;break;
		}
		if(!f)d[++len]=td[i];
	}
	FOR(t,1,len){
		val[t].clear();
		s[t].clear();
		rep(i,0,d[t]){
			val[t].PB(0);
			for(int j=i;j<n;j+=d[t]){
				val[t][i]+=a[j];
			}
			s[t].emplace(val[t][i]);
		}
	}
	write(query());putchar('\n');
	FOR(_,1,q){
		int x,y;
//		x=1;y=10;
		read(x);read(y);
		x--;
		FOR(t,1,len){
			int now=x%d[t];
			s[t].erase(s[t].lwb(val[t][now]));
			val[t][now]-=a[x];
			val[t][now]+=y;
			s[t].emplace(val[t][now]);
		}
		a[x]=y;
		write(query());putchar('\n');
	}
}
signed main(){
	int T;
	read(T);
	while(T--)solve();
	RE 0;
}