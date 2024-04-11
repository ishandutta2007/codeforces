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

void parse(const string& s, int &pos){
	while(pos<s.size() && isspace(s[pos])) pos++;
	if(pos<s.size()){
		if(s[pos]=='\"'){
			printf("<");
			pos++;
			while(s[pos]!='\"'){
				printf("%c",s[pos]);
				pos++;
			}
			pos++;
			puts(">");
		}else{
			printf("<");
			while(pos<s.size() && !isspace(s[pos]) && s[pos]!='\"'){
				printf("%c",s[pos]);

				pos++;
			}
			puts(">");
		}
	}
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	string s;
	getline(cin,s);
	int pos = 0;
	while(pos<s.size()) parse(s,pos);

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}