#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

int n;
bool c[50];

struct M{
	bool a[50][50];
	M(){CL(a,0);}
	M pow(M &s){
		M r;
		REP(i,n)REP(j,n){
			bool sum = 0;
			REP(k,n) sum ^= a[i][k]&s.a[k][j];
			r.a[i][j]= sum;
		}
		return r;
	}
};

M qp(M m,ll st){
	M r;
	REP(i,n) r.a[i][i]=1;
	while(st){
		if(st&1) r=r.pow(m);
		m=m.pow(m);
		st>>=1;
	}
	return r;
}

bool isOne(M &x){
	REP(i,n)if(!x.a[i][i]) return 0;
	REP(i,n)REP(j,n)if(i!=j && x.a[i][j]) return 0;
	return 1;
}

vector<ll> d;

bool good(){
	M m;
	FOR(i,1,n) m.a[i][i-1]=1;
	REP(i,n)   m.a[0][i]=c[i];
	ll p = (1ll<<n)-1;
	M x = qp(m, p);
	if(!isOne(x)) return 0;
	REP(i,d.size()){
		x = qp(m,p/d[i]);
		if(isOne(x)) return 0;
	}
	return 1;
}

bool v[1<<25];

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	for(int i=2;i<(1<<13);i++)if(!v[i])
		for(int j=i+i;j<(1<<25);j+=i) v[j]=true;
	cin>>n;
	ll p = (1ll<<n)-1;
	for(ll i=2;i*i<=p;i++)if(!v[i] && p%i==0){
		d.pb(i);
		while(p%i==0) p/=i;
	}
	if(p>1) d.pb(p);
	//cout<<d.size()<<' '<<clock()<<endl;
	c[n-1]=1;
	while(1){
		REP(i,min(n-1,48)) c[i]=rand()%2;
		if(good()) break;
	}

	REP(i,n){
		if(i) printf(" ");
		printf("%d",c[i]?1:0);
	}
	puts("");

	REP(i,n){
		if(i) printf(" ");
		printf("1");
	}
	puts("");

#ifdef LocalHost
	cout<<endl<<endl<<clock()<<endl;
#endif
	return 0;
}