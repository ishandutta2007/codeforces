//#pragma comment(linker, "/STACK:60777216")  

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
typedef pair<int,pii>	p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

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

pl extendedgcd(ll a,ll b){
	if(a==0){
		return pl(0,1);
	}else if(b==0){
		return pl(1,0);
	}else if(a>b){
		pl t = extendedgcd(a%b, b);
		return pl(t.first,t.second-a/b*t.first);
	}else{
		pl t = extendedgcd(b,a);
		return pl(t.second,t.first);
	}
}

void buildsum(vector<p3l>& r, ll start, ll mult){
	ll current = 1;
	while(current*2<=mult){
		r.pb(p3l(0,pl(start*current,start*current)));
		current*=2;
	}
	ll mx = current;
	while(current!=mult){
		if(current+mx<=mult){
			r.pb(p3l(0,pl(start*current,start*mx)));
			current+=mx;
		}
		mx/=2;
	}
}

void check(vector<p3l> w, ll start){
	set<ll> s;
	s.insert(start);

	REP(i,w.size()){
		if(!s.count(w[i].second.first) || !s.count(w[i].second.second)){
			puts("FUCK1");
		}
		if(w[i].first==0)s.insert(w[i].second.second+w[i].second.first);
		else s.insert(w[i].second.second^w[i].second.first);
	}

	if(!s.count(1)) puts("FUCK");
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	/*
	for(int i=1;i<=1000000;i++)if(i%2==1){
		bool ho=0;
		for(ll j=1;j<=1000000;j++){
			if(gcd(i,(j*i)^i)==1){ho=1;break;}
		}
		if(!ho)cout<<i<<endl;//": "<<gcd(i,(2*i)^i)<<' '<<gcd(i,(4*i)^i)<<endl;
	}
	*/
	ll x;
	cin>>x;
	vector<p3l> r;
	for(ll j=1;;j++){
		ll nx = (j*x)^x;
		if(gcd(x,nx)==1){
			buildsum(r,x,j);

			r.pb(p3l(1,pl(x,j*x)));

			pl t = extendedgcd(x,nx);
			while(t.first<0 || t.first%2==0){
				t.first+=nx;
				t.second-=x;
			}
			ll t1 = t.first;
			ll t2 = t.second;

			if(t1<0)t1=-t1;
			if(t2<0)t2=-t2;
			//cout<<"! "<<t.first*x + t.second*nx<<' '<<(t1^t2)<<endl;
			
			buildsum(r,x,t1);
			buildsum(r,nx,t2);
			r.pb(p3l(1,pl(x*t1,nx*t2)));
			break;
		}
	}

	//check(r,x);
	//goto start;

	cout<<r.size()<<endl;
	REP(i,r.size()){
		if(r[i].first==0){
			cout<<r[i].second.first<<" + " <<r[i].second.second<<"\n";
		}else{
			cout<<r[i].second.first<<" ^ " <<r[i].second.second<<"\n";
		}
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}