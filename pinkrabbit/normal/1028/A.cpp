#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=(a);i<=(b);++i)
// Luogu Gu-INF
int n,m;
char str[1001][1001];
int x,y,X,Y;

int main(){
	scanf("%d%d",&n,&m); x=n,y=m;
	F(i,1,n) {scanf("%s",str[i]+1); F(j,1,m) if(str[i][j]=='B') x=min(x,i), X=max(X,i), y=min(y,j), Y=max(Y,j);}
	printf("%d %d\n",(x+X)/2,(y+Y)/2);
	return 0;
}