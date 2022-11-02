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

int n,t;
int a[111];
int b[111*111];
int sf[111*111][111];
int sb[111*111][111];

void solve1(){
	REP(i,111)sf[0][i]=0;
	REP(it,111)REP(i,n){
		REP(j,111){
			sf[it*n+i+1][j]=0;
			if(j)sf[it*n+i+1][j]=sf[it*n+i+1][j-1];
			sf[it*n+i+1][j]=max(sf[it*n+i+1][j],sf[it*n+i][j]);			
			if(a[i]==j)sf[it*n+i+1][j]=max(sf[it*n+i+1][j],sf[it*n+i][j]+1);
		}
	}
}
void solve2(){
	REP(i,111)sb[0][i]=0;
	REP(it,111)REP(i,n){
		for(int j=100;j>=0;j--){
			sb[it*n+i+1][j]=sb[it*n+i+1][j+1];
			sb[it*n+i+1][j]=max(sb[it*n+i+1][j],sb[it*n+i][j]);
			if(a[n-i-1]==j)sb[it*n+i+1][j]=max(sb[it*n+i+1][j],sb[it*n+i][j]+1);
		}
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>t;
	vi vvv;
	REP(i,n)cin>>a[i],vvv.pb(a[i]);
	UN(vvv);
	REP(i,n)a[i]=lower_bound(vvv.begin(),vvv.end(),a[i])-vvv.begin();

	REP(i,100)REP(j,n)b[i*n+j]=a[j];
	solve1();
	solve2();

	map<int,int> w;
	REP(i,n)w[a[i]]++;

	int best=0;
	for(map<int,int>::iterator it = w.begin();it!=w.end();it++){
		int val = it->first;
		int num = it->second;
		REP(i1,min(100,t)+1)REP(i2,min(100,t)+1)if(i1+i2<=t){
			int c = t - i1 - i2;
			best=max(best,c*num+sf[i1*n][val]+sb[i2*n][val]);
		}
	}

	cout<<best<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}