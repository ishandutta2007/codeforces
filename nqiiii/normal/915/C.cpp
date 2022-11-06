#include<cstdio>
typedef long long ll;
ll a,b,f[20],now; int cnt[20],bit;
ll work(){
	ll ans=0;
	for(int i=0;i<10;++i)
		for(int j=1;j<=cnt[i];++j) ans=ans*10+i;
	return ans;
}
int main(){
	scanf("%lld%lld",&a,&b);
	for(;a;a/=10,++bit) ++cnt[a%10];
	f[1]=1;
	for(int i=2;i<=19;++i) f[i]=f[i-1]*10;
	for(int i=bit;i>=1;--i){
		for(int j=9;j>=0;--j)
			if(cnt[j]){
				--cnt[j]; if(now+j*f[i]+work()<=b){
					now+=j*f[i]; break;
				}else ++cnt[j];
			}
	}
	printf("%lld",now); return 0;
}