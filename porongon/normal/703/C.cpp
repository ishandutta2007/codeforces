#include <bits/stdc++.h>
#define EPS 1e-12
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,w,v,u;
int x[10005],y[10005];
vector<pair<int,double> > e;

int main(){
	scanf("%d%d%d%d",&n,&w,&v,&u);
	bool can=true;
	int miny=(1<<30),maxy=-(1<<30),minx=-(1<<30);
	fore(i,0,n){
		scanf("%d%d",x+i,y+i);
		miny=min(miny,y[i]);
		maxy=max(maxy,y[i]);
	}
	fore(i,0,n)if(y[i]==miny)minx=max(minx,x[i]);

	fore(i,0,n){
		double t=1.*x[i]/v;
		if(x[i]<0)can=false;
		else {
			if(1LL*x[i]*u<1LL*y[i]*v)can=false;
			if(x[i]>=minx)e.pb(mp(y[i],t));
		}
	}
	if(can||e.empty()){
		printf("%.10lf\n",1.*w/u);
		return 0;
	}
	sort(e.begin(),e.end());
	int y=0;double t=0.;
	fore(i,0,e.size()){
		//printf("%d %.5lf\n",y,t);
		int yb=e[i].fst;
		double tb=e[i].snd;
		if(yb==y)t=max(t,tb);
		else {
			t=max(tb,t+1.*(yb-y)/u);
			y=yb;
		}
	}
	printf("%.10lf\n",t+1.*(w-y)/u);
	return 0;
}