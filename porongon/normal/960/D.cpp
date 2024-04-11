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
#define mp make_pair
#define fst first
#define snd second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define FORN(i,b) for(int i=0;i<(b);i++)
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

void floordiv(ll x, ll y, ll& q, ll& r) {
	q=x/y;r=x%y;
	if((r!=0)&&((r<0)!=(y<0)))q--,r+=y;
}
ll pisodiv(ll a, ll b){
	ll q,r;
	floordiv(a,b,q,r);
	return q;
}

ll q0[64],q1[64];int q;

ll shift(ll x, int l, ll s){
	x-=1LL<<(l-1);
	assert(x>=0);
	x+=s;
	x%=1LL<<(l-1);
	x+=1LL<<(l-1);
	x%=1LL<<(l-1);
	x+=1LL<<(l-1);
	return x;
}

void query(ll x){
	int l=1;
	while((1LL<<l)<=x)l++;
	//printf(" %lld %d\n",x,l);
	x=shift(x,l,-q0[l]);
	while(1){
		printf("%lld",shift(x,l,q0[l]));
		if(l==1){puts("");break;}
		putchar(' ');
		x=shift(x/2,l-1,pisodiv(q1[l]+(x%2),2));
		l--;
	}
}

int main(){
	scanf("%d",&q);
	while(q--){
		int	t;ll x;
		scanf("%d%lld",&t,&x);
		if(t<=2){
			ll k;
			scanf("%lld",&k);
			int l=1;
			while((1LL<<l)<=x)l++;
			if(t==1){
				q0[l]-=k;
			}
			else {
				q1[l]+=k;
			}
		}
		else query(x);
	}
	return 0;
}