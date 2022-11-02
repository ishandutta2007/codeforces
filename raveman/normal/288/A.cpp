#pragma comment(linker, "/STACK:60777216")  

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

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n,k;
	cin>>n>>k;
	if(k>n || k==1 && n>1){
		puts("-1");
		return 0;
	}
	string s;
	REP(i,n) s.pb('a'+(i%2));
	FOR(i,2,k) s[s.size()-k+i]='a'+i;
	cout<<s<<endl;

	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
	return 0;
}