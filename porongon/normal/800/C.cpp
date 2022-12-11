#include <algorithm>
#include <bitset>
#include <cassert>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define FORN(i,b) for(int i=0;i<(b);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

int gcd(int a, int b){
	while(b){
		int c=a%b;
		a=b;
		b=c;
	}
	return a;
}

pair<ll,ll> extendedEuclid(ll a, ll b){
	ll x,y;
	if (b==0) return mp(1,0);
	pair<ll,ll> p=extendedEuclid(b,a%b);
	x=p.snd;
	y=p.fst-(a/b)*x;
	if(a*x+b*y==-gcd(a,b)) x=-x, y=-y;
	return mp(x,y);
}
ll inv(ll a, ll mod) {
	assert(gcd(a,mod)==1);
	pair<ll,ll> sol=extendedEuclid(a,mod);
	return ((sol.fst%mod)+mod)%mod;
}

int n,m;
bool h[200005];
int q[200005];
vi w[200005];
vi p;
int f[200005],c[200005];
vi r;

int solve(int k, int r){ // returns x such that k*x=r
	//printf("solving %d %d\n",k,r);
	assert(r%gcd(k,m)==0);
	int mm=m;
	for(int w:p){
		while(k%w==0&&mm%w==0){
			assert(r%w==0);
			k/=w;r/=w;mm/=w;
		}
	}
	//printf("I have %d %d\n",k,r);
	//int q=k/gcd(k,m);printf("(%d %d %d)\n",k,r,q);
	return (1LL*inv(k,mm)*r)%m;
}

void fact(int m){
	for(int i=2;m>1;++i){
		if(m%i==0){
			p.pb(i);
			while(m%i==0)m/=i;
		}
	}
}

int go(int x){
	if(f[x]>=0)return f[x];
	if(x==m)return f[x]=q[0];
	int r=-1;
	for(int k:p){
		if(m%(k*x)==0){
			if(go(k*x)>r){
				r=go(k*x);
				c[x]=k*x;
			}
		}
	}
	return f[x]=r+q[x];
}

int main(){
	scanf("%d%d",&n,&m);
	memset(h,1,sizeof(h));
	FORN(i,n){
		int x;
		scanf("%d",&x);
		h[x]=0;
	}
	fact(m);
	FORN(i,m)if(h[i])q[gcd(m,i)%m]++,w[gcd(m,i)%m].pb(i);
	memset(f,-1,sizeof(f));
	go(1);
	int k=1;
	while(k!=m){
		for(int x:w[k])r.pb(x);
		k=c[k];
	}
	if(h[0])r.pb(0);
	printf("%d\n",(int)r.size());
	//for(auto x:r)printf(" %d",x);puts("");
	int c=1;
	FORN(i,r.size()){
		if(i)putchar(' ');
		printf("%d",solve(c,r[i]));
		c=r[i];
	}
	puts("");
	return 0;
}

/*
  _____   ____  _____   ____  _   _  _____  ____  _   _
 |  __ \ / __ \|  __ \ / __ \| \ | |/ ____|/ __ \| \ | |
 | |__) | |  | | |__) | |  | |  \| | |  __| |  | |  \| |
 |  ___/| |  | |  _  /| |  | | . ` | | |_ | |  | | . ` |
 | |    | |__| | | \ \| |__| | |\  | |__| | |__| | |\  |
 |_|     \____/|_|  \_\\____/|_| \_|\_____|\____/|_| \_|

*/