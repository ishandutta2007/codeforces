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
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back	

int n,q;
int l[11111];
int r[11111];
int x[11111];
vi  a[11111];

bool u[11111];

const int mod = 1000000007;
int  c[11111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>q;	REP(i,q)cin>>l[i]>>r[i]>>x[i];
	/*n=q=10000;
	REP(i,q){
		l[i]=rand()%n;
		r[i]=rand()%n;
		if(l[i]>r[i])swap(l[i],r[i]);
		l[i]++;
		r[i]++;
		x[i]=rand()%n+1;
	}*/

	REP(i,q){
		l[i]--,r[i]--;
		a[l[i]].pb(x[i]);
		a[r[i]+1].pb(-x[i]);
	}

	c[0]=1;
	REP(i,n){
		REP(j,a[i].size()){
			int t = a[i][j];
			if(t>0){
				for(int j=n+1;j>=t;j--){
					c[j]+=c[j-t];
					if(c[j]>=mod)c[j]-=mod;
				}
			}else{
				t=-t;
				FOR(j,t,n+1){
					c[j]-=c[j-t];
					if(c[j]<0)c[j]+=mod;
				}
			}
		}
		REP(j,n)if(c[j+1])u[j+1]=true;
	}


	int cnt=0;
	REP(i,n)if(u[i+1])cnt++;
	cout<<cnt<<endl;
	REP(i,n)if(u[i+1]){
		cout<<i+1<<" ";
	}
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}