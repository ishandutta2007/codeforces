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

int n,k;
int x[111111];
int y[111111];
vi X,Y;

int YL[222222];
int YR[222222];
int XL[222222];
int XR[222222];


int solveYL(int ypos){
	if(YL[ypos]!=-1)return YL[ypos];
	int num=0;
	REP(i,n)if(y[i]<Y[ypos])num++;
	return YL[ypos]=num;
}

int solveYR(int ypos){
	if(YR[ypos]!=-1)return YR[ypos];
	int num=0;
	REP(i,n)if(y[i]>Y[ypos])num++;
	return YR[ypos]=num;
}
int solveXL(int xpos){
	if(XL[xpos]!=-1)return XL[xpos];
	int num=0;
	REP(i,n)if(x[i]<X[xpos])num++;
	return XL[xpos]=num;
}

int solveXR(int xpos){
	if(XR[xpos]!=-1)return XR[xpos];
	int num=0;
	REP(i,n)if(x[i]>X[xpos])num++;
	return XR[xpos]=num;
}

map<pii,int> M[2][2];

int solve(int xpos,int ypos,int dx,int dy){
	if(M[dx][dy].count(pii(xpos,ypos))) return M[dx][dy][pii(xpos,ypos)];
	int num = 0;
	REP(i,n){
		if((x[i] <= X[xpos]) && dx==1) continue;
		if((x[i] >= X[xpos]) && dx==0) continue;
		if((y[i] <= Y[ypos]) && dy==1) continue;
		if((y[i] >= Y[ypos]) && dy==0) continue;
		num++;
	}
	return M[dx][dy][pii(xpos,ypos)] = num;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	CL(YL,-1);
	CL(XL,-1);
	CL(YR,-1);
	CL(XR,-1);
	cin>>n>>k;
	REP(i,n){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		int xx = (x1+x2);
		int yy = (y1+y2);
		x[i]=xx;
		y[i]=yy;
		X.pb(xx);
		Y.pb(yy);
	}
	ll best = 4e18;
	UN(X),UN(Y);
	for(int yl=0;yl<Y.size();yl++){
		if(yl>k) break;
		for (int yr=Y.size()-1;yr>=yl;yr--){
			if(Y.size()-1-yr>k) break;
			for(int xl=0;xl<X.size();xl++){
				if(xl>k) break;
				for (int xr=X.size()-1;xr>=xl;xr--){
					if(X.size()-1-xr>k) break;

					int num = solveYL(yl)+solveYR(yr)+solveXL(xl)+solveXR(xr);
					num -= solve(xl,yl,0,0);
					num -= solve(xl,yr,0,1);
					num -= solve(xr,yl,1,0);
					num -= solve(xr,yr,1,1);

					if(num<=k){
						ll d1 = Y[yr]-Y[yl]+0ll;
						ll d2 = X[xr]-X[xl]+0ll;
						d1 = max(1ll, (d1+1)/2);
						d2 = max(1ll, (d2+1)/2);
						best=min(best,  d1*d2);
					}
				}
			}
		}
	}
	cout<<best<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}