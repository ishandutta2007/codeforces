#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int T;
int main(){
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		if(n==1&&m==1)puts("0");
		else if(n==1||m==1)puts("1");
		else puts("2");
	}
	return 0;
}