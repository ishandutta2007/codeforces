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

const int mod = 1000000007;

int d[5555][5555];
int s[5555];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n,a,b,k;
	cin>>n>>a>>b>>k;
	a--,b--;
	d[a][0]=1;
	FOR(i,1,k+1){
		s[0]=d[0][i-1];
		FOR(j,1,5555){
			s[j]=s[j-1]+d[j][i-1];
			if(s[j]>=mod)s[j]-=mod;
		}
		REP(j,n){
			if (j > b){
				int x = (j+b)/2;
				while(2*x<=j+b)x++;
				while(2*(x-1)>j+b)x--;
				d[j][i] = s[n-1]-(x-1>=0?s[x-1]:0);
				if(d[j][i]<0)d[j][i]+=mod;
				d[j][i]-=d[j][i-1];
				if(d[j][i]<0)d[j][i]+=mod;
			}else if(j<b){
				int x = (j+b)/2;
				while(2*x>=j+b)x--;
				while(2*(x+1)<j+b)x++;
				d[j][i] = s[x];
				d[j][i]-=d[j][i-1];
				if(d[j][i]<0)d[j][i]+=mod;
			}
		}
	}
	int sum = 0;
	REP(i,n){
		sum+=d[i][k];
		if(sum>=mod)sum-=mod;
	}
	cout<<sum<<endl;
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}