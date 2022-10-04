#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)

int n;
int ask(int r1,int c1,int r2,int c2){
	if(r1<1||r2<1||c1<1||c2<1) return 0;
	if(r1>n||r2>n||c1>n||c2>n) return 0;
	char str[7];
	printf("? %d %d %d %d\n",r1,c1,r2,c2);
	fflush(stdout);
	scanf("%s",str);
	return *str=='Y';
}
char Ans[1005]; int T;
int main(){
	scanf("%d",&n); T=2*n-2;
	int nx=1, ny=1;
	F(i,1,n-1){
		int d1=ask(nx+1,ny,n,n), d2=ask(nx,ny+1,n,n);
		if(d1) Ans[i]='D', ++nx;
		else Ans[i]='R', ++ny;
	}
	nx=n, ny=n;
	F(i,1,n-1){
		int d1=ask(1,1,nx-1,ny), d2=ask(1,1,nx,ny-1);
		if(d2) Ans[T--]='R', --ny;
		else Ans[T--]='D', --nx;
	}
	printf("! %s",Ans+1);
	return 0;
}