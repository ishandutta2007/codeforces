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
ll k;
vector<ll> v;

void go(ll c){
	if(c) v.pb(c);
	if(c<=100000000000000000ll){
		go(c*10+4);
		go(c*10+7);
	}
}

typedef pair<ll,ll> pl;

ll v1[1111111];
ll v2[1111111];
ll n1[1111111];
ll n2[1111111];

pl m[111111];
ll diff;

bool good(int num){
	REP(i,v.size()){
		ll start = v[i];
		if(i+num-1>=v.size()) continue;
		ll end =   v[i+num-1];
		if(end-start>diff) continue;
		ll val = v1[i] + v2[i+num-1];
		if(val<=k) return 1;
	}
	return 0;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	go(0);
	SORT(v);

	cin>>n>>k;
	diff = 1000000000000000000ll;
	REP(i,n) scanf("%I64d %I64d",&m[i].first,&m[i].second),diff=min(diff, m[i].second-m[i].first);
	sort(m,m+n);
	
	int pos = n-1;
	for(int i = v.size() - 1;i>=0;i--){
		if(v1[i+1] + n1[i+1]*double(v[i+1]-v[i]) > 2*k) 
			v1[i] = k+1;
		else v1[i] = v1[i+1] + n1[i+1] * (v[i+1]-v[i]);
		v1[i] = min(v1[i],k+1);
		n1[i] = n1[i+1];

		while(pos>=0 && m[pos].first >= v[i]){
			n1[i]++;
			v1[i] += (m[pos].first - v[i]);
			v1[i] = min(v1[i],k+1);
			pos--;
		}		
	}

	REP(i,n) swap(m[i].first,m[i].second);
	sort(m,m+n);
	REP(i,n) swap(m[i].first,m[i].second);

	pos = 0;
	for(int i = 0;i<v.size();i++){
		if(i){
			if(v2[i-1] + n2[i-1] * double(v[i] - v[i-1])) v2[i]=k+1;
			else v2[i] = v2[i-1] + n2[i-1] * (v[i] - v[i-1]);
			v2[i] = min(v2[i],k+1);
			n2[i] = n2[i-1];
		}

		while(pos<n && m[pos].second <= v[i]){
			n2[i]++;
			v2[i] += (v[i] - m[pos].second);
			v2[i] = min(v2[i],k+1);
			pos++;
		}		
	}

	int best = 0;
	int a = 1, b = v.size();
	while(a<=b){
		int s = (a+b)>>1;
		if(good(s)) best=s,a=s+1;
		else b=s-1;
	}
	cout<<best<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}