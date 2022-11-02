//#pragma comment(linker, "/STACK:60777216")  

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
typedef pair<int,pii>	p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

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

	int tc;
	cin>>tc;
	REP(TC,tc){
		int n,m;
		cin>>n>>m;

		if(n%2==1 && m%2==1){
			REP(i,n){
				REP(j,m){
					if(i==0 || j==0 || i==n-1 ||j==m-1){
						if((i+j)%2==0)printf("1");
						else printf("0");
					}else printf("0");
				}
				puts("");
			}
		}else if(n%2==1){
			REP(i,n){
				REP(j,m){
					if(i==0 || j==0 || i==n-1 ||j==m-1){
						if(j==0 || j==m-1){
							if(i%2==0)printf("1");
							else printf("0");
						}else if(i==0 || i==n-1){
							if(j%2==0 && j+2<m-1)printf("1");
							else printf("0");
						}else printf("0");
					}else printf("0");
				}
				puts("");
			}
		}else if(m%2==1){
			REP(i,n){
				REP(j,m){
					if(i==0 || j==0 || i==n-1 ||j==m-1){
						if(i==0 || i==n-1){
							if(j%2==0)printf("1");
							else printf("0");
						}else if(j==0 || j==m-1){
							if(i%2==0 && i+2<n-1)printf("1");
							else printf("0");
						}else printf("0");
					}else printf("0");
				}
				puts("");
			}
		}else{
			REP(i,n){
				REP(j,m){
					if(i==0 || j==0 || i==n-1 ||j==m-1){
						if(i==0 || i==n-1){
							if(j%2==0)printf("1");
							else printf("0");
						}else if(j==0 || j==m-1){
							if(i%2==0 && i+2<n-1)printf("1");
							else printf("0");
						}else printf("0");
					}else printf("0");
				}
				puts("");
			}
		}
		puts("");
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}