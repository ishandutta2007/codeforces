#pragma comment(linker, "/STACK:65777216")
 
#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

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

typedef pair<ll,ll> pl;
map<pl,bool> w;
bool go(ll a,ll b){
	//cout<<a<<' '<<b<<endl;
	if(a==0 || b==0) return 0;
	if(a>b) return go(b,a);
	if(a==1) return 1;
	if(w.count(pl(a,b))) return w[pl(a,b)];
	if(!go(a,b%a)) return w[pl(a,b)]=1;
	//cout<<w.size()<<' '<<a<<' '<<b<<endl;
	ll s=1;
	for(;;){
		if(s*double(a) > 2*double(b)) break;
		s*=a;
		if(b>=s) if(!go(a,b-s)) return w[pl(a,b)]=1;
	}
	return w[pl(a,b)]=0;
}

ll preparse(ll b,ll a){
	return b;
	vector<ll> t;
	while(b){
		t.pb(b%a);
//		t.back()%=2;
		b/=a;
	}
	reverse(t.begin(),t.end());
	ll res = 0;
	REP(i,t.size()) res = res*a+t[i];
	return res;
}

map<pl,bool> w3;
bool go3(ll b,ll a){
	return (b%(a+1))%2==0;
	if(a==2) return b%3==0 || b%3==2;
	if(a==3) return b%2==0;
	if(a==4) return (b%(a+1))%2==0;
	return (b%(a+1))%2==0;
	if(b==0) return 1;
	if(b<a) return b%2==0;
	
	ll t = b%a;

	if(w3.count(pl(a,b))) return w3[pl(a,b)];
	ll s = 1;
	//cout<<a<<' '<<b<<endl;
	for(;;){
		if(!go3(b-s,a)) return w3[pl(a,b)]=1;
		if(s*double(a) >  2*double(b) || s*a>b) break;
		s*=a;
	}
	return w3[pl(a,b)]=0;
}

map<pl,bool> w2;
bool go2(ll a,ll b){
	//cout<<a<<' '<<b<<endl;
	if(a==0 || b==0) return 0;
	if(a>b) return go2(b,a);
	if(a==1) return 1;
	if(w2.count(pl(a,b))) return w2[pl(a,b)];
	w3.clear();
	if(go3(preparse(b/a,a),a)) return w2[pl(a,b)]=1;
	if(!go2(a,b%a)) return w2[pl(a,b)]=1;
	return w2[pl(a,b)]=0;
}


ll r(){
	return rand()%100;
	ll v = 31;
	REP(i,53) v=v*2+rand()%2;
	return v;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	//REP(i,100) if(go3(i,4)) cout<<i<<endl;
	//return 0;
		int tc;
	cin>>tc;
	int it=0;
	REP(TC,tc){
		ll a,b;
//start:
		//it++;
		cin>>a>>b;
		
		//a=r();
		//b=r();
		//a=286785197954851792ll;
		//b=287083971438852791ll;
		//a=284951916423813801ll;
		//b=284951658124499619ll;

		//cout<<a<<' '<<b<<endl;
		w.clear();w2.clear();w3.clear();

		/*if(go(a,b)!=go2(a,b)){
			cout<<a<<' '<<b<<endl;
			puts("FUCK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		}
		else puts("OK");*/
		w.clear();w2.clear();w3.clear();
		puts(go2(a,b)?"First":"Second");
		//cout<<a<<' '<<b<<endl;
		//go2(a,b);
		//if(it==10000) break;
		
	//	goto start;
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}