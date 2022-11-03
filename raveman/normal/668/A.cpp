//#pragma comment(linker, "/STACK:60777216")  

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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

pii a[111][111];
int r[111][111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n,m,q;
	cin>>n>>m>>q;
	REP(i,n)REP(j,m)a[i][j]=pii(i,j);
	REP(i,q){
		int t;
		cin>>t;
		if(t==1){
			int r;
			cin>>r;
			r--;
			a[r][m]=a[r][0];
			FOR(j,1,m+1)a[r][j-1]=a[r][j];
		}else if(t==2){
			int c;
			cin>>c;
			c--;
			a[n][c]=a[0][c];
			FOR(j,1,n+1)a[j-1][c]=a[j][c];
		}else if(t==3){
			int x,y,z;
			cin>>x>>y>>z;
			x--,y--;
			//cout<<a[x][y].first<<' '<<a[x][y].second<<' '<<z<<endl;
			r[a[x][y].first][a[x][y].second]=z;
			//cout<<r[0][0]<<' '<<r[0][1]<<endl;
		}
	}

	REP(i,n){
		REP(j,m){
			if(j)printf(" ");
			printf("%d",r[i][j]);
		}
		puts("");
	}

#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}