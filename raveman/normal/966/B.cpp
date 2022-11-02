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

int n,x1,x2;
int c[333333];
vector<pii> v;

bool solve(int x1,int x2,int type){
	for(int i=n-1;i>=0;i--){
		ll total = v[i].first * ll(n - i);
		if (total>=x1){
			for(int j=i-1;j>=0;j--){
				ll total2 = v[j].first * ll(i-j);
				if(total2 >= x2){
					puts("Yes");

					if(type==0){
						cout<<n-i<<' '<<i-j<<endl;
						REP(w1,n-i)printf("%d ",v[i+w1].second+1);puts("");
						REP(w1,i-j)printf("%d ",v[j+w1].second+1);puts("");
					}else{
						cout<<i-j<<' '<<n-i<<endl;
						REP(w1,i-j)printf("%d ",v[j+w1].second+1);puts("");
						REP(w1,n-i)printf("%d ",v[i+w1].second+1);puts("");
					}
					return 1;
				}
			}
			break;
		}
	}
	return 0;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>x1>>x2;
	REP(i,n)scanf("%d",c+i);
	REP(i,n)v.pb(pii(c[i],i));
	SORT(v);

	if(solve(x1,x2,0));
	else if(solve(x2,x1,1));
	else puts("No");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}