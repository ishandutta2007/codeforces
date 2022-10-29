#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define inf 0x3f3f3f3f
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<long long,int> pli;
typedef double db;
// head
 
const int mod=998244353;
const int N=3e5+5;

ll powmod(ll x,ll k) {
	ll res=1;
	for (;k;k>>=1,x=x*x%mod) if (k&1) res=res*x%mod;
	return res;
}
void add(ll &a,ll b) {(a+=b)%=mod;}

int n,k,A,H;
int a[40],b[40],rk[40];
vi now,tmp;

void solve1() {
	int n=1<<k,tot=n-1;
	// puts("!!!!");
	for (int sta=0;sta<(1<<tot);sta++) {
		int cur=0;
		now.clear(),tmp.clear();
		rep(i,1,n+1) now.pb(i);
		while (SZ(now)>1) {
			int v=SZ(now)/2+1;
			tmp.clear();
			for (int i=0;i<SZ(now);i+=2) {
				if ((sta>>cur)&1) tmp.pb(now[i+1]),rk[now[i]]=v;
				else tmp.pb(now[i]),rk[now[i+1]]=v;
				cur++;
			}
			now.clear();
			rep(i,0,SZ(tmp)) now.pb(tmp[i]);
		}
		rk[now[0]]=1;
		ll hsh=0;
		rep(i,1,n+1) hsh=(hsh+i*powmod(A,rk[i])%mod)%mod;
		if (hsh==H) {
			rep(i,1,n+1) printf("%d ",rk[i]);
			return ;
		}
	}
	puts("-1");
}

const int T=7e4+5;
int cnt;
pii pr0[T],pr1[T];
int nxt[40];

void gao(int sta) {// now is prepared
	int cur=0;
	while (SZ(now)>1) {
		int v=SZ(now)/2+1;
		tmp.clear();
		for (int i=0;i<SZ(now);i+=2) {
			if ((sta>>cur)&1) tmp.pb(now[i+1]),rk[now[i]]=v;
			else tmp.pb(now[i]),rk[now[i+1]]=v;
			cur++;
		}
		now.clear();
		rep(i,0,SZ(tmp)) now.pb(tmp[i]);
	}
	rk[now[0]]=1;
}
void solve2() {
	nxt[1]=2,nxt[2]=3,nxt[3]=5,nxt[5]=9,nxt[9]=17;
	
	int tot=15;
	rep(sta,0,1<<tot) {
		now.clear(),tmp.clear();
		rep(i,1,16+1) now.pb(i);
		gao(sta);
		
		ll hsh0=0,hsh1=0;
		rep(i,1,16+1) {
			if (rk[i]!=1) {
				add(hsh0,i*powmod(A,nxt[rk[i]])%mod);
				add(hsh1,i*powmod(A,nxt[rk[i]])%mod);
			}else {
				add(hsh0,i*powmod(A,nxt[rk[i]])%mod);
				add(hsh1,i*powmod(A,1)%mod);
			}
		}
		pr0[++cnt]=mp((int)hsh0,sta),pr1[cnt]=mp((int)hsh1,sta);
	}
	sort(pr0+1,pr0+1+cnt);
	sort(pr1+1,pr1+1+cnt);
	
	rep(sta,0,1<<tot) {
		now.clear(),tmp.clear();
		rep(i,17,32+1) now.pb(i);
		gao(sta);
		
		ll hsh0=0,hsh1=0;
		rep(i,17,32+1) {
			if (rk[i]!=1) {
				add(hsh0,i*powmod(A,nxt[rk[i]])%mod);
				add(hsh1,i*powmod(A,nxt[rk[i]])%mod);
			}else {
				add(hsh0,i*powmod(A,nxt[rk[i]])%mod);
				add(hsh1,i*powmod(A,1)%mod);
			}
		}
		
		// lose
		int ned0=(H-hsh0+mod)%mod;
		int p=lower_bound(pr1+1,pr1+1+cnt,mp(ned0,0))-pr1;
		if (pr1[p].fi!=ned0) ;
		else {
			now.clear(),tmp.clear();
			rep(i,1,16+1) now.pb(i);
			gao(pr1[p].se);
			rep(i,1,16+1) printf("%d ",rk[i]==1?1:nxt[rk[i]]);
			rep(i,17,32+1) printf("%d ",nxt[rk[i]]);
			puts("");
			return;
		}
		
		// win
		int ned1=(H-hsh1+mod)%mod;
		p=lower_bound(pr0+1,pr0+1+cnt,mp(ned1,0))-pr0;
		if (pr0[p].fi!=ned1) ;
		else {
			now.clear(),tmp.clear();
			rep(i,1,16+1) now.pb(i);
			gao(pr0[p].se);
			rep(i,1,16+1) printf("%d ",nxt[rk[i]]);
			rep(i,17,32+1) printf("%d ",rk[i]==1?1:nxt[rk[i]]);
			puts("");
			return;
		}
	}
	puts("-1");
	
}

int main() {
	scanf("%d%d%d",&k,&A,&H); H%=mod;
	if (k<=4) solve1();
	else solve2();
	return 0;
}