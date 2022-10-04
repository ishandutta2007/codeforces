#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
int n,q,x,Ans;
int main(){
	scanf("%d",&n);
	F(i,1,n) F(j,1,n) scanf("%d",&x), Ans^=((i==j)*x);
	scanf("%d",&q);
	while(q--){
		scanf("%d",&x);
		if(x==3) printf("%d",Ans);
		else scanf("%*d",&x), Ans^=1;
	}
	return 0;
}