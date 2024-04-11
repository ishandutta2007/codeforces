#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
typedef double ld;

int sy,a,b,n,q;
int C[400005],S[400005];
ld c[400005];

int main(){
	scanf("%d%d%d%d",&sy,&a,&b,&n);
	F(i,1,n)
		scanf("%d%d",C+i+i-1,C+i+i),
		c[i+i-1]=C[i+i-1], c[i+i]=C[i+i],
		S[i+i-1]=S[i+i-2], S[i+i]=S[i+i-1]+C[i+i]-C[i+i-1];
	scanf("%d",&q);
	F(i,1,q){
		int x,y;
		scanf("%d%d",&x,&y);
		ld xl=a+(ld)(x-a)*(-sy)/(y-sy);
		ld xr=b+(ld)(x-b)*(-sy)/(y-sy);
		int pl=lower_bound(c+1,c+n+n+1,xl)-c;
		int pr=upper_bound(c+1,c+n+n+1,xr)-c-1;
		if(pr<pl) {printf("%.15lf\n",(ld)(pl&1?0:b-a)); continue;}
		ld dl=xr-xl, s=S[pr]-S[pl];
		if(~pl&1) s+=C[pl]-xl;
		if(pr&1) s+=xr-C[pr];
		printf("%.15lf\n",s*(b-a)/dl);
	}
	return 0;
}