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

int n,m;
string s[444];

int a[444][444];

int solve(int x1,int y1,int x2,int y2,int t){
	int total = (x2-x1+1)*(y2-y1+1);
	int sum = a[x2][y2] - (x1-1>=0?a[x1-1][y2]:0) - (y1-1>=0?a[x2][y1-1]:0) + (x1-1>=0 && y1-1>=0?a[x1-1][y1-1]:0);
	if(t==1)sum=total-sum;
	return sum;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n>>m;
		REP(i,n)cin>>s[i];
		CL(a,0);
		REP(i,n){
			REP(j,m){
				a[i][j]=s[i][j]-'0';
				if(i)a[i][j]+=a[i-1][j];
				if(j)a[i][j]+=a[i][j-1];
				if(i&&j)a[i][j]-=a[i-1][j-1];
			}
		}
		int best=n*m;
		REP(i,n)REP(j,m){
			for(int a=5;;a++){
				if(i+a>n)break;
				for(int b=4;;b++){
					if(j+b>m)break;
					int l = solve(i+1,j,i+a-2,j,1);
					int r = solve(i+1,j+b-1,i+a-2,j+b-1,1);
					int t = solve(i,j+1,i,j+b-2,1);
					int bot = solve(i+a-1,j+1,i+a-1,j+b-2,1);
					int midd = solve(i+1,j+1,i+a-2,j+b-2,0);

					if(best<=l+t+bot+midd)break;
					best=min(best,l+r+t+bot+midd);
				}
			}
		}
		cout<<best<<endl;
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}