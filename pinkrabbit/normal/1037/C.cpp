#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)

int n,Ans;
char a[1000002],b[1000002];

int main(){
	scanf("%d",&n);
	scanf("%s%s",a+1,b+1);
	int d=a[1]!=b[1];
	F(i,2,n){
		int g=a[i]!=b[i];
		if(d){
			++Ans;
			if(g&&a[i-1]!=a[i]) g=0;
		}
		d=g;
	} if(d) ++Ans;
	printf("%d",Ans);
	return 0;
}