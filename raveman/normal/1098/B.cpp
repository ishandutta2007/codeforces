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
char _s[333333];
string s[333333];
string l="ACGT";
int d[333333][4][4];

int count(int i,int i1,int i2){
	int res = 0;
	REP(j,s[i].size()){
		if(j%2==0){
			if(s[i][j]!=l[i1])res++;
		}else{
			if(s[i][j]!=l[i2])res++;
		}
	}
	return res;
}

int count2(int i,int i1,int i2){
	int res = 0;
	REP(j,n){
		if(j%2==0){
			if(s[j][i]!=l[i1])res++;
		}else{
			if(s[j][i]!=l[i2])res++;
		}
	}
	return res;
}

int RES=-1;
string r[333333];

void solve1(){
	CL(d,-1);
	REP(i,n){
		REP(i1,4)REP(i2,4)if(i1!=i2){
			int v = count(i,i1,i2);
			if(i){
				int mx = 1000000000;
				REP(i3,4)REP(i4,4)if(i3!=i4 && i3!=i1 && i3!=i2 && i4!=i1 && i4!=i2)mx=min(mx,d[i-1][i3][i4]);
				v += mx;
			}
			d[i][i1][i2]=v;
		}
	}

	int bv = d[n-1][0][1];
	int row = n-1;
	int ii1=0,ii2=1;
	REP(i1,4)REP(i2,4)if(i1!=i2){
		if(d[n-1][i1][i2]<bv){
			bv=d[n-1][i1][i2];
			ii1=i1;
			ii2=i2;
		}
	}
	if(RES==-1 || RES>bv){
		RES=bv;
	}
	while(row>=0){
		r[row]="";
		REP(i,s[row].size()){
			if(i%2==0)r[row].pb(l[ii1]);
			else r[row].pb(l[ii2]);
		}
		row--;
		if(row>=0){
			bv=1000000000;
			int ii3,ii4;
			REP(i3,4)REP(i4,4)if(i3!=ii1 && i3!=ii2 && i3!=i4 && i4!=ii1 && i4!=ii2){
				if(bv>d[row][i3][i4]){
					bv=d[row][i3][i4];
					ii3=i3;
					ii4=i4;
				}
			}
			ii1=ii3;
			ii2=ii4;
		}
	}
}
void solve2(){
	CL(d,-1);
	REP(i,m){
		REP(i1,4)REP(i2,4)if(i1!=i2){
			int v = count2(i,i1,i2);
			if(i){
				int mx = 1000000000;
				REP(i3,4)REP(i4,4)if(i3!=i4 && i3!=i1 && i3!=i2 && i4!=i1 && i4!=i2)mx=min(mx,d[i-1][i3][i4]);
				v += mx;
			}
			d[i][i1][i2]=v;
		}
	}

	int bv = d[m-1][0][1];
	int column = m-1;
	int ii1=0,ii2=1;
	REP(i1,4)REP(i2,4)if(i1!=i2){
		if(d[m-1][i1][i2]<bv){
			bv=d[m-1][i1][i2];
			ii1=i1;
			ii2=i2;
		}
	}
	if(RES==-1 || RES>bv){
		RES=bv;
	}else return;
	REP(i,n)r[i]=string(m,' ');
	while(column>=0){
		REP(i,n){
			if(i%2==0)r[i][column]=l[ii1];
			else r[i][column]=l[ii2];
		}
		column--;
		if(column>=0){
			bv=1000000000;
			int ii3,ii4;
			REP(i3,4)REP(i4,4)if(i3!=ii1 && i3!=ii2 && i3!=i4 && i4!=ii1 && i4!=ii2){
				if(bv>d[column][i3][i4]){
					bv=d[column][i3][i4];
					ii3=i3;
					ii4=i4;
				}
			}
			ii1=ii3;
			ii2=ii4;
		}
	}
}


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n){
		scanf("%s",_s);
		s[i]=string(_s);
	}

	solve1();
	solve2();

	REP(i,n)cout<<r[i]<<'\n';
//	cout<<RES<<endl;
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}