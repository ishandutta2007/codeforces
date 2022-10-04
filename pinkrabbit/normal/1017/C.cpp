#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
const int INF=0x3f3f3f3f;

int n;

int main(){
	scanf("%d",&n);
	int Ans=INF, X=0;
	F(i,1,n) if(i+((n-1)/i+1)<Ans) Ans=i+((n-1)/i+1), X=i;
	F(i,1,n/X) dF(j,X,1) printf("%d ",(i-1)*X+j);
	F(i,1,n-X*(n/X)) printf("%d ",n-i+1);
	return 0;
}