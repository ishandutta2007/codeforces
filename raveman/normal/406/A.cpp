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

int a[1111][1111];
int c[1111];
int r[1111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	
	int n;
	cin>>n;
	REP(i,n)REP(j,n)scanf("%d",&a[i][j]);
	int sum = 0;
	REP(i,n)REP(j,n)sum+=a[i][j]*a[j][i];
	REP(i,n)REP(j,n)r[i]=(r[i]+a[i][j])%2;
	REP(i,n)REP(j,n)c[i]=(c[i]+a[j][i])%2;
	sum%=2;
	int q,t,w;
	cin>>q;
	REP(i,q){
		scanf("%d",&t);
		if(t==3){
			printf("%d",sum);
		}else if(t==2){
			scanf("%d",&w);
			w--;
			sum = (sum + 1 )%2;
			c[w] = (c[w]+n)%2;
			r[w] = (r[w]+1)%2;
		}else if(t==1){
			scanf("%d",&w);
			w--;
			sum = (sum + 1)%2;
			r[w] = (r[w]+n)%2;
			c[w] = (c[w]+1)%2;
		}
	}
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}