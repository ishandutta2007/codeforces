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

int n;
int a[111111];
int r[111111];

int go(int p){
	if(r[p]!=-1)return r[p];
	for(int i=1;i*a[p]<=n;i++){
		int p1 = p - i * a[p];
		int p2 = p + i * a[p];
		if (p1>=0 && p1<n && a[p1] > a[p]){
			if (go(p1) == 0) return r[p]=1;
		}
		if (p2>=0 && p2<n && a[p2] > a[p]){
			if (go(p2) == 0) return r[p]=1;
		}
	}
	return r[p]=0;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	CL(r,-1);
	cin>>n;
	REP(i,n)scanf("%d",a+i);
	REP(i,n)printf("%c","BA"[go(i)]);
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}