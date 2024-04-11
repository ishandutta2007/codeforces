#pragma comment(linker, "/STACK:60777216")  

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
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,p;
int t[111111];
ll r[111111];

set<int> w;
queue<int> line;
set<int> line_set;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>p;
	vector<pii> a;
	REP(i,n)scanf("%d",t+i),a.pb(pii(t[i],i));
	SORT(a);
	reverse(a.begin(),a.end());
	ll currtime=-1;
	REP(i,n){
		while(!w.empty() && (line.empty() || (*w.begin())<(*line_set.begin()))){
			line.push(*w.begin());
			line_set.insert(*w.begin());
			w.erase(w.begin());
		}
		if(line.empty()){
			currtime=max(currtime,ll(a.back().first));
			line.push(a.back().second);
			line_set.insert(a.back().second);
			a.pop_back();
		}

		ll nexttime = currtime + p;

		while(!a.empty() && a.back().first <= nexttime){
			if((*line_set.begin())>a.back().second){
				line.push(a.back().second);
				line_set.insert(a.back().second);
				a.pop_back();
				continue;
			}
			
			w.insert(a.back().second);
			a.pop_back();
		}

		int val = line.front();line.pop();
		line_set.erase(val);
		currtime=nexttime;
		r[val]=currtime;
	}

	REP(i,n)cout<<r[i]<<' ';
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}