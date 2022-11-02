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

char c[111][111];
int n = 10;

void iterate(int x,int y){
	int it = 0;
	while(1){
		cout<<"new it " << it <<endl;
	//	REP(i,n)cout<<c[i]<<endl;
		//puts("");
		if(c[x][y]=='.') break;
		int dx=0,dy=0;
		if(c[x][y]=='>')dy=1;
		if(c[x][y]=='<')dy=-1;
		if(c[x][y]=='v')dx=1;
		if(c[x][y]=='^')dx=-1;
		int nx = x + dx;
		int ny = y + dy;
		if(nx<0 || nx>=n || ny<0 || ny>=n) break;
		if(c[nx][ny]!='.'){
			x=nx;
			y=ny;
			continue;
		}
		it++;
		while(1){
			swap(c[x][y],c[x+dx][y+dy]);
			x += dx;
			y += dy;
			nx = x + dx;
			ny = y + dy;
			if(nx<0 || nx>=n || ny<0 || ny>=n) goto end;
			if(c[nx][ny]!='.'){
				x=nx;
				y=ny;
				break;
			}
		}
	}
end:
	cout<<"TOTAL: " << it<<endl;
}

void generate(int n){
	//cout<<n<<endl;
	REP(i,n){
		if(i==0) cout<<'>';
		else cout<<'^';
		if(i%2==0){
			REP(j,n/2-1) cout<<">";
			REP(j,n/2/2-1) cout<<".>";
			cout<<".v";
		}else{
			if(i==n-1) cout<<"..";
			else cout<<"v.";
			REP(j,n/2/2-1) cout<<"<.";
			REP(j,n/2-1) cout<<"<";			
		}
		puts("");
	}
	cout<<"1 1"<<endl;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	
#endif
	//freopen("output.txt","w",stdout);generate(100);return 0;
	cin>>n;
	if(n==5){
		puts(">...v");
		puts("v.<..");
		puts("..^..");
		puts(">....");
		puts("..^.<");
		puts("1 1");
		return 0;
	}else if(n==3) {
		puts(">vv");
		puts("^<.");
		puts("^.<");
		puts("1 3");
		return 0;
	}else{
		generate(100);
		return 0;
	}/*
	REP(i,n)cin>>c[i];
	//REP(i,n)REP(j,n)c[i][j]='.';
	int sx,sy;
	cin>>sx>>sy;

	iterate(sx,sy);
	*/
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}