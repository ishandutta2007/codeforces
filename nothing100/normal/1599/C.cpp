#include<bits/stdc++.h>
using namespace std;
int n;
double p;
double f(int x){
	double res=0;
	res=res+1.0*x*(x-1)*(x-2)*1.0;
	res=res+3.0*x*(x-1)*(n-x)*1.0;
	res=res+3.0*x*(n-x)*(n-x-1)*0.5;
	//printf("%d %.6lf\n",x,res);
	return res;
}
int main(){
	scanf("%d%lf",&n,&p);
	for (int i=0;i<=n;i++)
	if (f(i)>=p*n*(n-1)*(n-2)){
		printf("%d\n",i);
		return 0;
	}
}