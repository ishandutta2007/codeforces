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

int n;
int a[111];
int r[111*111][111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n){
		int x;
		cin>>x;
		a[x]++;
	}

	r[0][0]=1;
	int t,val;
	REP(i,111)if(t=a[i]){
		for(int sum=100*100;sum>=0;sum--)for(int k=100;k>=0;k--)if(val=r[sum][k]){
			FOR(j,1,t+1){
				int& z = r[sum+i*j][k+j];
				z+=val;
				if(z>=2)z=2;
			}
		}
	}
	//REP(i,111*111)REP(j,111)if(r[i][j])cout<<i<<' '<<j<<": "<<r[i][j]<<endl;

	int res = 1;
	REP(i,111)if(a[i]>1){
		FOR(j,2,a[i]+1){
			if(r[i*j][j]==1) res=max(res,j);
		}
	}
	REP(i,111)REP(j,i)if(a[i]+a[j]==n)res=n;
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}