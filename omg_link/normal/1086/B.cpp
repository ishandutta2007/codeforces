#include <stdio.h>
#define MN 100000
int n,cnt,d[MN+5];
double s;
int main(){
	scanf("%d%lf",&n,&s);
	for(int i=1;i<=n-1;i++){
		static int u,v;
		scanf("%d%d",&u,&v);
		d[u]++,d[v]++;
	}
	for(int i=1;i<=n;i++)
		if(d[i]==1) cnt++;
	printf("%.10lf\n",s/cnt*2);
}