#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int T;
int main(){
	scanf("%d",&T);
	while(T--){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a*3LL<=b){
			printf("%d\n",a);
		}else if(b*3LL<=a){
			printf("%d\n",b);
		}else{
			printf("%d\n",(a+b)/4);
		}
	}
	return 0;
}