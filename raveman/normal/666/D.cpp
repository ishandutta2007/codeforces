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

int x[4],y[4];

int sx[4],sy[4];
int tx[4],ty[4];
int ttx[4],tty[4];

pii inter(pii p1,pii p2){
	return pii(max(p1.first,p2.first),min(p1.second,p2.second));
}

bool canmakeit(int p,int d,int X,int Y,int r){
	if (d) { // hor
		if (y[p] != Y) return 0;
		return abs(x[p]-X)<=r;
	}else {
		//ver
		if (x[p] != X) return 0;
		return abs(y[p]-Y)<=r;
	}
}

bool good(int* d,int* p, int r){
	// 2 hor
	if (d[0] && d[1] && d[2] && d[3]) {
		if (y[p[0]] != y[p[3]]) return 0;
		if (y[p[1]] != y[p[2]]) return 0;
		int side = y[p[1]] - y[p[0]];
		if (side <= 0) return 0;

		pii pos[4];
		REP(i,4) pos[i] = pii(x[p[i]]-r,x[p[i]]+r);
		pii s1 = inter(pos[0],pos[1]);
		pii s2 = inter(pos[2],pos[3]);
		if(s1.first>s1.second || s2.first>s2.second)return 0;

		s1.first += side;
		s1.second += side;
		
		pii s = inter(s1,s2);
		if(s.first>s.second) return 0;

		ttx[0] = s.first - side;
		ttx[1] = s.first - side;

		ttx[2] = s.first;
		ttx[3] = s.first;

		tty[0] = y[p[0]];
		tty[1] = y[p[2]];
		tty[2] = y[p[2]];
		tty[3] = y[p[0]];

		REP(i,4){
			tx[p[i]] = ttx[i];
			ty[p[i]] = tty[i];
		}

		return 1;
	}
	// 2 ver
	if (!d[0] && !d[1] && !d[2] && !d[3]) {
		if (x[p[0]] != x[p[1]]) return 0;
		if (x[p[2]] != x[p[3]]) return 0;
		int side = x[p[2]] - x[p[0]];
		if (side <= 0) return 0;

		pii pos[4];
		REP(i,4) pos[i] = pii(y[p[i]]-r,y[p[i]]+r);
		pii s1 = inter(pos[0],pos[3]);
		pii s2 = inter(pos[1],pos[2]);
		if(s1.first>s1.second || s2.first>s2.second)return 0;

		s1.first += side;
		s1.second += side;
		
		pii s = inter(s1,s2);
		if(s.first>s.second) return 0;

		tty[0] = s.first - side;
		tty[1] = s.first;

		tty[2] = s.first;
		tty[3] = s.first - side;

		ttx[0] = x[p[0]];
		ttx[1] = x[p[0]];
		ttx[2] = x[p[2]];
		ttx[3] = x[p[2]];

		REP(i,4){
			tx[p[i]] = ttx[i];
			ty[p[i]] = tty[i];
		}

		return 1;
	}
	
	// all

	const int inf = 1e9+11;
	int xl = inf;
	int xu = inf;
	int yl = inf;
	int yu = inf;

	if (d[0]) yl = y[p[0]];
	else xl = x[p[0]];
	if (d[1]) yu = y[p[1]];
	else xl = x[p[1]];
	if (d[2]) yu = y[p[2]];
	else xu = x[p[2]];
	if (d[3]) yl = y[p[3]];
	else xu = x[p[3]];
	
	int side = inf;
	if(xl!=inf && xu !=inf)side = xu - xl;
	if(yl!=inf && yu !=inf)side = yu - yl;
	if(side<=0) return 0;
	if(xl==inf) xl = xu - side;
	if(xu==inf) xu = xl + side;
	if(yl==inf) yl = yu - side;
	if(yu==inf) yu = yl + side;

	if (yu - yl != xu - xl) return 0;

	if (!canmakeit(p[0],d[0],xl,yl,r)) return 0;
	if (!canmakeit(p[1],d[1],xl,yu,r)) return 0;
	if (!canmakeit(p[2],d[2],xu,yu,r)) return 0;
	if (!canmakeit(p[3],d[3],xu,yl,r)) return 0;

	ttx[0] = xl;
	ttx[1] = xl;
	ttx[2] = xu;
	ttx[3] = xu;
	tty[0] = yl;
	tty[1] = yu;
	tty[2] = yu;
	tty[3] = yl;


	REP(i,4){
		tx[p[i]] = ttx[i];
		ty[p[i]] = tty[i];
	}

	return 1;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		REP(i,4)scanf("%d %d",x+i,y+i);
		int best = 1e9+7;

		int d[4];
		for(d[0]=0;d[0]<2;d[0]++)for(d[1]=0;d[1]<2;d[1]++)for(d[2]=0;d[2]<2;d[2]++)for(d[3]=0;d[3]<2;d[3]++){
			int p[4];
			p[0]=0;p[1]=1;p[2]=2;p[3]=3;
			do{
				int a = 0, b = best - 1;
				while(a<=b){
					int s = (a+b)>>1;
					if(good(d,p,s)){
						b = s - 1;
						best = s;
						REP(i,4)sx[i]=tx[i],sy[i]=ty[i];
					}else{
						a = s + 1;
					}
				}
			}while(next_permutation(p,p+4));
		}

		if(best>1e9) puts("-1");
		else{
			cout<<best<<endl;
			REP(i,4)printf("%d %d\n",sx[i],sy[i]);
		}
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}