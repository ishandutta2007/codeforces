#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1000;
int x[maxn+10],n,r;
double y[maxn+10];
int main(){
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;++i){
		scanf("%d",&x[i]); y[i]=r;
		for(int j=1;j<i;++j){
			double d=r*r*4-(x[i]-x[j])*(x[i]-x[j]);
			if(d>=0) y[i]=max(y[i],y[j]+sqrt(d));
		}
		printf("%.10lf ",y[i]);
	}
}