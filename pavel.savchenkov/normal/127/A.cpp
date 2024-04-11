#include <cstdio>
#include <math.h>

using namespace std;

int main() {
	int n; int k;
	//freopen("in.txt","r",stdin);
	double x[200],y[200],res=0;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&x[i],&y[i]);
		if (i>1) res+=sqrt( (x[i-1]-x[i])*(x[i-1]-x[i])+(y[i-1]-y[i])*(y[i-1]-y[i]) );
	}
	printf("%.10lf",(double)(res*k/50));
	return 0;
}