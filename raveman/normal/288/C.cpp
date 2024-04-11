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

ll n;
int a[1111111];

void solve(int n){
	if(n<=0) return;
	for(int i=25;i>=0;i--)if(n&(1<<i)){
		int x = (1<<i);
		int prev = x - 1;
		while(x<=n){
			a[x] = prev;
			a[prev] = x;
			prev--;
			x++;
		}
		solve(prev);
		break;
	}
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;

	cout<<n*(n+1)<<endl;
	solve(n);
	REP(i,n+1){
		if(i) printf(" ");
		printf("%d",a[i]);
	}
	puts("");
	ll c=0;
	REP(i,n+1)c+=(a[i]^i);
	//cout<<c<<endl;

	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
	return 0;
}