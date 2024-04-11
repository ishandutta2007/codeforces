#include<cstdio>
#include<cmath>
#define F(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int d,R,n,Ans=0;
int main(){
	int x,y,r;
	scanf("%d%d%d",&R,&d,&n);
	F(i,1,n){
		scanf("%d%d%d",&x,&y,&r);
		if(sqrt(x*x+y*y)-r>=R-d&&sqrt(x*x+y*y)+r<=R) ++Ans;
	}
	printf("%d",Ans);
	return 0;
}