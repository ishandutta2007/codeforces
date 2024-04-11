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
int a[5555];
int v_a[5555];
int b[5555];
int g[5555];
int v_g[5555];
set<int> bad;

int gcd(int a,int b){
	while(a&&b)
		if(a>b)a%=b;
		else b%=a;
	return a+b;
}
int calc(int val){
	int res = 0;
	for(int i=2;i*i<=val;i++){
		while(val%i==0){
			res += (bad.count(i)?-1:1);
			val/=i;
		}
	}
	if(val>1) res += (bad.count(val)?-1:1);
	return res;
}

int r[5555][5555];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n)scanf("%d",a+i);
	REP(i,m)scanf("%d",b+i),bad.insert(b[i]);
	REP(i,n)v_a[i]=calc(a[i]);
	REP(i,n){
		g[i]=a[i];
		if(i)g[i]=gcd(g[i],g[i-1]);
		v_g[i]=calc(g[i]);
	}
	g[n]=1;
	v_g[n]=0;
	const int inf = 1e9;
	REP(i,n+1)REP(j,n+1)r[i][j]=-inf;
	r[n][n]=0;
	for(int i=n-1;i>=0;i--){
		for(int j=i+1;j<=n;j++){
			r[i][j]=max(r[i][j],r[i+1][j]+(v_a[i]-v_g[j]));
			r[i][i]=max(r[i][i],r[i+1][j]+(v_a[i]-v_g[i]));
		}
	}
	//cout<<r[n-1][n-1]<<endl;
	int res = -inf;
	REP(j,n+1)res=max(res,r[0][j]);
	cout<<res<<endl;
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}