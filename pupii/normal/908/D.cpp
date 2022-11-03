#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
#define mod 1000000007
il int pow(int a,int b){
	int ret=1;
	while(b){
		if(b&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;b>>=1;
	}return ret;
}
int k,pa,pb,dv,f[1010][1010];
il int dp(int x,int y){
	if(x+y>=k)return(x+y+dv)%mod;
	if(~f[x][y])return f[x][y];
	else return f[x][y]=(1ll*dp(x+1,y)*pa+1ll*dp(x,x+y)*pb)%mod;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("cf908.in","r",stdin);
	freopen("cf908.out","w",stdout);
#endif
	k=gi(),pa=gi(),pb=gi();
	dv=1ll*pa*pow(pb,mod-2)%mod;
	int sum=pa+pb;pa=1ll*pa*pow(sum,mod-2)%mod,pb=1ll*pb*pow(sum,mod-2)%mod;
	memset(f,-1,sizeof f);
	printf("%d\n",dp(1,0));
	return 0;
}