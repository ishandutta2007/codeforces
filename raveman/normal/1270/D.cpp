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



int main(){	
#ifdef LocalHost
//	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n,k;
	cin>>n>>k;
	map<pii,int> tw;
	REP(i,k+1){
		cout<<"?";
		REP(j,k+1){
			if(j==i)continue;
			cout<<' '<<j+1;
		}
		cout<<endl;
		cout.flush();
		int pos,apos;
		cin>>pos>>apos;
		tw[pii(apos,pos)]++;
	}
	if(tw.size()!=2) puts("FUCK");
	map<pii,int>::iterator it = tw.begin();
	it++;
	cout<<"! "<<it->second<<endl;
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}