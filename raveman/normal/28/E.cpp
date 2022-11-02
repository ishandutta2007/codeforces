#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include<complex>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<pii,int> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int n;
int x[11111];
int y[11111];

int xa,ya,xv,yv,zv,f,xu,yu,zu;

const double eps = 1e-7;

double t1=-1,t2=-1;

const double SM_INF = 1e10;

struct SimplexM{
	int startN, N;
	vd old_c,c,b,res;
	vector<vd> system;
	double value;
	SimplexM(vd c):N(c.size()),c(c){ } //   ( )
	
	void add(vd r,double v,int sgn=0){ // v >= 0
		for(;c.size()<r.size();c.pb(0));
		for(;r.size()<c.size();r.pb(0));
		if(sgn)r.pb(-sgn),c.pb(0);
		system.pb(r),b.pb(v);
	}

	void refresh_c_func(int pos,int row){
		double begin=c[pos];
		REP(i,N) c[i]-=begin*system[row][i];
	}

	void gauss(int row,int col){
		double v=system[row][col];
		REP(i,N) system[row][i]/=v;
		b[row]/=v;
		REP(i,system.size()) if(i!=row){
			v=system[i][col];
			REP(j,N) system[i][j]-=v*system[row][j];
			b[i]-=v*b[row];
		}
	}
	// -2 - NO SOLUTION
	// -1 -  - (  )
	// 1 - OK
	int solve(){
		N=c.size(),old_c=c;
		int m=system.size();
		REP(i,m)system[i].resize(N);
		startN=N;
		vi base(m,-1);
		REP(i,N){
			int nm=0,pos=-1;
			REP(j,m) if(fabs(system[j][i])>eps) nm++,pos=j;
			if(nm==1 && fabs(system[pos][i]-1)<eps && base[pos]==-1)
			base[pos]=i;
		}
		REP(i,m) if(base[i]==-1){
			N++;
			c.pb(SM_INF);
			REP(j,m) system[j].pb(j==i?1:0);
			base[i]=N-1;
		}
		REP(i,m) refresh_c_func(base[i],i);
		while(1){
			int pos=-1,row=-1;
			REP(i,N) if(c[i]<-eps && (pos==-1 || c[i]<c[pos])) pos=i;
			if(pos==-1) break;
			double min_teta=0;
			REP(i,m)
			if(system[i][pos]>eps && (row==-1 || min_teta>b[i]/system[i][pos]))
				row=i,min_teta=b[i]/system[i][pos];
			if(row==-1) return -1;
			base[row]=pos;
			gauss(row,pos);
			refresh_c_func(pos,row);
		}
		REP(i,m) if(base[i]>=startN && fabs(b[i])>eps) return -2;
		res.resize(startN,0);
		REP(i,m) if(base[i]<startN) res[base[i]]=b[i];
		value=0;
		REP(i,startN) value+=res[i]*old_c[i];
		return 1;
	}
};

void go(double X,double Y){
	vd c;
	c.pb(1e5);
	c.pb(1);
	c.pb(0);
	SimplexM m(c);

	vd r1;
	r1.pb(xv);r1.pb(0);r1.pb(xu);
	if(X<0){
		X=-X;
		REP(i,r1.size()) r1[i]=-r1[i];
	}

	m.add(r1,X,0);
	vd r2;
	r2.pb(yv);r2.pb(0);r2.pb(yu);
	if(Y<0){
		Y=-Y;
		REP(i,r2.size()) r2[i]=-r2[i];
	}
	m.add(r2,Y,0);
	vd r3;
	r3.pb(zv);r3.pb(f);r3.pb(zu);
	m.add(r3,0,0);

	if(m.solve()==1){
		double T1 = m.res[0];
		double T2 = m.res[1];

		if(t1<-0.5 || t1 > T1 + eps || t1 > T1 -eps && t2 > T2 +eps)
			t1=T1,t2=T2;
	}
}

double det(double a,double b,double c,double d){return a*d-b*c;}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)scanf("%d %d",x+i,y+i);
	x[n]=x[0],y[n]=y[0];
	cin>>xa>>ya;
	REP(i,n+1) x[i]-=xa,y[i]-=ya;
	cin>>xv>>yv>>zv;
	cin>>f;
	cin>>xu>>yu>>zu;

	REP(i,n) go(x[i],y[i]);

	double dx = xv;// + zv/double(-f)*xu;
	double dy = yv;// + zv/double(-f)*yu;
	REP(q,2){
	
		REP(i,n){
			double d = det(x[i+1]-x[i],-dx,y[i+1]-y[i],-dy);
			if(fabs(d)>eps){
				double t1 = det(-x[i],-dx,-y[i],-dy) / d;				
				double t2 = det(x[i+1]-x[i], -x[i], y[i+1]-y[i], -y[i]) / d;

				if(t1>0 && t1<1 && t2>0){
					go(dx * t2, dy * t2);
				}
			}
		}

		dx += zv/double(-zu)*xu;
		dy += zv/double(-zu)*yu;
	}

	printf("%.6lf %.6lf\n",t1,t2);

	return 0;
}