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

int x[111111];
int y[111111];
int n;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	vector<pair<pii,int>> t;
	REP(i,n)scanf("%d %d",x+i,y+i),t.pb(make_pair(pii(x[i],y[i]),i+1));
	SORT(t);
	int p1 = t[0].second;
	int p2 = t[1].second;
	int p3 = -1;
	ll b=-1;
	FOR(j,2,n){
		ll s = (t[j].first.first-t[0].first.first)*ll(t[1].first.second-t[0].first.second)-(t[j].first.second-t[0].first.second)*ll(t[1].first.first-t[0].first.first);
		if (s==0) continue;
		if(s<0)s=-s;
		if(p3==-1 || b > s){
			b=s;
			p3=t[j].second;
		}
	}

	cout<<p1<<' '<<p2<<' '<<p3<<endl;

	
	
#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}