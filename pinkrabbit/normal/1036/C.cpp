#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int c[20];

LL f(LL x){
	if(x<=0) return 0;
	LL xx=x; int len=0;
	while(xx) c[++len]=xx%10, xx/=10;
	LL Ans[5], s;
	Ans[0]=Ans[1]=Ans[2]=Ans[3]=0; s=0;
	for(int i=len;i>=1;--i){
		Ans[3]=Ans[3]+Ans[2]*9;
		Ans[2]=Ans[2]+Ans[1]*9;
		Ans[1]=Ans[1]+Ans[0]*9;
		if(c[i]){
			if(s<=3) ++Ans[s], Ans[s+1]+=c[i]-1;
			++s;
		}
	} return Ans[1]+Ans[2]+Ans[3]+(s<=3);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		LL L,R;
		scanf("%lld%lld",&L,&R);
		printf("%lld\n",f(R)-f(L-1));
	}
	return 0;
}