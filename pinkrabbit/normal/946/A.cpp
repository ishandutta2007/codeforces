#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)

int n,ans;

int main(){
	scanf("%d",&n);
	int x;
	F(i,1,n) scanf("%d",&x), ans+=abs(x);
	printf("%d",ans);
	return 0;
}