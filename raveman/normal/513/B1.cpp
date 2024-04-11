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

int a[111];

void go(int from,int to,ll m,int start){
	if(from>to)return;
	int num = to - from + 1;
	ll total = 1ll<<num;
	total/=2;
	if(total==0)total=1;
	total/=2;
	if(total==0)total=1;

	for(int i=0;;i++){
		if(m<=total){
			a[from]=start+i;
			for(int j=0;j<i;j++){
				a[to]=start+j;
				to--;
			}
			go(from+1,to,m,start+i+1);
			break;
		}
		m-=total;
		total/=2;
		if(total==0)total=1;
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	ll m;
	cin>>n>>m;

	go(0,n-1,m,1);
	REP(i,n){
		if(i)printf(" ");
		cout<<a[i];
	}
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}