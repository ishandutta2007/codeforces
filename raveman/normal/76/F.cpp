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

int n,V,n1;
pii p[111111];

ll v[222222];
int s[222222];

void setVal(int p,int val){
	p += 111111;
	while(p){
		s[p]=max(s[p],val);
		p>>=1;
	}
}

int getMax(int p){
	int res = 0;
	p += 111111;
	int end = -1+2*111111;
	while(p<=end){
		res = max(res,s[p]);
		res = max(res,s[end]);
		p = (p+1)>>1;
		end = (end-1)>>1;
	}
	return res;
}

pair<ll,ll> q[111111];

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif
	cin>>n;
	REP(i,n) scanf("%d %d",&p[i].first,&p[i].second);
	cin>>V;
	REP(i,n) {
		ll p1 = p[i].first - ll(V) * p[i].second;
		ll p2 = p[i].first + ll(V) * p[i].second;
		v[i] = p2;
		q[i]=make_pair(p1,-p2);
	}
	sort(q,q+n);

	REP(i,n) q[i].second*=(-1);
	sort(v,v+n);
	n1 = unique(v,v+n)-v;
	int res = 0;
	int vv2 = 0; bool checkF = false;
	REP(i,n){

		if(q[i].first > 0 && !checkF){
			checkF = true;
			vv2 = getMax(lower_bound(v,v+n1,0)-v);
		}
		int p = lower_bound(v,v+n1,q[i].second) - v;
		int val = getMax(p) + 1;
		setVal(p, val);
		res = max(res, val);

	}
	if(!checkF)
		vv2 = getMax(lower_bound(v,v+n1,0)-v);
	cout<<vv2<<' '<<res<<endl;
	return 0;
}