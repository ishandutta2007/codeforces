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

int n,m;
int x[111111];
ll  y[111111];

int d[111111];
int p[20][111111];

int lca(int a,int b){
	if(d[a]<d[b])swap(a,b);
	for(int j=19;j>=0;j--)
		if(d[a]-(1<<j)>=d[b])a=p[j][a];
	while(d[a]!=d[b]);
	if(a==b)return a;
	for(int j=19;j>=0;j--)
		if(p[j][a]!=p[j][b])a=p[j][a],b=p[j][b];
	return p[0][a];
}

bool cansee(int v1,int v2,int v3){
	return (x[v2]-x[v1])*(y[v3]-y[v1])-(x[v3]-x[v1])*(y[v2]-y[v1])>0;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)scanf("%d %I64d",x+i,y+i);

	d[n-1]=1;
	p[0][n-1]=n-1;
	
	for(int i=n-2;i>=0;i--){
		p[0][i]=i+1;

		while(1){
			int next = p[0][i];
			int nnext = p[0][next];
			if(next==nnext) break;
			if(cansee(i,next,nnext)) p[0][i]=nnext;
			else break;
		}

		//cout<<i<<' '<<p[0][i]<<endl;
		d[i]=d[p[0][i]]+1;
	}

	FOR(i,1,20)REP(j,n)p[i][j]=p[i-1][p[i-1][j]];
	cin>>m;
	int a,b;
	REP(i,m){
		scanf("%d %d",&a,&b);a--,b--;
		if(i)printf(" ");
		printf("%d",lca(a,b)+1);
	}
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}