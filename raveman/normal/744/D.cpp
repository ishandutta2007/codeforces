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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int n,m;
int x[1111],y[1111];
const double eps = 1e-8;
int xm[1111],ym[1111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n)cin>>x[i]>>y[i],x[i]*=2,y[i]*=2;
	REP(i,m)cin>>xm[i]>>ym[i],xm[i]*=2,ym[i]*=2;
	if(m<=2) {puts("-1");return 0;}

	double best=0;
	REP(p1,m)REP(p2,p1){
		int X = (xm[p1] + xm[p2]) / 2;
		int Y = (ym[p1] + ym[p2]) / 2;

		ll dx = xm[p2] - xm[p1];
		ll dy = ym[p2] - ym[p1];
		swap(dx,dy);
		dx=-dx;

		bool hasleft=false,hasright=false;
		bool bad = false;
		double rbound,lbound;
		//cout<<"start "<<p1<<' '<<p2<<endl;
		//cout<<"center "<<X<<' '<<Y<<endl;
		//cout<<"d "<<dx<<' '<<dy<<endl;
		REP(i,m)if(i!=p1 && i!=p2){
			if (hasleft && hasright){
				if(lbound - eps > rbound) {bad=true;break;}
			}
			int A = -2 * xm[p1] + 2 * xm[i];
			int B = -2 * ym[p1] + 2 * ym[i];
			int C = xm[i]*xm[i] - xm[p1]*xm[p1] + ym[i] *ym[i]-ym[p1]*ym[p1];

			if ((xm[p1]-xm[i])*(ym[p2]-ym[i])-(xm[p2]-xm[i])*(ym[p1]-ym[i])==0){
				if (xm[i] < min(xm[p1],xm[p2]) || xm[i]>max(xm[p1],xm[p2])) continue;
				if (ym[i] < min(ym[p1],ym[p2]) || ym[i]>max(ym[p1],ym[p2])) continue;
				bad = true; break;
			}

			ll k = dx * A + dy * B;
			if(!k)continue;
			double t = double (C - A * X - B * Y) / k;
///			cout<<t<<endl;

			double px = X + dx * (t + 1);
			double py = Y + dy * (t + 1);
			bool right = false;
			if ((xm[i]-px)*(xm[i]-px)+(ym[i]-py)*(ym[i]-py)<(xm[p1]-px)*(xm[p1]-px)+(ym[p1]-py)*(ym[p1]-py)) right = true;
			//cout<<X+dx*t<<' '<<Y+dy*t<<" "<<right<<endl;
			if(right){
				if(!hasright)hasright=true,rbound=t;
				else rbound=min(rbound,t);
			}else{
				if(!hasleft)hasleft=true,lbound=t;
				else lbound=max(lbound,t);
			}
		}
		if(bad) continue;
		if (hasleft && hasright){
			if(lbound - eps > rbound) continue;
		}
		//cout<<"here "<<p1<<' '<<p2<<' '<<lbound<<' '<<hasleft<<' '<<rbound<<' '<<hasright<<endl;

		REP(i,n){
			int A = -2 * xm[p1] + 2 * x[i];
			int B = -2 * ym[p1] + 2 * y[i];
			int C = x[i]*x[i] - xm[p1]*xm[p1] + y[i] *y[i]-ym[p1]*ym[p1];

			if ((xm[p1]-x[i])*(ym[p2]-y[i])-(xm[p2]-x[i])*(ym[p1]-y[i])==0){
				if (x[i] < min(xm[p1],xm[p2]) || x[i]>max(xm[p1],xm[p2])) continue;
				if (y[i] < min(ym[p1],ym[p2]) || y[i]>max(ym[p1],ym[p2])) continue;
				double mx = max(fabs(lbound),fabs(rbound));

				double nx = X + dx * mx;
				double ny = Y + dy * mx;
				best = max(best, (xm[p1]-nx)*(xm[p1]-nx)+(ym[p1]-ny)*(ym[p1]-ny));
				continue;
			}

			ll k = dx * A + dy * B;
			if(!k)continue;
			double t = double (C - A * X - B * Y) / k;

			double px = X + dx * (t + 1);
			double py = Y + dy * (t + 1);
			bool right = false;
			//cout<<X+dx*t<<' '<<Y+dy*t<<" "<<right<<endl;
			if ((x[i]-px)*(x[i]-px)+(y[i]-py)*(y[i]-py)<(xm[p1]-px)*(xm[p1]-px)+(ym[p1]-py)*(ym[p1]-py)) right = true;
			if(right){
				if(!hasright){puts("-1");return 0;}

				if(hasleft) t = max(t,lbound);
				if (t - eps > rbound) continue;

				double mx = max(fabs(t),fabs(rbound));

				double nx = X + dx * mx;
				double ny = Y + dy * mx;
				best = max(best, (xm[p1]-nx)*(xm[p1]-nx)+(ym[p1]-ny)*(ym[p1]-ny));

				if(hasleft && mx == fabs(rbound) && fabs(rbound)>fabs(lbound)) break;

			}else{
				if(!hasleft){puts("-1");return 0;}


				if(hasright) t = min(t,rbound);
				if (t + eps < lbound) continue;

				double mx = max(fabs(t),fabs(lbound));

				double nx = X + dx * mx;
				double ny = Y + dy * mx;
				best = max(best, (xm[p1]-nx)*(xm[p1]-nx)+(ym[p1]-ny)*(ym[p1]-ny));

				if(hasright && mx == fabs(lbound) && fabs(lbound)>fabs(rbound)) break;
			}
		}
	}
	printf("%.10lf\n",sqrt(best)/2);
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}