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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

set<string> s1,s2;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n,m;
	cin>>n>>m;
	string s;
	getline(cin,s);
	REP(i,n){
		getline(cin,s);
		s1.insert(s);
	}
	REP(i,m){
		getline(cin,s);
		s2.insert(s);
	}
	int n1=0,n2=0,nc=0;
	for(set<string>::iterator it = s1.begin();it!=s1.end();it++){
		if(s2.count(*it)) nc++;
		else n1++;
	}
	n2 = s2.size() - nc;
	while(1){
		if(n1+nc==0){puts("NO");return 0;}
		if(nc>0)nc--;
		else n1--;
		if(n2+nc==0){puts("YES");return 0;}
		if(nc>0)nc--;
		else n2--;
	}

	
#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}