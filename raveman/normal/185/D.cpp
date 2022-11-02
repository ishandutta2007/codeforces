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

ll qp(ll c,ll st,int mod){
	ll r = 1;
	while(st){
		if(st&1) r=(r*c)%mod;
		c=(c*c)%mod;st>>=1;
	}
	return r;
}

ll gcd(ll a,ll b){
	if(a<0) a=-a;
	if(b<0) b=-b;
	while(a&&b)
		if(a>b) a%=b;
		else b%=a;
	return a+b;
}

int solve(int k,ll l, ll r,int p){
	if(p==2) return 1-(k%2);
	//if(k%p==0) return 1;
	int pw = qp(2,l,p-1);
	int a = qp(k, pw, p);
	if(k%p==0) a=0;
	//cout<<a<<' '<<pw<<endl;
	if(a==1){
		ll res = qp(2,r-l+1,p);
		if(k%2){
			res *= qp(qp(2, r-l, p),p-2,p);
			res %= p;
		}
		return res;
	}

	ll res = qp(a,qp(2,r-l+1,p-1),p);
	if(a==0) res = 0;
	//cout<<res<<' '<<a<<' '<<qp(2,r-l+1,p-1)<<endl;
	res--;
	//cout<<res<<endl;
	if(res<0) res +=p;
	int aa = a-1;
	if(aa<0) aa+=p;
	res *= qp(aa,p-2,p);
	res %= p;
	//cout<<res<<endl;
	if(k%2){
		res *= qp(qp(2, r-l, p),p-2,p);
		res %= p;
	}

	return res;
}


int stupid(int k,ll l, ll r,int p){
	int mod = 1000000007;
	ll res = 1;
	for(ll i=l;i<=r;i++){
		ll st = qp(2,i,mod-1);
		ll val = qp(k,st,mod)+1;
		//cout<<val<<' '<<endl;
		ll g = gcd(res,val);
		res = res/g * val;
	}
	return res%p;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		int k,p;ll l,r;
		scanf("%d %I64d %I64d %d",&k,&l,&r,&p);
/*start:
		l=rand()%3;
		r=rand()%3;
		if(l>r) swap(l,r);
		k=rand()%10+1;*/
		//p=7;
		//cout<<l<<' '<<r<<' '<<k<<' '<<p<<endl;
		//printf("%d %d\n",solve(k,l,r,p),stupid(k,l,r,p));
		printf("%d\n",solve(k,l,r,p));
		//if(stupid(k,l,r,p)==solve(k,l,r,p)) goto start;
		//else break;
	}
	/*
	for(int k=1;k<=5;k++){
		ll prev = 1;
		for(int l=0;l<=10;l++){
			ll nx = qp(k,qp(2,l))+1;
			cout<<nx<<" ("<<gcd(nx,prev)<<") "<<' ';
			prev = nx;
		}
		puts("");
	}
	*/

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}