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

int n,m,q;
int a[1111][1111];

int b[4][1111][1111];

void do_row(int i){
	for(int j = m-1;j>=0;j--){
		if(a[i][j]==0)b[0][i][j]=0;
		else b[0][i][j]=1+b[0][i][j+1];
	}

	for(int j = 0;j<m;j++){
		if(a[i][j]==0)b[1][i][j]=0;
		else b[1][i][j]=1+(j-1>=0?b[1][i][j-1]:0);
	}
}

void do_column(int j){
	for(int i = n-1;i>=0;i--){
		if(a[i][j]==0)b[2][i][j]=0;
		else b[2][i][j]=1+b[2][i+1][j];
	}

	for(int i = 0;i<n;i++){
		if(a[i][j]==0)b[3][i][j]=0;
		else b[3][i][j]=1+(i-1>=0?b[3][i-1][j]:0);
	}
}

void calc_all(){
	REP(i,n){do_row(i);}
	REP(j,m){do_column(j);}
}

void update(int x,int y){
	do_row(x);
	do_column(y);
}

int solve(int x,int y){
	int res = 0;
	//0,1
	REP(j,2){
		int val = b[j][x][y];
		int p1 = x,p2=x;
		for(int len=val;len>0;len--){
			while(p1>=0 && b[j][p1][y]>=len)p1--;
			while(p2<n && b[j][p2][y]>=len)p2++;
			res=max(res,len*(p2-p1-1));
		}
	}
	//2,3
	FOR(j,2,4){
		int val = b[j][x][y];
		int p1 = y,p2=y;
		for(int len=val;len>0;len--){
			while(p1>=0 && b[j][x][p1]>=len)p1--;
			while(p2<m && b[j][x][p2]>=len)p2++;
			res=max(res,len*(p2-p1-1));
		}
	}
	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	
	cin>>n>>m>>q;
	REP(i,n)REP(j,m)scanf("%d",&a[i][j]);

	calc_all();

	REP(i,q){
		int op,x,y;
		scanf("%d %d %d",&op,&x,&y);
		x--,y--;
		if (op==1) {
			a[x][y]^=1;
			update(x,y);
		} else {
			int res = solve(x,y);
			cout<<res<<endl;
		}
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}