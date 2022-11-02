#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

int n;
char s[5555][5555];

bool solve(vi v){
	if(v.size()<3) return 0;
	vi t1,t2;
	int ver = v[0];
	FOR(i,1,v.size()) if(s[v[i]][ver]=='1') t1.pb(v[i]);
	else t2.pb(v[i]);

	REP(i1,t1.size()) REP(i2,t2.size()) if(s[t2[i2]][t1[i1]]=='1'){
		cout<<ver+1<<' '<<t2[i2]+1<<' '<<t1[i1]+1<<endl;
		return true;
	}
	if(solve(t1)) return true;
	if(solve(t2)) return true;
	return false;
}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n) scanf(" %s",s[i]);
	vi v;
	REP(i,n) v.pb(i);
	random_shuffle(v.begin(),v.end());
	if(!solve(v)) puts("-1");

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}