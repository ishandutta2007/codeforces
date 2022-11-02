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
#include<stack>

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

const int mod = 1000000000+7;
const ll mod2 = ll(mod) * mod;

struct M{
	int a[128][128];
	M(){CL(a,0);}
	M pom(const M& s){
		M r;
		REP(i,128){
			REP(j,128){
				ll res = 0;
				REP(k,128){
					res += a[i][k] * ll(s.a[k][j]);
					if(res>=mod2)res-=mod2;
				}
				r.a[i][j]=res%mod;
			}
		}
		return r;
	}
};

M m[10];

M qp(M s, int st){
	M r;
	REP(i,128)r.a[i][i]=1;
	while(st){
		if(st&1)r=r.pom(s);
		s=s.pom(s);
		st>>=1;
	}
	return r;
}

bool good(int n,int m1,int m2,int m3){
	REP(i,n){
		if(!(m1&(1<<i))) continue;
		if(!(m2&(1<<i))) continue;
		if(n==1) return false;
		if(i>0 && !(m3&(1<<(i-1)))) continue;
		if(i<n-1 && !(m3&(1<<i))) continue;
		return false;
	}
	return true;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int sum=0;
	vector<pii> w;
	for(int i = 1;i<=7;i++){
		int tt ;
		cin>>tt;
		if(tt>0)w.pb(pii(i,tt));
	}
	if(w.size()==1 && w[0].first==1 && w[0].second==1){
		puts("0");
		return 0;
	}

	M curr;
	REP(i,128)curr.a[i][i]=1;
	REP(ii,w.size()){
		int i = w[ii].first;
		int len = w[ii].second;
		M t;
		REP(j1,1<<i){
			REP(j2,1<<i){
				REP(j3,1<<(i-1)){
					if(good(i,j1,j2,j3)){
						t.a[j1][j2]++;
					}
				}
			}
		}
		t=qp(t,len);
		curr=curr.pom(t);
		if(ii+1<w.size()){
			int msk = 0;
			for(int z = i;z<w[ii+1].first;z++)msk|=(1<<z);
			M per;
			REP(j1,1<<i){
				per.a[j1][j1|msk]=1;
			}
			curr=curr.pom(per);
		}
	}
	cout<<curr.a[(1<<(w[0].first))-1][(1<<(w.back().first))-1]<<endl;
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}