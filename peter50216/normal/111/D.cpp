#include<stdio.h>
const int mod=1000000007;
inline long long rev(long long a,long long b){
    if(a==1)return 1;
    return (((1-rev(b%a,a)*b)/a)%b+b)%b;
}
inline long long pow(long long a,long long b){
    if(b==0)return 1;
    if(b==1)return a;
    long long t=pow(a,b/2);
    t=(t*t)%mod;
    if(b%2)t=(t*a)%mod;
    return t;
}
int n,m,kk;
long long fac[1001000],rf[1001000];
long long dp[1010][1010];
long long sb[1010][1010];
inline int solve(){
    int k=kk;
    if(m==1)return pow(k,n);
    int i,j;
    long long ans=0;
    if(m==2){
	//all diff
	for(j=1;j<=n&&j*2<=k;j++){
	    long long r=fac[k];
	    r=(r*rf[j])%mod;
	    r=(r*rf[j])%mod;
	    r=(r*rf[k-2*j])%mod;
	    r=(r*dp[n][j])%mod;
	    r=(r*dp[n][j])%mod;
//	    printf("0 %d %lld\n",j,r);
	    ans=(ans+r)%mod;
	}
    }
    for(i=1;i<=n&&i<=k;i++){//same color
	for(j=0;j<=n-i&&j*2<=k-i;j++){//diff color
	    long long r=fac[k];
	    r=(r*rf[i])%mod;
	    r=(r*rf[j])%mod;
	    r=(r*rf[j])%mod;
	    r=(r*rf[k-i-2*j])%mod;
	    r=(r*pow(i,(m-2)*n))%mod;
	    r=(r*dp[n][i+j])%mod;
	    r=(r*dp[n][i+j])%mod;
//	    printf("%d %d %lld\n",i,j,r);
	    ans=(ans+r)%mod;
	}
    }
    return ans;
}
int main(){
    int i,j,k;
    fac[0]=1;
    rf[0]=1;
    for(i=1;i<=1000000;i++){
	fac[i]=(fac[i-1]*i)%mod;
	rf[i]=rev(fac[i],mod);
    }
    sb[0][0]=1;
    for(i=1;i<=1000;i++){
	sb[i][0]=sb[i][i]=1;
	for(j=1;j<i;j++)sb[i][j]=(sb[i-1][j]+sb[i-1][j-1])%mod;
    }
    dp[0][0]=1;
    for(i=1;i<=1000;i++){
	for(j=1;j<=i;j++){
	    dp[i][j]=(dp[i-1][j]*j+dp[i-1][j-1]*j)%mod;
	}
    }
    scanf("%d%d%d",&n,&m,&kk);
    printf("%d\n",solve());
}