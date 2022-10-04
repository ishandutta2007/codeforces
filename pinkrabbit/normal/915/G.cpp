#include<cstdio>
#define Mod 1000000007
int n,k,Ans;
bool isnprime[2000001]={1,1};
int mobius[2000001]={0,1};
int primes[1000001],pnum;
int ans[2000001];
int pows[2000001];
void Mobius(int num){
	for(int i=2;i<=num;++i){
		if(!isnprime[i])
			primes[++pnum]=i, mobius[i]=-1;
		for(int j=1;j<=pnum&&i*primes[j]<=num;++j){
			isnprime[i*primes[j]]=1;
			if(i%primes[j]==0) break;
			mobius[i*primes[j]]=-mobius[i];
		}
	}
}
inline int Pow(int base,int exp){
	int sum=1;
	while(exp){
		if(exp&1) sum=(long long)sum*base%Mod;
		base=(long long)base*base%Mod; exp>>=1;
	} return sum;
}
int main(){
	scanf("%d%d",&n,&k);
	Mobius(k);
	pows[0]=0;
	for(int i=1;i<=k;++i) pows[i]=Pow(i,n);
	for(int i=1;i<=k;++i){
		if(!mobius[i]) continue;
		for(int j=1;j*i<=k;++j){
			ans[j*i]-=mobius[i]*pows[j-1];
			ans[j*i]+=mobius[i]*pows[j];
			ans[j*i]=((ans[j*i]%Mod)+Mod)%Mod;
		}
	}
	for(int i=1;i<=k;++i) ans[i]=(ans[i-1]+ans[i])%Mod, Ans=(Ans+(ans[i]^i))%Mod;
	printf("%d",Ans);
	return 0;
}