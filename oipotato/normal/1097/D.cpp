#include<cstdio>
#include<cstring>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
const int MOD=1E9+7;
int f[10010][60],b[60],k,cnt,inv[110];
long long a[60],n;
/*
// Miller_Rabin 
// <2^63
const int S=20;//S
// (a*b)%c.   a,blong long
//  a,b,c <2^63
long long mult_mod(long long x,long long y,long long mod){
    if (x<1e9 && y<1e9) return x*y%mod;
    long long k=(long long)((long double)x*y/mod),res;
    res=(x*y-k*mod)%mod;
    return res<0? res+mod:res;
}
long long pow_mod(long long x,long long n,long long mod){//x^n%c
    if(n==1)return x%mod;
    x%=mod; long long tmp=x; long long ret=1;
    while(n){
        if(n&1) ret=mult_mod(ret,tmp,mod);
        tmp=mult_mod(tmp,tmp,mod); n>>=1;
    }
    return ret;
}
//a,n-1=x*2^t      a^(n-1)=1(mod n)  n
//true,false
bool check(long long a,long long n,long long x,long long t){
    long long ret=pow_mod(a,x,n);long long last=ret;
    for(int i=1;i<=t;i++){
        ret=mult_mod(ret,ret,n);
        if(ret==1&&last!=1&&last!=n-1) return true;//
        last=ret;
    }
    if(ret!=1) return true;return false;
}
//true.() false
bool Miller_Rabin(long long n){// Miller_Rabin()
    if(n<2)return false;
    if(n==2)return true;
    if((n&1)==0) return false;//
    long long x=n-1,t=0;
    while((x&1)==0){x>>=1;t++;}
    for(int i=0;i<S;i++){
        long long a=rand()%(n-1)+1;
        if(check(a,n,x,t))return false;//
    }
    return true;
}
//pollard_rho 
long long factor[500000];//
int tol;//1
long long gcd(long long a,long long b)
{
    if(a==0)return 1;
    if(a<0) return gcd(-a,b);
    while(b){long long t=a%b; a=b; b=t;}
    return a;
}
long long Pollard_rho(long long x,long long c){
    long long i=1,k=2,x0=rand()%x;long long y=x0;
    while(1){
        i++; x0=(mult_mod(x0,x0,x)+c)%x;
        long long d=gcd(y-x0,x);
        if(d!=1&&d!=x) return d;
        if(y==x0) return x;
        if(i==k){y=x0;k+=k;}
    }
}
void findfac(long long n){//n
    if(Miller_Rabin(n)){//
        factor[++tol]=n;
        return;
    }
    long long p=n;
    while(p>=n)p=Pollard_rho(p,rand()%(n-1)+1);
    findfac(p);findfac(n/p);
}*/
int mypow(int x,int n){int ans=1;for(;n;n>>=1,x=1ll*x*x%MOD)if(n&1)ans=1ll*ans*x%MOD;return ans;}
int cal(int x,int t,int k)
{
	memset(f,0,sizeof(f));
	f[0][t]=1;
	for(int i=0;i<k;i++)for(int j=0;j<=t;j++)for(int p=0;p<=j;p++)f[i+1][p]=(f[i+1][p]+1ll*f[i][j]*inv[j+1])%MOD;
	int tans=0;
	for(int i=0;i<=t;i++)tans=(tans+1ll*mypow(x,i)*f[k][i])%MOD;
	//printf("%d\n",t);
	//for(int i=1;i<=t;i++)printf("%d%c",f[k][i]," \n"[i==t]);
	return tans;
}
int main()
{
	//srand(time(0));
	scanf("%lld%d",&n,&k);
	rep(i,60)inv[i]=mypow(i,MOD-2);
	/*if(n==1)
	{
		puts("1");
		return 0;
	}
    tol=0; findfac(n);
    if(Miller_Rabin(n))printf("PRIME\n");
    sort(factor+1,factor+tol+1);
    rep(i,tol)*/
	for(int i=2;1ll*i*i<=n;i++)
	if(n%i==0)
	{
		a[++cnt]=i;
		for(;n%i==0;n/=i,b[cnt]++);
	}
	if(n>1)a[++cnt]=n,b[cnt]=1;
	int ans=1;
	rep(i,cnt)ans=1ll*ans*cal(a[i]%MOD,b[i],k)%MOD;
	printf("%d\n",ans);
	return 0;
}