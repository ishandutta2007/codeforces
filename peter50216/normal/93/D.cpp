#include<stdio.h>
#include<string.h>
const long long mod=1000000007;
const int s=17;
struct XD{
    long long num[20][20];
    XD(){memset(num,0,sizeof(num));}
    XD operator*(const XD& b)const{
	XD x;
	int i,j,k;
	for(i=0;i<s;i++)for(j=0;j<s;j++)for(k=0;k<s;k++){
	    x.num[i][j]+=(num[i][k]*b.num[k][j])%mod;
	    x.num[i][j]%=mod;
	}
	return x;
    }
};
inline long long half(long long n){
    n%=mod;
    if(n%2==0)return n/2;
    else return (n+mod)/2;
}
inline void power(XD& a,long long n){
    XD id;
    id=a;
    int i;
    XD ans;
    for(i=0;i<17;i++)ans.num[i][i]=1;
    while(n){
	if(n%2)ans=ans*id;
	id=id*id;
	n/=2;
    }
    a=ans;
}
long long ori[20];
inline long long realsolve(long long n){
    if(n==1)return 4;
    XD tmp;
    int i,j,k;
    for(i=0;i<4;i++)for(j=0;j<4;j++)for(k=0;k<4;k++){
	if(i==j||j==k)continue;
	if(i+j==1||j+k==1)continue;
	if(i+j==5||j+k==5)continue;
	if(i==3&&j==1&&k==2)continue;
	if(i==2&&j==1&&k==3)continue;
	tmp.num[j*4+k][i*4+j]=1;
    }
    for(i=0;i<17;i++)tmp.num[16][i]=1;
    for(i=0;i<17;i++)ori[i]=0;
    for(i=0;i<4;i++)for(j=0;j<4;j++){
	if(i==j)continue;
	if(i+j==1)continue;
	if(i+j==5)continue;
	ori[i*4+j]=1;
    }
    ori[16]=4;
    power(tmp,n-1);
    long long ans=0;
    for(i=0;i<17;i++)ans=(ans+(tmp.num[16][i]*ori[i])%mod)%mod;
    //printf("realsolve %d %d\n",n,ans);
    return ans;
}
inline long long solvesym(long long n){
    return realsolve((n+1)/2);
}
inline long long solve(long long n){
    if(n==0)return 0;
    if(n==1)return 4;
    return half(realsolve(n)+solvesym(n));
}
int main(){
    long long a,b;
    scanf("%I64d%I64d",&a,&b);
    printf("%I64d\n",((solve(b)-solve(a-1))%mod+mod)%mod);
}