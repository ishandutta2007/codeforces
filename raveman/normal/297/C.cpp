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

int n;
int s[111111];
int a[111111];
int r1[111111];
int r2[111111];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n) scanf("%d",s+i),a[i]=s[i];
	sort(a,a+n);

	int tn = n/3;
	if(tn*3!=n) tn++;

	REP(i,tn){
		r1[i] = 0;
		r2[i] = a[i];
	}
	FOR(j,tn,2*tn){
		r1[j] = a[j];
		r2[j] = 0;
	}
	int  num = n - 2 * tn;
	FOR(j,2*tn,n){
		r1[j] = num - (j-2*tn)-1;
		r2[j] = a[j] - r1[j];
	}


	puts("YES");
	REP(i,n){
		int pos = lower_bound(a,a+n,s[i])-a;
		if(i) printf(" ");
		printf("%d",r1[pos]);
	}
	puts("");
	REP(i,n){
		int pos = lower_bound(a,a+n,s[i])-a;
		if(i) printf(" ");
		printf("%d",r2[pos]);
	}
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}