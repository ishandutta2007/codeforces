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

int n,m,d;
int a[333],b[333],t[333];

ll r1[150555];
ll r2[150555];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	ll res = 0;
	cin>>n>>m>>d;
	REP(i,m) cin>>a[i]>>b[i]>>t[i],res += b[i],a[i]--;

	int prev = -n;
	for(int i=0;i<m;){
		int j = i;
		vi v;
		while(j<m && t[i]==t[j])v.pb(a[j]),++j;
		SORT(v);

		int pos = 0;
		ll currdiff = 0;
		REP(w,v.size()) currdiff -= v[w];

		ll diff = (t[i] - prev) * ll(d);
		memcpy(r1,r2,sizeof r1);

		ll from = -diff;
		ll to = diff;

		deque<pair<ll,int>> q;
		REP(ww,n)if(ww>=from && ww<=to){
			while(!q.empty() && q.back().first<=r1[ww]) q.pop_back();
			q.push_back(make_pair(r1[ww],ww));
		}
		//REP(w,n)cout<<r1[w]<<' ';puts("");
		//cout<<"!"<<diff<<' '<<q.size()<<' '<<q.front().first<<' '<<q.back().first<<endl;
		REP(w,n){
			//cout<<q.front().first<<endl;
			r2[w] = currdiff+q.front().first;

			while(pos<v.size() && v[pos]<=w)pos++;
			currdiff -= pos;
			currdiff += (v.size() - pos);

			
			if(from>=0 && from<n && q.front().second==from)q.pop_front();

			from++;
			to++;

			if(to>=0 && to<n){
				while(!q.empty() && q.back().first<=r1[to]) q.pop_back();
				q.push_back(make_pair(r1[to],to));
			}
		}

		prev = t[i];
		i=j;
	}

	ll best = -1e18;
	REP(i,n)best=max(best,r2[i]);
	cout<<res+best<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}