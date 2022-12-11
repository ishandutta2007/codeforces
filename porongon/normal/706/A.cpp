#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

double xx,yy;
double x,y;
int n;

int main(){
	scanf("%lf%lf",&xx,&yy);
	scanf("%d",&n);
	double r=1e9;
	while(n--){
		double v;
		scanf("%lf%lf%lf",&x,&y,&v);
		r=min(r,sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy))/v);
	}
	printf("%.12lf\n",r);
	return 0;
}