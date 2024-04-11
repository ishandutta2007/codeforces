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

	int n;
	cin>>n;
	vector<pii> v1,v2;
	REP(i,n)REP(j,n)if((i+j)%2==0)v1.pb(pii(i,j));
	else v2.pb(pii(i,j));
	REP(i,n*n){
		int x;
		cin>>x;
		if(v1.empty()){
			cout<<(x==2?3:2)<<" "<<v2.back().first+1<<" "<<v2.back().second+1<<endl;
			cout.flush();
			v2.pop_back();
		}else if(v2.empty()){
			cout<<(x==1?3:1)<<" "<<v1.back().first+1<<" "<<v1.back().second+1<<endl;
			cout.flush();
			v1.pop_back();
		}else{
			if(x==1){
				cout<<"2 "<<v2.back().first+1<<" "<<v2.back().second+1<<endl;
				cout.flush();
				v2.pop_back();
			}else{
				cout<<"1 "<<v1.back().first+1<<" "<<v1.back().second+1<<endl;
				cout.flush();
				v1.pop_back();
			}
		}
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}