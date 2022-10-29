#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
using namespace std;
const int N=1e5+9;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b;
		scanf("%d%d",&a,&b);
		int d=abs(a-b);
		int ans=d/5;
		d%=5;
		if(d==0)ans+=0;
		if(d==1||d==2)ans+=1;
		if(d==3||d==4)ans+=2;
		printf("%d\n",ans);
	}
}