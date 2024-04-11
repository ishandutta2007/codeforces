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

const int mod = 1000000007 ;

int n,m;
int s[111111];
int t[111111];
vi x;
vector<pii> r;

int rr[444444];

void add(int pos,int val){
	pos += 222222;
	while(pos){
		rr[pos] += val;
		if(rr[pos]>=mod) rr[pos]-=mod;
		pos>>=1;
	}
}

int sum(int p1,int p2){
	p1 += 222222;
	p2 += 222222;

	int res = 0;
	while(p1<=p2){
		if(p1&1){
			res += rr[p1];
			if(res>=mod) res-=mod;
		}
		if(!(p2&1)){
			res += rr[p2];
			if(res>=mod) res-=mod;
		}
		p1= (p1+1)>>1;
		p2=(p2-1)>>1;
	}
	return res;
}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,m) scanf("%d %d",s+i,t+i),x.pb(s[i]),x.pb(t[i]);
	x.pb(0);
	x.pb(n);
	UN(x);
	REP(i,m){
		s[i] = lower_bound(x.begin(),x.end(),s[i])-x.begin();
		t[i] = lower_bound(x.begin(),x.end(),t[i])-x.begin();
		r.pb(pii(t[i],s[i]));
	}
	SORT(r);
	
	add(0,1);
	REP(i,r.size())
		add(r[i].first, sum(r[i].second, r[i].first-1));
	cout<<sum(x.size()-1,x.size()-1)<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}