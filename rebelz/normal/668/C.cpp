#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

int n;
double ma[100005],mb[100005],a[100005],b[100005],prep[100005],preq[100005];

double f(double x,double y){
	double tmp=(x-y+1)*(x-y+1)-4*x;
	tmp=max(tmp,0.0);
	return sqrt(tmp);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf",&ma[i]);
	for(int i=1;i<=n;i++)
		scanf("%lf",&mb[i]);
	for(int i=1;i<=n;i++)
		a[i]=a[i-1]+ma[i];
	for(int i=n;i>=1;i--)
		b[i]=b[i+1]+mb[i+1];
	for(int i=1;i<=n;i++){
		prep[i]=(a[i]-b[i]+1-f(a[i],b[i]))/2;
		preq[i]=(a[i]-b[i]+1+f(a[i],b[i]))/2;
	}
	for(int i=1;i<=n;i++)
		printf("%.8lf ",prep[i]-prep[i-1]);
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%.8lf ",preq[i]-preq[i-1]);
	printf("\n");
	return 0;
}