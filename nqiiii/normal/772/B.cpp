#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=10000;
struct vec{double x,y;};
typedef vec pnt;
vec operator-(vec a,vec b){return (vec){a.x-b.x,a.y-b.y};}
double operator|(vec a,vec b){return a.x*b.y-a.y*b.x;}
double len(vec a){return sqrt(a.x*a.x+a.y*a.y);}
int n; pnt a[maxn+10]; double ans=0x3f3f3f3f;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%lf%lf",&a[i].x,&a[i].y);
	for(int i=0;i<n;++i){
		pnt st=a[i],ed=a[(i+2)%n],p=a[(i+1)%n];
		double d=fabs((ed-st)|(p-st))/len(ed-st);
		ans=min(ans,d/2);
	}
	printf("%.10lf",ans);
}