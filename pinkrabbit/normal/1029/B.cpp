#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define Luogu Judging
int n,Ans;
int a[200001];

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i);
	int P=1;
	F(i,2,n){
		if(a[i]>a[i-1]*2) Ans=max(Ans,P), P=1;
		else ++P;
	} Ans=max(Ans,P);
	printf("%d",Ans);
	return 0;
}