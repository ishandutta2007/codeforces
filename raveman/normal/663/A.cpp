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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back



int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	string s;
	vi v;
	bool plus=true;
	while(cin>>s){
		if(s=="="){
			break;
		}
		if(s=="-") plus=false;
		if(s=="+") plus=true;
		if(s=="?")v.pb(plus?1:-1);
	}
	int n;
	cin>>n;

	int np=0;
	int nm=0;
	REP(i,v.size())if(v[i]==1)np++;else nm++;
	int from = np;
	int to = np * n;
	from -= nm * n;
	to -= nm;
	if(from<=n && n<=to){
		puts("Possible");
		int sum=0;
		REP(i,v.size()){
			if(v[i]>0)np--;
			else nm--;
			if(i) printf(" %c ",v[i]==1?'+':'-');
			for(int j=1;j<=n;j++){
				from = sum + v[i] * j + np;
				to = sum + v[i] * j + np * n;
				from -= nm * n;
				to -= nm;
				if(from<=n && n<=to){
					cout<<j;
					sum+=j*v[i];
					break;
					
				}
			}
		}
		cout<<" = " << n<<endl;
	}else{
		puts("Impossible");
	}

#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}