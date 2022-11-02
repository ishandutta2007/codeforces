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

string s;
vector<ll> r;
set<pii> u;
bool good(int pos,int add){
	if(u.count(pii(pos,add))) return 0;
	u.insert(pii(pos,add));
	if(pos==s.size()){
		if(add)return 0;
		r.clear();
		REP(i,6)r.pb(0);
		return 1;
	}
	REP(z,7)REP(f,7-z){
		int ss = 6-z-f;
		int xx = f * 4 + ss * 7 + add;
		if(xx%10==s[pos]-'0'){
			if(good(pos+1,xx/10)){
				REP(i,z)r[i]*=10;
				FOR(i,z,z+f)r[i]=r[i]*10+4;
				FOR(i,z+f,6)r[i]=r[i]*10+7;
				return true;
			}
		}
	}
	return 0;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif


	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>s;
		u.clear();
		reverse(s.begin(),s.end());
		if(good(0,0)){
			SORT(r);
			REP(i,r.size()) {if(i)printf(" ");cout<<r[i];}puts("");
		}else puts("-1");
	}
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}