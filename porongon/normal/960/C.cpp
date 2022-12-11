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

ll x,d;
vector<ll> r;

int main(){
	scanf("%lld%lld",&x,&d);
	ll o=1;
	for(int i=32;i>0;--i){
		while(((1LL<<i)-1)<=x){
			x-=((1LL<<i)-1);
			FORN(j,i)r.pb(o);
			o+=d+2;
		}
	}
	printf("%d\n",SZ(r));
	FORN(i,SZ(r))printf("%lld%c",r[i]," \n"[i==SZ(r)-1]);
	return 0;
}