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

int n,a,b;
int p[111111];
set<int> c;
set<int> u;
set<int> g1,g2;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>a>>b;
	REP(i,n)scanf("%d",p+i),c.insert(p[i]);
	bool good = 1;
	if(a==b){
		REP(i,n)if(!c.count(a-p[i])){good=0;break;}
	}else{
		REP(i,n){
			if(u.count(p[i])) continue;

			int start = p[i];
			set<int> s;
			int t = start;
			int l1=a,l2=b;
			while(1){
				s.insert(t);
				u.insert(t);
				t=l1-t;
				if(!c.count(t) || s.count(t)) break;
				swap(l1,l2);
			}
			t=start;
			l1=b,l2=a;
			while(1){
				s.insert(t);
				u.insert(t);
				t=l1-t;
				if(!c.count(t) || s.count(t)) break;
				swap(l1,l2);
			}
			bool gooda=1,goodb=1;
			for(set<int>::iterator it = s.begin();it!=s.end();++it){
				if(!s.count(a-(*it))) gooda=0;
				if(!s.count(b-(*it))) goodb=0;
			}
			if(gooda){
			}else if(goodb){
				for(set<int>::iterator it = s.begin();it!=s.end();++it){
					g2.insert(*it);
				}
			}else {good=0;break;}
		}
	}
	if(!good){
		puts("NO");
	}else {
		puts("YES");
		REP(i,n){
			if(i)printf(" ");
			printf("%d",(g2.count(p[i])?1:0));
		}
		puts("");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}