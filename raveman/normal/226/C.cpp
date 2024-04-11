#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>

using namespace std;


typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

struct M{
	ll a[2][2];
	M(){CL(a,0);}
	M pom(const M &s, ll mod) const{
		M r;
		REP(k,2)REP(i,2)REP(j,2){
			r.a[i][j] = (r.a[i][j] + a[i][k] * s.a[k][j]) % mod;
		}
		return r;
	}
};

M qp(M m, ll st, ll mod){
	M r;
	r.a[0][0] = r.a[1][1] = 1 % mod;
	while(st){
		if(st&1) r=r.pom(m,mod);
		m = m.pom(m, mod);
		st>>=1;
	}
	return r;
}

ll fb(ll pos, ll mod){
	if(pos<=2) return 1 % mod;
	M m;
	m.a[0][0] = 1 % mod ;
	m.a[1][0] = 1 % mod;
	m.a[0][1] = 1 % mod;
	M t = qp(m, pos-1, mod);
	return t.a[0][0];
}

bool good(ll l, ll r,ll d,ll k){
	if(d<=1) return 0;
	return (r/d)-(l-1)/d>=k;
}
ll solve(ll l, ll r, ll k){
	ll best = 1;
	FOR(i,1,1111111)
		if(good(l,r,i,k))
			best=i;
	/*for(ll rd=1;rd<=1000000;rd++){
		ll d1,d2;

		d1 = r / rd;
		d2 = r / (rd+1)+1;
		if(good(l,r,d1,k))best=max(best,d1);
		if(good(l,r,d2,k))best=max(best,d2);
		ll rd2 = rd - k;

		if(rd2>=0){
			// l-1/d <= rd - k
			ll val = (l-1)/rd2;

		}

		//cout<<rd<<' '<<d2<<' '<<d1<<' '<<r/d1<<' '<<r/d2<<' '<<r/(d2-1)<<' '<<r/(d1+1)<<endl;
	}*/
	for(ll rd=1;rd<=1000000;rd++)FOR(dx,-1,2)FOR(dx2,-1,2){
		ll d = (r+dx)/rd+dx2;
		if(good(l,r,d,k))best=max(best,d);
		d = (l+dx)/rd+dx2;
		if(good(l,r,d,k))best=max(best,d);
	}
	return best;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	ll m,l,r,k;
	cin>>m>>l>>r>>k;
	cout<<fb(solve(l,r,k),m)<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}