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
typedef pair<double,double>	pdd;
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
int a[333333];

bool good(int mid){
	int prev = 0;
	REP(i,n){
		int from = a[i];
		int to = a[i] + mid;
		if(to>=m){
			int from1 = 0;
			int to1 = to%m;
			to = m-1;

			from1=max(from1,prev);
			if(from1<=to1){
				prev=from1;
				continue;
			}
			from=max(from,prev);
			if(from<=to){
				prev=from;
				continue;
			}else{
				return 0;
			}
		}else{
			from=max(from,prev);
			if(from<=to){
				prev=from;
			}else{
				return 0;
			}
		}
	}
	return 1;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n)scanf("%d",a+i);

	int best=-1;
	int from = 0, to = m;
	while(from<=to){
		int mid = (from+to)/2;
		if(good(mid))best=mid,to=mid-1;
		else from=mid+1;
	}
	cout<<best<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}