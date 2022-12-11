#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define fst first
#define snd second
#define mp make_pair
#define fore(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define SZ(x) ((int)(x).size())
#define mset(x,t) memset(x,t,sizeof(x))
#define mcpy(x,y) memcpy(x,y,sizeof(x))
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
	while(b){
		ll c=a%b;
		a=b;b=c;
	}
	return a;
}

ll lcm(ll a, ll b){
	return a/gcd(a,b)*b;
}

int main(){
	ll a,b;
	scanf("%lld%lld",&a,&b);
	ll t=abs(a-b);
	auto r=mp(lcm(a,b),0LL);
	for(int i=1;i*i<=t;++i)if(t%i==0){
		ll k=i-a%i;
		r=min(r,mp(lcm(a+k,b+k),1LL*k));
		k=t/i-a%(t/i);
		r=min(r,mp(lcm(a+k,b+k),1LL*k));
	}
	printf("%lld\n",r.snd);
	return 0;
}