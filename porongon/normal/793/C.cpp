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

#define y0 PORONGON
#define y1 PORON_GON

typedef ll tp;

tp gcd(tp a, tp b){return a?gcd(b%a, a):b;}
struct rat{
	tp p,q;
	rat(tp p=0, tp q=1):p(p),q(q) {norm();}
	void norm(){
		tp a = gcd(p,q);
		if(a) p/=a, q/=a;
		else q=1;
		if (q<0) q=-q, p=-p;}
	rat operator+(const rat& o){
		tp a = gcd(q,o.q);
		return rat(p*(o.q/a)+o.p*(q/a), q*(o.q/a));}
	rat operator-(const rat& o){
		tp a = gcd(q,o.q);
		return rat(p*(o.q/a)-o.p*(q/a), q*(o.q/a));}
	rat operator*(rat o){
		tp a = gcd(q,o.p), b = gcd(o.q,p);
		return rat((p/b)*(o.p/a), (q/a)*(o.q/b));}
	rat operator/(rat o){
		tp a = gcd(q,o.q), b = gcd(o.p,p);
		return rat((p/b)*(o.q/a),(q/a)*(o.p/b));}
	bool operator<(const rat &o) const{return p*o.q < o.p*q;}
	bool operator==(rat o){return p==o.p&&q==o.q;}
};

int n;

rat a,b;
ll x0,y0,x1,y1;

void doit(ll x, ll vx, ll x0, ll x1){
	if(x0>x1)swap(x0,x1);
	if(vx==0){
		if(x>x0&&x<x1)return;
		a=rat(1);
		b=rat(0);
		return;
	}
	rat w0(x0-x,vx),w1(x1-x,vx);
	if(w1<w0)swap(w0,w1);
	a=max(a,w0);
	b=min(b,w1);
}

int main(){
	scanf("%d%lld%lld%lld%lld",&n,&x0,&y0,&x1,&y1);
	a=rat(0);b=rat(1<<30);
	FORN(i,n){
		ll x,y,vx,vy;
		scanf("%lld%lld%lld%lld",&x,&y,&vx,&vy);
		doit(x,vx,x0,x1);
		doit(y,vy,y0,y1);
	}
	if(a<b)printf("%.12lf\n",1.*a.p/a.q);
	else puts("-1");
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