#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
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
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

ll n,S;
int s[111111],a[111111],b[111111]; 

ll solve(const vector<pii>& v, int *a){
	ll r = 0;
	REP(i,v.size()){
		r += a[v[i].second]*ll(s[v[i].second]);
	}
	return r;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>S;
	REP(i,n)scanf("%d %d %d",s+i,a+i,b+i);
	vector<pii> v1;
	vector<pii> v2;
	REP(i,n){
		if(a[i]>=b[i])v1.pb(pii(a[i]-b[i],i));
		else v2.pb(pii(b[i]-a[i],i));
	}
	SORT(v1);
	SORT(v2);

	ll sum = 0;
	while(!v1.empty()){
		sum += a[v1.back().second]*ll(s[v1.back().second] / S) * S;
		s[v1.back().second] %= S;
		if(s[v1.back().second]==0){v1.pop_back();continue;}
		ll sm = 0;
		for(int i=v1.size()-1;i>=0;i--){
			sm += s[v1[i].second];
			if (sm >= S) {
				while(v1.size() > i + 1) {
					sum += a[v1.back().second]*ll(s[v1.back().second]);
					v1.pop_back();
				}
				ll d = sm - S;
				sum += a[v1.back().second] * ll(s[v1.back().second]-d);
				s[v1.back().second] = d;
				break;
			}
		}
		if (sm < S) break;
	}
	while(!v2.empty()){
		sum += b[v2.back().second]*ll(s[v2.back().second] / S) * S;
		s[v2.back().second] %= S;
		if(s[v2.back().second]==0){v2.pop_back();continue;}
		ll sm = 0;
		for(int i=v2.size()-1;i>=0;i--){
			sm += s[v2[i].second];
			if (sm >= S) {
				while(v2.size() > i + 1) {
					sum += b[v2.back().second]*ll(s[v2.back().second]);
					v2.pop_back();
				}
				ll d = sm - S;
				sum += b[v2.back().second] * ll(s[v2.back().second]-d);
				s[v2.back().second] = d;
				break;
			}
		}
		if (sm < S) break;
	}

	ll s1 = 0, s2 = 0;
	REP(i,v1.size()) s1 += s[v1[i].second];
	REP(i,v2.size()) s2 += s[v2[i].second];
	if (s1 + s2 <= S){
		sum += max(solve(v1,a)+solve(v2,a),solve(v1,b)+solve(v2,b));
	}else{
		sum += solve(v1,a)+solve(v2,b);
	}

	cout<<sum<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}