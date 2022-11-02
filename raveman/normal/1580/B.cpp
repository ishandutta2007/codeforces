#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<cstring>
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
typedef pair<int,pii>	p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int p;
ll f[111];
ll c[111][111];
int d[111][111][111];

int solve(int n,int m,int k){
	if(k==0){
		if(m>n)return f[n];
	}
	if(m<1 || k<0  || m>n || k>n)return 0;
	if(n==1) return (k==1?1:0);
	if(m==1) return (k==1?f[n]:0); 
	if(d[n][m][k]!=-1)return d[n][m][k];
	ll res=0;
	REP(i,n){
		int c1 = i;
		int c2 = n-1-i;

		if(c1==0 || c2==0){
			res = (res+solve(n-1,m-1,k))%p;
		}else{
			REP(j,k+1)if(j<=c1 && k-j<=c2) res = (res + ((c[c1+c2][c1] * solve(c1,m-1,j))%p)*solve(c2,m-1,k-j))%p;
		}
	}
	return d[n][m][k]=res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	int n,m,k;
	cin>>n>>m>>k>>p;
	if(p==1){
		puts("0");
		return 0;
	}
	f[0]=1;
	FOR(i,1,111)f[i]=(f[i-1]*i)%p;
	REP(i,111){
		c[i][i]=c[i][0]=(1%p);
		FOR(j,1,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
	}
	CL(d,-1);
	cout<<solve(n,m,k)<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}