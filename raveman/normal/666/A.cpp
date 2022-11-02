//#pragma comment(linker, "/STACK:60777216")  

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

string s;
set<string> r;
set<string> u[11111];

void go(int pos,string prev){
	if(u[pos].count(prev))return;
	u[pos].insert(prev);
	if(pos-2>=4){
		string t=s.substr(pos-1,2); 
		if(prev!=t){
			r.insert(t);
			go(pos-2,t);
		}
	}
	if(pos-3>=4){
		string t= s.substr(pos-2,3);
		if(prev!=t){
			r.insert(t);
			go(pos-3,t);
		}
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>s;

	go(s.size()-1,"");

	cout<<r.size()<<endl;
	for(set<string>::iterator it = r.begin();it!=r.end();it++){
		printf("%s\n",it->c_str());
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}