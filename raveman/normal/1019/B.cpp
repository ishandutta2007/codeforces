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
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back	


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	if (n%4!=0) puts("! -1");
	else{
		int from = 1;
		int to = n/2-1;

		bool d = 0;
		bool f = 1;

		while(1){
			int m = (from+to)/2;
			if(f)m=0;

			cout<<"? "<<m+1<<endl;
			int x;
			cin>>x;
			cout<<"? "<<m+1+n/2<<endl;
			int y;
			cin>>y;
			if(x==y){
				cout<<"! "<<m+1<<endl;
				break;
			}
			if (f){
				f=0;
				if(x<y)d=1;
				else d=0;
				continue;
			}
			if(x<y ^ (d==0)){
				from=m+1;
			}else{
				to=m-1;
			}
		}
	}
	
#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}