#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<cstring>
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
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

ll gcd(ll a,ll b){
	while(a&&b)
		if(a>b)a%=b;
		else b%=a;
	return a+b;
}

set<ll> t;
void ss(ll m,ll a,ll b,ll c =0){
	if(t.count(c))return;
	t.insert(c);
	if(c+a<=m)ss(m,a,b,c+a);
	if(c-b>=0)ss(m,a,b,c-b);
}
ll stupid(ll m,ll a,ll b){
	ll res = 0;
	REP(i,m+1){
		t.clear();
		ss(i,a,b);
		res += t.size();
	}
	return res;
}

bool u[222222];
ll m,a,b;

void go(ll p,ll i,ll& s){
	if(p-b>=0 && u[p-b]==0){
		u[p-b]=1;
		s++;
		go(p-b,i,s);
	}
	if(p+a<=i && u[p+a]==0){
		u[p+a]=1;
		s++;
		go(p+a,i,s);
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>m>>a>>b;


	CL(u,0);



	ll M=m;

	ll g = gcd(a,b);

	ll res = 0;
	if(m>=a+b){
		ll len = m - (a+b)+1;
		ll gr = len / g;
		ll lgr = len % g;

		res += g * ((a+b)/g+1+(a+b)/g+1+gr-1)*gr/2;
		res += lgr * ((a+b)/g+1+gr);

		m=a+b-1;
	}
	if(m==a+b-1){
		res += (a+b)/g;
		m--;
	}
	res++; // 0
	ll z = 1;
	u[0]=1;
	for(ll i=1;i<=m;i++){
		if(i>=a && u[i-a]){
			u[i]=1;
			z++;
			go(i,i,z);
		}
		res += z;
	}
	/*
	if(res!=stupid(M,a,b)){
		cout<<res<<' '<<stupid(M,a,b)<<endl;
		cout<<M<<' '<<a<<' '<<b<<endl;
	}else{
		cout<<"OK "<<res<<endl;
		goto start;
	}*/
	cout<<res<<endl;//' '<<stupid(M,a,b)<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}
/*
100 99

100

0 1 100

0 1 100 101*/