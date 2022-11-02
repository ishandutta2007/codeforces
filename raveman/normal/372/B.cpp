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
string s[44];
int sum[44][44];
int r[41][41][41][41];

int go(int a,int b,int c,int d){
	if(a>c || b>d) return 0;
	if(r[a][b][c][d]!=-1) return r[a][b][c][d];
	int val = 0;
	val += go(a+1,b,c,d);
	val += go(a,b,c-1,d);
	val -= go(a+1,b,c-1,d);

	for(int i=b;i<=d;++i){
		//cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<i<<endl;
		int j = i;
		while (j<=d && sum[c][j] - (j?sum[c][j-1]:0) - (a?sum[a-1][j]:0) + (a&&j?sum[a-1][j-1]:0)==0) ++j;
		//cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<i<<' '<<j<<' '<<sum[c][j]<<' '<<(j?sum[c][j-1]:0)<<' '<<(b?sum[b-1][j]:0)<<endl;
		val += (j-i)*(j-i+1)/2;
		i=j;
	}
	
	//if(sum[c][d]-(b?sum[c][b-1]:0)-(a?sum[a-1][d]:0)+(a&&b?sum[a-1][b-1]:0)==0) val++;
	return r[a][b][c][d]=val;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	int q;
	cin>>n>>m>>q;
	REP(i,n)cin>>s[i];
	REP(i,n)REP(j,m)sum[i][j]=(s[i][j]=='1'?1:0)+(i?sum[i-1][j]:0)+(j?sum[i][j-1]:0)-(i&&j?sum[i-1][j-1]:0);
	CL(r,-1);
	int a,b,c,d;
	REP(i,q){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		a--,b--,c--,d--;
		printf("%d\n",go(a,b,c,d));
	}
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}