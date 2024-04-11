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



int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		int n,m;
		string s[55];
		cin>>n>>m;
		REP(i,n)cin>>s[i];
		bool r0=0,r1=0,w0=0,w1=0;
		REP(i,n)REP(j,m){
			if(s[i][j]=='R'){
				if((i+j)%2==0)r0=1;
				else r1=1;
			}
			if(s[i][j]=='W'){
				if((i+j)%2==0)w0=1;
				else w1=1;
			}
		}
		if((w0 && w1) || (r0 && r1) || (r0 && w0) || (r1 && w1))puts("NO");
		else{
			bool t = 0;
			if(r1 || w0)t=1;
			puts("YES");
			REP(i,n){
				REP(j,m){
					if(t){
						printf("%c",((i+j)%2==0)?'W':'R');
					}else{
						printf("%c",((i+j)%2==1)?'W':'R');
					}
				}
				puts("");
			}
		}
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}