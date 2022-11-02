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

int n,m,k;
int a[111][111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>k;
	REP(i,n)REP(j,m)cin>>a[i][j];
	int best = k + 1;
	if(n<=10){
		REP(mask,1<<n){
			int sum = 0;
			REP(j,m){
				int n1 = 0, n2 = 0;
				REP(i,n){
					if(a[i][j] == ((mask&(1<<i)) ? 1 : 0)) n2++;
					else n1++;
				}
				sum += min(n1,n2);
			}
			best = min(best,sum);
		}
	}else{
		REP(real,n){
			int sum=0;
			REP(i,n){
				int n1=0,n2=0;
				REP(j,m){
					if(a[real][j]==a[i][j])n2++;
					else n1++;
				}
				sum += min(n1,n2);
			}
			best=min(best,sum);
		}
	}
	if(best<=k) cout<<best<<endl;
	else puts("-1");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}