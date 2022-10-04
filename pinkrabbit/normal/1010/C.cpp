#include<bits/stdc++.h>
using namespace std;
#define F2(i,a,b) for(int i=a;i<(b);++i)

int n,k;
int x;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}

int main(){
	scanf("%d%d",&n,&k);
	int A=k;
	F2(i,0,n){
		scanf("%d",&x),x%=k;
		A=Gcd(A,x);
	}
	printf("%d\n",k/A);
	for(int i=0;i<k;i+=A) printf("%d ",i);
	return 0;
}