#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
typedef long long LL;
inline LL Gcd(LL X,LL Y){return Y?Gcd(Y,X%Y):X;}

int n;

int main(){
	LL Ans=0,A,x,y;
	scanf("%d",&n);
	F(i,1,n) scanf("%I64d%I64d",&x,&y), Ans=Gcd(Ans,(LL)x*y/Gcd(x,y));
	if(Ans==1) return 0*puts("-1");
	for(int i=2;i<=10000000;++i){
		if(Ans%i==0) return 0*printf("%d\n",i);
	}
	A=Ans, Ans=x;
	for(int i=2;Ans&&i<=10000000;++i){
		while(Ans%i==0) Ans/=i;
	} if(Ans>1&&Gcd(A,Ans)>1) return 0*printf("%d",Ans);
	Ans=y;
	for(int i=2;Ans&&i<=10000000;++i){
		while(Ans%i==0) Ans/=i;
	} if(Ans>1) return 0*printf("%d",Ans);
	puts("-1");
	return 0;
}

// SB JUDGING