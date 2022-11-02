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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int n,k;
int s[1<<21];

void add(int p){
	p+=1<<20;
	while(p){
		s[p]++;
		p>>=1;
	}
}
ll getSum(int p1,int p2){
	p1+=(1<<20);
	p2+=(1<<20);
	ll sum=0;
	while(p1<=p2){
		if(p1&1)sum+=s[p1];
		if(!(p2&1))sum+=s[p2];
		p1=(p1+1)>>1;
		p2=(p2-1)>>1;
	}
	return sum;
}


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	k = min(k, n-k);
	ll sum=1;
	ll start=0;
	REP(i,n){
		ll end = start + k;
		if(end>=n)end-=n;
		sum++;
		if(end>start)sum+=getSum(start+1,end-1);
		else{
			sum += getSum(start+1,n-1);
			sum += getSum(0,end-1);
		}
		if(i)printf(" ");
		printf("%I64d",sum);
		add(start);
		add(end);
		start=end;
	}
	puts("");

	
#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}