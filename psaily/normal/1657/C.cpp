#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
#define fi first
#define se second

const int Mod=998244353;
ll Fast(ll x,int b) {
	ll t=1;
	for(; b; b>>=1,x=x*x%Mod) {
		if(b&1) t=t*x%Mod;
	}
	return t;
}
const int N=5e5+50;
const int Base=233;

char str[N];
void solve() {
	int n;
	scanf("%d%s",&n,str+1);
	ull h1=0,h2=0;
	int f=0;
	int r1=0;
	ull t=1;
	int r=0;
	int p=0;
	int l=0;
	FOR(i,1,n) {
		++l;
		if(str[i]=='(') {
			++f;
			h1=h1*Base;
		} else {
			--f;
			h1=h1*Base+1;
			h2=h2+t;
			if(f<0) r1=-1;
		}
		t=t*Base;
		if(f==0 && r1==0) {
//			cerr << i << endl;
			p=i;
			h1=h2=f=r1=0;
			t=1;
			++r;
			l=0;
		} else if(l>1 && h1==h2) {
			p=i;
			h1=h2=f=r1=0;
			t=1;
			++r;
			l=0;
		}
	}
//	cerr << p << endl;
	printf("%d %d\n",r,n-p);
}
int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}