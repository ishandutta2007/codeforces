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

	int n;
	cin>>n;
	if(n<4) puts("NO");
	else {
		puts("YES");
		if(n%2==0){
			for(int i=5;i<n;i+=2){
				printf("%d - %d = %d\n",i+1,i,1);
				printf("%d * %d = %d\n",1,1,1);
			}
			puts("1 * 2 = 2");
			puts("2 * 3 = 6");
			puts("6 * 4 = 24");
		}else{
			for(int i=6;i<n;i+=2){
				printf("%d - %d = %d\n",i+1,i,1);
				printf("%d * %d = %d\n",1,1,1);
			}
			puts("5 * 3 = 15");
			puts("2 * 4 = 8");
			puts("8 + 15 = 23");
			puts("23 + 1 = 24");
		}
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}