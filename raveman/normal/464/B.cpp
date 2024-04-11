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

int x[8][3];

bool good(){
	vector<ll> r;
	REP(i,8){
		r.clear();
		REP(j,8)if(i!=j){
			r.pb((x[i][0]-x[j][0])*ll(x[i][0]-x[j][0])+(x[i][1]-x[j][1])*ll(x[i][1]-x[j][1])+(x[i][2]-x[j][2])*ll(x[i][2]-x[j][2]));
		}
		SORT(r);
		if(r[0]==0) return false;
		if(r[0]!=r[2]) return false;
		if(r[3]!=r[5]) return false;
		if(r[0]*2!=r[3]) return false;
		if(r[0]*3!=r[6]) return false;
	}
	return true;
}

bool dfs(int pos){
	if(pos==8){
		if(good()){
			puts("YES");
			REP(i,8){
				cout<<x[i][0]<<' '<<x[i][1]<<' '<<x[i][2]<<endl;
			}
			return true;
		}
		return false;
	}
	sort(x[pos],x[pos]+3);
	do{
		if(dfs(pos+1)) return true;
	}while(next_permutation(x[pos],x[pos]+3));
	return false;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	REP(i,8){
		REP(j,3)cin>>x[i][j];
		sort(x[i],x[i]+3);
	}
	if(!dfs(1)) {
		puts("NO");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}