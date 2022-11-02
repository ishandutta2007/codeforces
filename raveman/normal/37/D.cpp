#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include<complex>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int n,m;
int x[111];
int y[111];

const int mod = 1000000007;
int qp(ll r,int st){
	ll a = 1;
	while(st){
		if(st&1) a*=r,a%=mod;
		r*=r,r%=mod;
		st>>=1;
	}
	return a;
}
int inv(int x){return qp(x,mod-2);}

int r[111][1001];
int c[1111][1111];

int go(int pos,int a){
	if(pos==m) return a==0 ? 1 : 0;
	if(r[pos][a]!=-1) return r[pos][a];
	int val = 0;
	for(int i=0;i<=min(y[pos], a + x[pos]);i++){
		ll t  = go(pos+1, a+x[pos]-i);
		t*= c[a+x[pos]][i];
		val+=(t%mod);
		if(val>=mod) val-=mod;
	}

	return r[pos][a]=val;
}

int main(){
#ifdef LocalHost    
	freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	c[0][0]=1;
	FOR(i,1,1111){
		c[i][0]=c[i][i]=1;
		FOR(j,1,i) c[i][j]= (c[i-1][j]+c[i-1][j-1])%mod;
	}
	cin>>m;
	REP(i,m) cin>>x[i],n+=x[i];
	REP(i,m) cin>>y[i];

	ll res = 1;
	FOR(i,2,n+1) res*=i,res%=mod;
	REP(i,m) FOR(j,2,x[i]+1) res*=inv(j),res%=mod;

	CL(r,-1);
	ll a = go(0,0);
	res *= a;
	res%=mod;

	cout<<res<<endl;


	return 0;
}