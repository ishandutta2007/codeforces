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

int n,m;
string s[2222];
int res[2222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int k;
	cin>>n>>m>>k;
	REP(i,n){
		cin>>s[i];
		REP(j,m)if(s[i][j]!='.'){
			if(s[i][j]=='R'){
				if(i+j<m){
					res[i+j]++;
				}
			}
			if(s[i][j]=='L'){
				if(j-i>=0){
					res[j-i]++;
				}	
			}
			if(s[i][j]=='U') {
				if(i%2==0)res[j]++;
			}
			if(s[i][j]=='D') continue;

		}
	}
	REP(i,m){
		if(i)printf(" ");
		printf("%d",res[i]);
	}
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}