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

int n;
int a[111111];
int b[111111];

vector< pair<int, pl > > s;

void addLine(ll cnt, ll inc){
	while(s.size()){
		int start = s.back().first;
		ll cnt_l = s.back().second.first;
		ll inc_l = s.back().second.second;

		ll temp = (cnt - cnt_l);
		ll den = inc_l - inc;
		ll val = temp/den;
		if(temp%den) val++;
		val=min(val,1011111111ll);

		if(val<=s.back().first) s.pop_back();
		else {
			s.pb(make_pair((int)val,pl(cnt,inc)));
			break;
		}
	}
}

ll getVal(int pos){
	int v = lower_bound(s.begin(),s.end(), make_pair(pos+1,pl(0,0)))-s.begin();
	v--;
	return s[v].second.first + s[v].second.second * pos;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n) scanf("%d",a+i);
	REP(i,n) scanf("%d",b+i);
	s.pb(make_pair(0, pl(0, b[0])));

	ll best = -1;
	FOR(i,1,n){
		ll res = getVal(a[i]);
		if(i==n-1) best=res;
		addLine(res, b[i]);
	}
	cout<<best<<endl;
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}