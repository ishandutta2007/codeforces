#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char in[2010];
const int mod=1000003;
int ans[2010];
long long fac[4010],rev[4010],rf[4010];
int t[2010],tc;//0:number, 1:unary
int st[2010],stc;
long long dp[2010][2010];
inline int solve(){
    int i,j,k;
    int n=strlen(in);
    tc=0;
    bool isn=0,ist;
    for(i=0;i<n;i++){
	ist=0;
	if(in[i]<='9'&&in[i]>='0'){
	    isn=1;
	}else{
	    if(isn){
		t[tc++]=0;
		isn=0;
	    }
	    if(i==0||!(in[i-1]<='9'&&in[i-1]>='0')){
		if(in[i]=='*'||in[i]=='/')return 0;
		t[tc++]=1;
	    }else{
		ist=1;
	    }
	}
    }
    if(isn)t[tc++]=0;
    if(t[tc-1]==1||ist)return 0;
    stc=0;
    for(i=0;i<tc;i++){
	if(t[i]==0)st[stc]++;
	else stc++;
    }
    if(stc==0)return ans[tc];
    dp[stc+1][0]=1;
    int ms=0;
    for(i=stc;i>=0;i--){
	int r=st[i];
	if(i){
	    ms+=r;
	    for(j=1;j<=ms;j++){
		for(k=max(r-j,0);k<=ms-j;k++){
		    dp[i][k+1]+=(dp[i+1][k+j-r]*ans[j])%mod;
		    if(dp[i][k+1]>=mod)dp[i][k+1]-=mod;
		}
	    }
	}else{
	    for(j=0;j<=ms;j++){
		dp[i][j+r]=dp[i+1][j];
	    }
	    ms+=r;
	}
    }
    int ret=0;
    for(i=1;i<=tc;i++)ret=(ret+dp[0][i]*ans[i])%mod;
    return ret;
}
int main(){
    int i,j;
    rev[1]=1;
    for(i=2;i<=4000;i++)rev[i]=(rev[mod%i]*(mod-mod/i))%mod;
    fac[0]=rf[0]=1;
    for(i=1;i<=4000;i++){
	fac[i]=(fac[i-1]*i)%mod;
	rf[i]=(rf[i-1]*rev[i])%mod;
    }
    ans[1]=1;
    for(i=1;i<=2000;i++){
	ans[i+1]=(rev[i+1]*(((fac[2*i]*rf[i])%mod*rf[i])%mod))%mod;
    }
    scanf("%s",in);
    printf("%d\n",solve());
}