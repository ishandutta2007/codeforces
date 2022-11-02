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

string t,p;
int x[222222];
bool u[222222];

bool good(const string& t1, const string& t2){
	int pos = 0;
	if(pos>=t2.size()) return true;
	REP(i,t1.size()){
		if(t1[i]==t2[pos]){
			pos++;
			if(pos>=t2.size()) return true;
		}
	}
	return false;
}

bool solve(int number){
	CL(u,0);
	REP(i,number)u[x[i]]=true;
	string z;
	REP(i,t.size()){
		if(!u[i]) z.pb(t[i]);
	}
	return good(z,p);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	
	cin>>t>>p;
	REP(i,t.size()) scanf("%d",&x[i]),x[i]--;

	int best = 0;
	int from = 1;
	int to = t.size();

	while(from<=to){
		int s = (from +to)/2;
		if(solve(s)) best = s, from=s+1;
		else to = s -1;
	}
	cout<<best<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}