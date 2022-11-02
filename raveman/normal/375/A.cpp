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

	string s;
	getline(cin,s);
	string t = "1689";
	REP(i,s.size()) if(s[i]=='1') {s.erase(s.begin()+i);break;}
	REP(i,s.size()) if(s[i]=='6') {s.erase(s.begin()+i);break;}
	REP(i,s.size()) if(s[i]=='8') {s.erase(s.begin()+i);break;}
	REP(i,s.size()) if(s[i]=='9') {s.erase(s.begin()+i);break;}
	sort(s.begin(),s.end());
	reverse(s.begin(),s.end());
	int val = 0;
	REP(i,s.size())val=(10*val+s[i]-'0')%7;
	do{
		int z = val;
		REP(i,t.size()) z=10*z +t[i]-'0';
		if(z%7==0) break;
	}while(next_permutation(t.begin(),t.end()));
	if(s.size()==0) cout<<t<<endl;
	else if(s[0]=='0') cout<<t<<s<<endl;
	else cout<<s<<t<<endl;

#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}