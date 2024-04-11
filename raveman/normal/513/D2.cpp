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

int n,c;
set<int> sl[1111111];
set<int> sr[1111111];

int LN[1111111];
int RN[1111111];

void print_tree(int pos){
	if(LN[pos]!=-1) print_tree(LN[pos]);
	printf("%d ",pos);
	if(RN[pos]!=-1) print_tree(RN[pos]);
}

int START;

bool go(bool force,int MN=-1){
	//cout<<START<<' '<<force<<' '<<MN<<endl;
	if(START>n+1)return false;
	int ver = START;
	START++;
	if (START == n + 1) {
		if(!(sl[ver].empty() && sr[ver].empty())) return false;
		return true;
	}
		
	if(sl[ver].empty() && sr[ver].empty() && MN<START){
		if(!force) return true;
		RN[ver] = START;
		return go(force);
	}
	
	if(!sl[ver].empty()){
		LN[ver] = START;
		if(*(--sl[ver].end())<START) return false;
		if(!go(false,*(--sl[ver].end()))) return false;
	}

	//cout<<ver<<" here"<<endl;
	
	if(sr[ver].empty()){
		if(force || MN>=START){
			if(START==n+1)return true;
			RN[ver] = START;
			if(!go(force,MN)) return false;
		}
	}else{
		//cout<<*(sr[ver].begin())<<' '<<START<<endl;
		RN[ver] = START;
		if(*(sr[ver].begin()) < START) return false;
		if(*(--sr[ver].end()) < START) return false;
		if(!go(force,max(MN,*(--sr[ver].end())))) return false;
	}
	//cout<<ver<<" here2"<<endl;
	return true;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>c;
	char _s[10];
	REP(i,c){
		int a,b;
		scanf("%d %d %s",&a,&b,_s);
		if(a>=b){
			puts("IMPOSSIBLE");
			return 0;
		}
		if(_s[0]=='L')sl[a].insert(b);
		else sr[a].insert(b);
	}
	CL(LN,-1);
	CL(RN,-1);
	START=1;
	if(!go(1)){
		puts("IMPOSSIBLE");
	}else{
		if (START != n+1)puts("IMPOSSIBLE");
		else print_tree(1);
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}