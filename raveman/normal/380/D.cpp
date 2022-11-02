#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
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
#include<bitset>
#include<fstream>
#include<queue>

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

const int mod = 1000000007;

int n;
int a[111111];

int qp2(int pw){
	int sum = 1;
	REP(i,pw)sum*=2,sum%=mod;
	return sum;
}

ll f[111111];
ll invf[111111];
ll c(int n,int m){
	if(n==m || m==0) return 1;
	ll res = f[n];
	res *= invf[m]; res %= mod;
	res *= invf[n-m]; res %= mod;
	return res;
}

ll qp(ll p, ll st){
	ll r = 1;
	while(st){
		if(st&1)r*=p,r%=mod;
		p*=p;p%=mod;
		st>>=1;
	}
	return r;
}

ll solve(int from,int to){
	ll res = 1;
	int np = to;
	int pp = from;
	while(from!=0 || to!=n-1){
		np = max(np, to + 1);
		while(np<n && a[np]==0) np++;
		pp = min(pp, from - 1);
		while(pp>=0 && a[pp]==0) pp--;
		if(pp<0 && np>=n){
			res *= c(from+(n-1-to),from);
			res %= mod;
			break;
		}else if(pp<0 || np<n && a[np] < a[pp]){
			if (a[np] <= (to-from+1)) return 0;
			int nm = a[np] - (to-from+1);
			int lf = nm - (np - to);
			if(lf<0) return 0;
			if(from-lf<0) return 0;
			if(from-lf<=pp) return 0;
			res *= c(lf+np-to-1,lf);
			res %= mod;
			to = np;
			from -= lf;
		}else{
			if (a[pp] <= (to-from+1)) return 0;
			int nm = a[pp] - (to-from+1);
			int rg = nm - (from - pp);
			if(rg<0) return 0;
			if(to+rg>=n) return 0;
			if(to+rg>=np) return 0;
			res *= c(rg+from-pp-1,rg);
			res %= mod;
			from = pp;
			to += rg;
		}
	}
	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	f[0]=1;
	FOR(i,1,111111)f[i]=f[i-1]*i,f[i]%=mod;
	REP(i,111111)invf[i]=qp(f[i],mod-2);
	cin>>n;
	int num = 0;
	REP(i,n)scanf("%d",a+i),num+=(a[i]==0?0:1);
	if(num==0){
		cout<<qp2(n-1)<<endl;
	}else{
		int pos = -1;
		REP(i,n) if(a[i] && (pos==-1 || a[pos] > a[i])) pos = i;
		int res = 0;
		// c1
		{
			int nm = a[pos];
			bool good = true;
			REP(i,nm-1)if(pos-1-i<0 || a[pos-1-i]!=0)good=0;
			if(good){
				ll t = qp2(nm-1-1);
				t *= solve(pos-nm+1,pos);
				t %= mod;
				res += t;
				res %= mod;
			}
		}
		// c2
		if (a[pos] != 1) {
			int nm = a[pos];
			bool good = true;
			REP(i,nm-1)if(pos+1+i>=n || a[pos+1+i]!=0)good=0;
			if(good){
				ll t = qp2(nm-1-1);
				t *= solve(pos,pos+nm-1);
				t %= mod;
				res += t;
				res %= mod;
			}
		}
		cout<<res<<endl;
	}


#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}