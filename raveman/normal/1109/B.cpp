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

bool ispal(const string& x){
	REP(i,x.size())if(x[i]!=x[x.size()-1-i])return 0;
	return 1;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	
	string s;
	cin>>s;

	int n = s.size();

	if (s == string(n,s[0])) puts("Impossible");
	else{
		bool f = 0;
		FOR(len,1,n){
			string t = s.substr(len,n-len)+s.substr(0,len);
			if(t!=s){
				if(ispal(t)){f=1;break;}
			}
		}
		if(n%2==1 && !f){
			if(s.substr(0,n/2)==string(n/2,s[0])) {
				puts("Impossible");
				return 0;
			}
		}
		puts(f?"1":"2");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}