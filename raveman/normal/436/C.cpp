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

int d[1111][1111];
string s[1111][11];
bool u[1111];
int closest[1111];
int pos[1111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n,m,k,w;
	cin>>n>>m>>k>>w;
	REP(i,k){
		REP(j,n)cin>>s[i][j];
	}
	REP(i,k)REP(j,i){
		int cost = 0;
		REP(x1,n)REP(x2,m)if(s[i][x1][x2]!=s[j][x1][x2])cost++;
		cost*=w;
		d[i][j]=d[j][i]=cost;
	}

	int cost = 0;
	vector<pii> order;
	REP(i,k)closest[i]=n*m,pos[i]=-1;
	REP(i,k){
		int best = -1;
		REP(j,k)if(!u[j]) if(best==-1 || closest[best]>closest[j]) best = j;
		order.pb(pii(best,pos[best]));
		cost += closest[best];
		u[best]=true;
		//cout<<best<<endl;
		REP(j,k)if(closest[j]>d[best][j])closest[j]=d[best][j],pos[j]=best;
	}

	cout<<cost<<endl;
	REP(i,order.size())printf("%d %d\n",order[i].first+1,order[i].second+1);

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}