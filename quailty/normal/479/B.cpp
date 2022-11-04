#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int min(int a,int b)
{
	if(a<b)return a;
	else return b;
}
int max(int a,int b)
{
	if(a>b)return a;
	else return b;
}
int main()
{
	int n,k,i,j,minimum,mini,maximum,maxi,tow[100],less[1000],more[1000];
	scanf("%d%d",&n,&k);
	for(i=0;i<=n-1;i++)scanf("%d",&tow[i]);
	mini=1;maxi=1;
	minimum=10001;maximum=0;
	for(j=0;j<=n-1;j++){
		minimum=min(minimum,tow[j]);
		maximum=max(maximum,tow[j]);
		if(minimum==tow[j])mini=j;
		if(maximum==tow[j])maxi=j;
	}
	for(i=1;i<=k;i++){
		if(maximum-minimum<=1)break;
		less[i-1]=maxi+1;more[i-1]=mini+1;
		tow[maxi]--;tow[mini]++;
		mini=1;maxi=1;
		minimum=10001;maximum=0;
		for(j=0;j<=n-1;j++){
			minimum=min(minimum,tow[j]);
			maximum=max(maximum,tow[j]);
			if(minimum==tow[j])mini=j;
			if(maximum==tow[j])maxi=j;
		}
	}
	printf("%d %d\n",maximum-minimum,i-1);
	for(j=1;j<=i-1;j++){
		printf("%d %d\n",less[j-1],more[j-1]);
	}
}