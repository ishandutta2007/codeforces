//#pragma comment(linker, "/STACK:60777216")  

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
typedef pair<int,pii>	p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

string s[333];
int n;

int cost(vector<pii> v, char c){
	int r=0;
	REP(i,v.size())if(s[v[i].first][v[i].second]!=c)r++;
	return r;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n;
		REP(i,n)cin>>s[i];
		vector<pii> v[3];
		REP(i,n)REP(j,n)if(s[i][j]!='.'){
			v[(i+j)%3].pb(pii(i,j));
		}

		int best = n*n;
		int xx,oo;
		REP(x,3)REP(o,3)if(x!=o){
			int c1 = cost(v[x],'X');
			int c2 = cost(v[o],'O');
			c1+=c2;
			if(c1<best){best=c1;xx=x,oo=o;}
		}
		
		REP(i,v[xx].size())s[v[xx][i].first][v[xx][i].second]='X';
		REP(i,v[oo].size())s[v[oo][i].first][v[oo][i].second]='O';
		REP(i,n)cout<<s[i]<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}