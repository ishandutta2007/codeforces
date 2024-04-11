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

string s,t;
int n;

int a[2][2];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	getline(cin,s);
	getline(cin,s);
	getline(cin,t);
	REP(i,2*n)
		a[s[i]-'0'][t[i]-'0']++;
	string s1,s2;
	REP(i,n){
		if(a[1][1]){
			s1.pb('1');
			a[1][1]--;
		}else if(a[1][0]){
			s1.pb('1');
			a[1][0]--;
		}else if(a[0][1]){
			s1.pb('0');
			a[0][1]--;
		}else {
			s1.pb('0');
			a[0][0]--;
		}
		if(a[1][1]){
			s2.pb('1');
			a[1][1]--;
		}else if(a[0][1]){
			s2.pb('1');
			a[0][1]--;
		}else if(a[1][0]){
			s2.pb('0');
			a[1][0]--;
		}else {
			s2.pb('0');
			a[0][0]--;
		}
		
	}
	if(s1==s2) puts("Draw");
	else if(s1>s2) puts("First");
	else puts("Second");
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}