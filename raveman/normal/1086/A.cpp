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

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int x[3],y[3];
	REP(i,3)cin>>x[i]>>y[i];
	vector<pii> w;
	REP(i,3)REP(j,3)REP(tp,2)if(i!=j){
		vector<pii> t;
		int x1 = x[i], y1 = y[i];
		t.pb(pii(x1,y1));

		while(x1!=x[j] || y1!=y[j]){
			if(tp==0){
				if(x1!=x[j])x1+=(x[j]>x1?1:-1);
				else y1 += (y[j]>y1?1:-1);
			}else{
				if(y1!=y[j])y1+=(y[j]>y1?1:-1);
				else x1 += (x[j]>x1?1:-1);
			}
			t.pb(pii(x1,y1));
		}
		int bt = 0;
		REP(q,t.size()){
			if(abs(t[bt].first-x[3-i-j])+abs(t[bt].second-y[3-i-j])>abs(t[q].first-x[3-i-j])+abs(t[q].second-y[3-i-j]))bt=q;
		}
		x1 = t[bt].first;
		y1 = t[bt].second;
		while(x1!=x[3-i-j] || y1!=y[3-i-j]){
			if(x1!=x[3-i-j])x1 += (x[3-i-j]>x1?1:-1);
			else y1 += (y[3-i-j]>y1?1:-1);
			t.pb(pii(x1,y1));
		}
		if(w.size() == 0 || w.size()>t.size()) w=t;
	}

	cout<<w.size()<<endl;
	REP(i,w.size()) cout<<w[i].first<<' '<<w[i].second<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}