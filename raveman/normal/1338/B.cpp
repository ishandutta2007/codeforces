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
typedef pair<int,pii>	p3;
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

int n;
vi v[111111];
int sub;
int no,ne;

void dfs(int ver,int par=-1,int d=0){
	int nl=0;
	REP(i,v[ver].size()){
		if(v[ver][i]==par)continue;
		if(v[v[ver][i]].size()==1) {
			if(d)no++;
			else ne++;
			nl++;
		}else dfs(v[ver][i],ver,d^1);
	}
	sub += max(0, nl-1);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n-1){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
	}

	REP(i,n)if(v[i].size()>1){
		dfs(i);
		break;
	}

	cout<<(no==0 || ne==0 ? 1 : 3)<<' '<<n-1-sub<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}