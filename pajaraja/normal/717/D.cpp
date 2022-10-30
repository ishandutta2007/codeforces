#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n,l;
double x[129],p[101][129];
void spojiss(int k)
{
	for(int i=0;i<128;i++) for(int j=0;j<128;j++) p[k+1][i xor j]+=p[k][i]*p[k][j];
}
void spojix(int k)
{
	double t[129];
	fill(t,t+129,0);
	for(int i=0;i<128;i++) for(int j=0;j<128;j++) t[i xor j]+=x[i]*p[k][j];
	for(int i=0;i<128;i++) p[k][i]=t[i];
}
void ver(int k,int i)
{
	if(k==0) 
	{
		p[i][0]=1;
		for(int j=1;j<128;j++) p[i][j]=0;
		return;
	}
	ver(k/2,i-1);
	if(k%2==0) spojiss(i-1);
	else 
	{
		spojiss(i-1);
		spojix(i);
	}
}
int main(int argc, char** argv) 
{
	scanf("%d%d",&n,&l);
	for(int i=0;i<101;i++) fill(p[i],p[i]+129,0);
	for(int i=0;i<=l;i++) scanf("%lf",&x[i]);
	for(int i=l+1;i<128;i++) x[i]=0;
	ver(n,100);
	printf("%lf",1-p[100][0]);
	return 0;
}