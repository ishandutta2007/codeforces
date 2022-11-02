#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back


int n;
int m;
int x[222222];
int y[222222];
int X[211111];
int Y[211111];
int xt[222222];
int yt[222222];
double mn[111111];
double MX[111111];

void change(int *x,int *y,int n){
	int pos = 0;
	REP(i,n)if(x[i] < x[pos] || x[i] == x[pos] && y[i] > y[pos])
		pos = i;
	REP(i,n) xt[i] = x[(i+pos)%n],yt[i]=y[(i+pos)%n];
	REP(i,n) x[i] =xt[i], y[i]=yt[i];
}

bool better(ll x,ll y,ll x1,ll y1,ll x2,ll y2){
	ll q = (x1-x)*(y2-y)-(x2-x)*(y1-y);
	if(q) return q<0;
	return (x-x1)*(x-x1)+(y-y1)*(y-y1) > (y-y2)*(y-y2)+(x-x2)*(x-x2);
}

void un(){
	int N=0;

	x[n] = x[0],y[n] = y[0];
	X[m] = X[0],Y[m] = Y[0];

	int p1 = 0;
	int p2 = 0;

	while(1){
		xt[N] = x[p1] + X[p2];
		yt[N] = y[p1] + Y[p2];
		N++;
		if(N == n + m) break;
		

		int x1 = x[p1] + X[p2+1];
		int y1 = y[p1] + Y[p2+1];
		int x2 = x[p1+1] + X[p2];
		int y2 = y[p1+1] + Y[p2];

		if(better(xt[N-1],yt[N-1],x1,y1,x2,y2)) p2++;
		else p1++;
	}


	REP(i,N) x[i]=xt[i],y[i]=yt[i];
	n=N;

	/*puts("begin");
	REP(i,N) {
		cout<<x[i]<<' '<<y[i]<<endl;
	}
	puts("end");*/
}

typedef pair<pii,int> p3;
p3 p[111111];

const double eps = 1e-9;

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(j,n) scanf("%d %d",&x[j],&y[j]);
	reverse(x,x+n);
	reverse(y,y+n);
	change(x,y,n);
	REP(i,2){
		cin>>m;
		REP(j,m) scanf("%d %d",&X[j],&Y[j]);
		reverse(X,X+m);
		reverse(Y,Y+m);
		change(X,Y,m);
		un();
	}
	cin>>m;
	REP(i,m){
		scanf("%d %d",X+i,Y+i);
		p[i] = p3(pii(3*X[i],Y[i]),i);
		mn[i] = 1e100;
		MX[i] = -1e100;
	}
	sort(p,p+m);
	x[n] = x[0], y[n] = y[0];
	REP(i,n){
		int xf = min(x[i],x[i+1]);
		int xe = max(x[i],x[i+1]);
		int pos = lower_bound(p,p+m,p3(pii(xf,-2000000000),0))-p;
		while(pos<m){
			if(p[pos].first.first > xe) break;
			int ver = p[pos].second;
			if(xf == xe){
				mn[ver] =  min(mn[ver], 0.+min(y[i],y[i+1]));
				MX[ver] =  max(MX[ver], 0.+max(y[i],y[i+1]));
			}else{
				double Y = y[i] + (y[i+1]-y[i])*double(p[pos].first.first - x[i])/double(x[i+1]-x[i]);
				mn[ver] =  min(mn[ver], Y);
				MX[ver] =  max(MX[ver], Y);
			}

			pos++;
		}
	}
	REP(i,m){
		puts(3*Y[i]>=mn[i]-eps && 3*Y[i]<=MX[i]+eps ? "YES":"NO");
		//cout<<
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}