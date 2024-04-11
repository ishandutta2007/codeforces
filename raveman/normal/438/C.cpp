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

const int mod = 1000000007;

int n;
int x[222],y[222];
int d[222][222];
bool good[222][222];


ll sq(int p1,int p2,int p3){
	ll t = (x[p2]-x[p1])*ll(y[p3]-y[p1])-(x[p3]-x[p1])*ll(y[p2]-y[p1]);
	if(t<0) return -1;
	if(t>0) return 1;
	return 0;
}

bool isinside(int X,int Y){
	ll oX = mod, oY = mod + 2;
	x[n+1]=oX;
	y[n+1]=oY;
	x[n+2]=X;
	y[n+2]=Y;
	int num = 0;
	REP(i,n){
		if(sq(i,i+1,n+1) *sq(i,i+1,n+2)<0){
			if(sq(n+1,n+2,i) *sq(n+1,n+2,i+1)<0){
				num++;
			}
		}
	}
	return num%2==1;
}


bool is_good(int from,int to){
	if(abs(from-to)<=1)return 1;
	REP(i,n)if(i!=from && i!=to){
		if(sq(from,to,i)==0){
			if(x[i]>=min(x[from],x[to]) && x[i]<=max(x[from],x[to]) &&
			   y[i]>=min(y[from],y[to]) && y[i]<=max(y[from],y[to])) {
		        return false;
			}
		}
	}

	REP(i,n)if(i!=from && i!=to && i+1!=from && i+1!=to){
		if(sq(from,to,i) *sq(from,to,i+1)<0){
			if(sq(from,i+1,i) *sq(to,i+1,i)<0){
				return false;
			}
		}
	}

	return isinside((x[to]+x[from])/2,(y[to]+y[from])/2);
}

int go(int from,int to){
	if(to==from+2) return 1;
	if(to==from+1) return 1;
	if(d[from][to]!=-1)return d[from][to];
	ll res = 0;
	//cout<<from<<' '<<to<<endl;
	FOR(i,from+1,to){
		if(good[from][i] && good[i][to] && sq(from,to,i)){
			res = (res + ll(go(from,i)) * go(i,to)) % mod; 
		}
	}
	return d[from][to]=res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	CL(d,-1);
	cin>>n;
	REP(i,n)cin>>x[i]>>y[i],x[i]*=2,y[i]*=2;
	x[n]=x[0],y[n]=y[0];
	REP(i,n)REP(j,n)good[i][j]=is_good(i,j);
	if(0)REP(i,n){
		REP(j,n)cout<<good[i][j]<<' ';
		puts("");
	}
	cout<<go(0,n-1)<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}