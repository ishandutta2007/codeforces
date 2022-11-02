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

int n;
int pos[111111];
set<int> s;
int val[222222];
char  t[222222];
int   x[222222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,2*n){
		scanf(" %c",&t[i]);
		if(t[i]=='+'){
			s.insert(i);
		}else{
			scanf("%d",&x[i]);x[i]--;
			pos[x[i]]=i;
		}
	}
	REP(i,n){
		set<int>::iterator it = s.lower_bound(pos[i]);
		if(it==s.begin()){
			puts("NO");
			return 0;
		}
		it--;
		val[*it] = i;
		s.erase(it);
	}

	s.clear();
	REP(i,2*n){
		if(t[i]=='+'){
			s.insert(val[i]);
		}else{
			if((*s.begin())!=x[i]){
				puts("NO");
				return 0;
			}
			s.erase(s.begin());
		}
	}
	puts("YES");
	REP(i,2*n)if(t[i]=='+')printf("%d ",val[i]+1);puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}