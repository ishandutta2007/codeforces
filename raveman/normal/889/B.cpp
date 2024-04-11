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

int n;
vector<string> s;

string combine(vector<string> s,int t){
	if(s.empty()) return "";
	vector<char> res(100,' ');
	REP(i,s.size()){
		int pos = 0;
		REP(j,s[i].size())if(s[i][j]-'a'==t)pos=j;
		REP(j,s[i].size()){
			if(res[50+j-pos]!=' ' && res[50+j-pos]!=s[i][j])return "NO";
			res[50+j-pos]=s[i][j];
		}
	}
	string w;
	REP(i,100)if(res[i]!=' ')w.pb(res[i]);
	int mask = 0;
	REP(i,w.size()){
		if(mask&(1<<(w[i]-'a')))return "NO";
		mask|=1<<(w[i]-'a');
	}
	return w;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	string t;
	getline(cin,t);
	REP(i,n){
		getline(cin,t);
		int mask = 0;
		REP(j,t.size()){
			if(mask&(1<<(t[j]-'a'))){
				puts("NO");
				return 0;
			}
			mask|=1<<(t[j]-'a');
		}
		s.pb(t);
	}


	REP(i,26){
		vector<string> ns,tmp;
		REP(j,s.size()){
			bool has = 0;
			REP(k,s[j].size())if(s[j][k]-'a'==i)has=1;
			if(has)tmp.pb(s[j]);
			else ns.pb(s[j]);
		}
		string t= combine(tmp,i);
		if(t=="NO"){
			puts("NO");
			return 0;
		}
		if(!t.empty())ns.pb(t);
		s=ns;
	}
	SORT(s);
	REP(i,s.size())cout<<s[i];
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}