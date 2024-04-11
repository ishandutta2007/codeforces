#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)

typedef double db;
typedef long long ll;

ll C(int n,int m) {
	if(n<m) return 0;
	ll t=1;
	FOR(i,1,m) t=t*(n-i+1);
	FOR(i,1,m) t=t/i;
	return t;
}
db P[]={0,1/3.0+1/3.0/2,1,1};
int main() {
	int n;
	db p;
	scanf("%d%lf",&n,&p);
	FOR(i,0,n) {
		db t=0;
//		db ss=0;
		FOR(j,0,3) {
			db q=C(i,j)*C(n-i,3-j)/(1.0*C(n,3));
//			ss+=q;
			t+=q*P[j];
		}
//		cerr << ss << endl;
		if(t+1e-8>=p) {
			printf("%d\n",i);
			return 0;
		}
	}
	assert(0);
	return 0;
}