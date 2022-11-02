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

double res;
int n;
void go(vi p, double pr,int st){
	if(st==0){
		int numinv = 0;
		REP(i,n)REP(j,i)if(p[i]<p[j])numinv++;
		res+=numinv*pr;
		//REP(i,p.size()) cout<<p[i]<<' ';puts("");
		//cout<<numinv<<' '<<pr<<endl;
	}else{
		vector<pii> v;
		REP(i,n)REP(j,i+1)v.pb(pii(j,i));
		REP(w,v.size()){
			vi t=p;
			reverse(t.begin()+v[w].first,t.begin()+v[w].second+1);
			go(t,pr/v.size(),st-1);
		}
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int k;
	cin>>n>>k;
	vi p(n);
	REP(i,n)cin>>p[i];
	go(p,1,k);
	printf("%.10lf\n",res);

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}