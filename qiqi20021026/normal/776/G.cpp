#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

#define LL long long
#define max(x,y) ((x)>(y)?(x):(y))

LL t,l,r,f[16][16][1<<17],num[16];

LL dp(int x,int mx,int sum,bool flag){
	if (x==0) return (sum>>mx)&1;
	if (!flag && f[x][mx][sum]!=-1) return f[x][mx][sum];
	LL lim=flag?num[x]:15,ret=0;
	for (int i=0;i<=lim;i++){
		int tmp=sum;
		if (x<=4) tmp|=i<<((x-1)*4);
		ret+=dp(x-1,max(mx,i),tmp,flag && i==lim);
	}
	if (!flag) f[x][mx][sum]=ret;
	return ret;
}

LL solve(LL x){
	int n=0;
	while (x){num[++n]=x%16; x/=16;}
	return dp(n,0,0,1);
}

int main(){
	scanf("%lld",&t);
	memset(f,-1,sizeof f);
	while (t--){
		scanf("%llx%llx",&l,&r);
		printf("%lld\n",solve(r)-solve(l-1));
	}
	
	return 0;
}