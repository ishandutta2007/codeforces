#include<bits/stdc++.h>

using namespace std;

#define N 1200
#define LD double

int n,r,x[N];
LD y[N];

int main(){
	scanf("%d%d",&n,&r);
	for (int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		y[i]=r;
		for (int j=1;j<i;j++)
			if (abs(x[j]-x[i])<=2*r){
				y[i]=max(y[i],(LD)sqrt(4*r*r-(x[j]-x[i])*(x[j]-x[i]))+y[j]);
			}
	}
	for (int i=1;i<=n;i++) printf("%.10lf%c",y[i],i==n?'\n':' ');
	
	return 0;
}