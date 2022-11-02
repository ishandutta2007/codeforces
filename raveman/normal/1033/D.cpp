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
#include<unordered_map>
#include<unordered_set>

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

const int mod = 998244353;

ll a[555];
int n;

map<ll,int> m;

ll gcd(ll a,ll b){
	while(a&&b)
		if(a>b)a%=b;
		else b%=a;
	return a+b;
}

void process(ll t){
	REP(i,n)if(a[i]%t==0){
		while(a[i]%t==0)a[i]/=t,m[t]++;
		if(a[i]>1) process(a[i]);
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)cin>>a[i];
	REP(i,n)if(a[i]>1){
		ll t = pow(a[i]+0., 1/3.);
		while(t*t*t<a[i])t++;
		if(t*t*t==a[i]){
			process(t);
		}
	}
	REP(i,n)if(a[i]>1){

		ll t = sqrt(a[i]+0.0);
		while(t*t<a[i])t++;
		if(a[i]==t*t){
			ll t2 = sqrt(t+0.0);
			while(t2*t2<t)t2++;
			if(t==t2*t2){
				process(t2);
			}else{
				process(t);
			}
		}
	}
	REP(i,n)if(a[i]!=1){
		REP(j,i)if(a[j]!=1 && a[i]!=a[j]){
			ll g = gcd(a[i],a[j]);
			if(g>1){
				process(g);
				break;
			}
		}
	}
	int cnt = 0;
	REP(i,n)if(a[i]!=1){
		cnt+=2;
		ll tmp = a[i];
		REP(j,n)if(a[j]==tmp){
			a[j]=1;
			m[-cnt]++;
			m[-cnt-1]++;
		}
	}
	ll res = 1;
	for(map<ll,int>::iterator it = m.begin();it!=m.end();++it){
		//cout<<it->first<<' '<<it->second<<endl;
		res *= (it->second+1);
		res %= mod;
	}
	cout<<res<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}