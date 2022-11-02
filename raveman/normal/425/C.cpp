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

int a[111111];
int b[111111];
int n,m,s,e;

int r[100111][301];

vi w[111111];

int id[100111];
int precalc[330][100111];

int getNext(int val,int pos){
	if(w[val].size()>330) {
		return precalc[id[val]][pos];
	}
	int ps = lower_bound(w[val].begin(),w[val].end(),pos)-w[val].begin();
	if(ps >=w[val].size()) return s + 1;
	return w[val][ps];
}


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>s>>e;
	FOR(i,1,1+n)scanf("%d",a+i);
	FOR(j,1,1+m)scanf("%d",b+j),w[b[j]].pb(j);

	int nm=0;
	REP(i,111111)if(w[i].size()>330){
		id[i]=nm;
		REP(j,100111)precalc[nm][j]=s+1;
		REP(j,w[i].size()) precalc[nm][w[i][j]]=w[i][j];
		for(int j=100000;j>=0;j--)precalc[nm][j]=min(precalc[nm][j],precalc[nm][j+1]);
		nm++;
	}
	int res = 0;
	CL(r,-1);
	r[0][0] = 0;
	FOR(i,1,n+1){
		r[i][0]=0;
		for(int j=1;j<=300;j++){
			if(r[i-1][j-1]==-1) break;
			r[i][j]=r[i-1][j];

			int ps = getNext(a[i],r[i-1][j-1]+1);
			if (ps + i + j * e <= s){
				if (r[i][j]==-1 || r[i][j]>ps){
					r[i][j]=ps;
				}
				res=max(res,j);
			}
		}
	}
	cout<<res<<endl;
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}