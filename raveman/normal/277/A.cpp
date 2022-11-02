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

bool u[111][111];
int n,m;

bool v[111];
bool hasl=0;

void dfs(int ver){
	if(v[ver]) return;
	v[ver]=true;
	REP(i,m)if(u[ver][i]){
		hasl=true;

		REP(j,n)if(u[j][i])
			dfs(j);
	}
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n){
		int x;
		cin>>x;
		REP(j,x){
			int y;
			cin>>y;
			y--;
			u[i][y]=1;
		}
	}
	vector<bool> vv;
	bool or = 0;
	REP(i,n)if(!v[i]){
		hasl = 0;
		dfs(i);
		or |= hasl;
		vv.pb(hasl);
	}

	if(vv.size()==1) puts("0");
	else{
		if(or) cout<<vv.size()-1<<endl;
		else cout<<vv.size()<<endl;
	}


#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}