#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int x,y;
		scanf("%d%d",&x,&y);
		if((x&1)&&(y&1)){
			printf("%d %d\n",(x+1)/2,(y-1)/2);
		}else if((~x&1)&&(~y&1)){
			printf("%d %d\n",x/2,y/2);
		}else puts("-1 -1");
	}
	return 0;
}