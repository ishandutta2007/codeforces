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

const int mod = 1000000007;
int n,k;
int a[10];
ll res = 0;

void go(int pos,int good=0){
	if(pos==k){
		while(1){
			int prev = good;
			FOR(j,1,k)if(good&(1<<a[j]))good|=(1<<j);
			if(prev==good) break;
		}
		if(a[0]==0) good|=1;
		if(good&(1<<a[0])) good|=1;
		if(good==(1<<k)-1) res++;
	}else{
		REP(i,k){
			a[pos] = i;
			go(pos+1,good|(pos>0&&i==0?(1<<pos):0));
		}
	}
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	go(0);

	REP(i,n-k) res *= (n-k), res %= mod;
	cout<<res<<endl;
	
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
	return 0;
}