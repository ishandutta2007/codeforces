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

ll n;
int m,mod;

int solve(ll l,ll r,ll u,ll v,ll n,ll start,ll step){
	u = max(u, start);
	v = min(v, start + step*(n-1));
	if(l>r || r<1 || l>n) return 0;
	if(l<=1 && r>=n){
		int ans = 0;
		if(start < u){
			start += ((u - start)/step)*step;
			while(start<u) start += step;
		}
		if(start > v) return 0;
		ll num = (v-start)/step+1;
		ll v1 = (start + start + step * (num-1));
		ll v2 = num;
		if(v1%2==0) v1/=2;
		else v2/=2;
		v1%=mod;
		v2%=mod;
		v1*=v2;
		v1%=mod;
		return v1;
	}
	int res = 0;
	res += solve(l,min(r,(n+1)/2),u,v,(n+1)/2,start,step*2);
	res += solve(max((n+1)/2+1,l)-(n+1)/2,r-(n+1)/2,u,v,n/2    ,start+step,step*2);
	if(res>=mod) res-=mod;
	return res;
}

vector<ll> f(vector<ll> q){
	if(q.size()<2) return q;
	vector<ll> t1;
	vector<ll> t2;
	REP(i,q.size()){
		if(i%2) t2.pb(q[i]);
		else t1.pb(q[i]);
	}
	t1 = f(t1);
	t2 = f(t2);
	REP(i,t2.size()) t1.pb(t2[i]);
	return t1;
}

int stupid(ll l, ll r, ll u, ll v,ll n){
	vector<ll> q;
	REP(i,n) q.pb(i+1);
	q = f(q);
	ll sum = 0;
	FOR(i,l-1,r)if(q[i]>=u && q[i]<=v){
		sum += q[i];
		sum %= mod;
	}
	return sum;
}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>mod;
	REP(i,m){
		ll l,r,u,v;
		scanf("%I64d %I64d %I64d %I64d",&l,&r,&u,&v);
		//printf("%d %d\n",solve(l,r,u,v,n,1,1),stupid(l,r,u,v,n));
		printf("%d\n",solve(l,r,u,v,n,1,1));
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}