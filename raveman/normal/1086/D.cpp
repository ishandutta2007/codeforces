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

int n,q;
string s;

set<int> t[3];
int sum[3][1<<20];

int getSum(int* s,int from,int to){
	from+=(1<<19);
	to+=(1<<19);
	int res=0;
	while(from<=to){
		if(from&1)res+=s[from];
		if(!(to&1))res+=s[to];
		from=(from+1)>>1;
		to=(to-1)>>1;
	}
	return res;
}

void addVal(int* s,int val,int pos,set<int>& ss){
	if(val==1){
		ss.insert(pos);
	}else{
		ss.erase(pos);
	}
	pos+=(1<<19);
	while(pos){
		s[pos]+=val;
		pos>>=1;
	}
}

void process(char c,int add,int pos){
	if(c=='R')addVal(sum[0],add,pos,t[0]);
	if(c=='S')addVal(sum[1],add,pos,t[1]);
	if(c=='P')addVal(sum[2],add,pos,t[2]);
}

int getFirst(int type){
	if(t[type].empty()) return n;
	return *t[type].begin();
}
int getLast(int type){
	if(t[type].empty()) return -1;
	set<int>::iterator it = t[type].end();
	it--;
	return *it;
}

int solve(int type,pii s1,pii s2){
	int t1 = max(s1.first,s2.first);
	int t2 = min(s1.second,s2.second);
	return getSum(sum[type],t1,t2);
}
int solve_type(int type){
	int killer = (type+2)%3;
	int inf = (type+1)%3;

	int first_killer = getFirst(killer);
	int first_inf = getFirst(inf);

	// beginning
	pii s1(0,first_killer-1);
	pii s2(max(first_killer,first_inf)+1,n-1);
	
	// ending

	int last_killer = getLast(killer);
	int last_inf = getLast(inf);

	pii s3(last_killer+1,n-1);
	pii s4(0,min(last_killer,last_inf)-1);

	int res = 0;

	res += solve(type,s1,s3);
	res += solve(type,s1,s4);
	res += solve(type,s2,s3);
	res += solve(type,s2,s4);
	return res;
}

int solve(){
	int res = 0;
	REP(i,3){
		res += solve_type(i);
	}
	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>q;
	cin>>s;
	REP(i,n){
		process(s[i],1,i);
	}
	printf("%d\n",solve());
	REP(i,q){
		int p;char c;
		scanf("%d %c",&p,&c);
		p--;
		process(s[p],-1,p);
		s[p]=c;
		process(s[p],1,p);
		printf("%d\n",solve());
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}