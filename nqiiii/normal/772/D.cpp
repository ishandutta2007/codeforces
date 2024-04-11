#pragma GCC optimize(3)
#include<cstdio>
typedef long long ll;
const int maxn=999999,mod=1000000007;
int n,bit[maxn+10];
ll num[maxn+10],sum[maxn+10],sqsum[maxn+10],power[maxn+10],ans[maxn+10];
ll tot;
int main(){
	power[0]=1; for(int i=1;i<=maxn;++i) power[i]=power[i-1]*2%mod;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x; scanf("%d",&x); ++num[x]; sum[x]+=x; (sqsum[x]+=1ll*x*x%mod)%=mod;
	}
	for(int i=maxn;i>=0;--i){
		for(int j=0,t=i;j<6;++j) bit[j]=t%10,t/=10;
		for(int j=1;j<1<<6;++j){
			int tot=0,d=-1; bool suc=1;
			for(int k=5;k>=0;--k)
				if(j>>k&1){
					if(bit[k]==9){
						suc=0; break;
					}else d=-d,tot=tot*10+bit[k]+1;
				}else tot=tot*10+bit[k];
			if(suc){
				num[i]+=d*num[tot]; sum[i]+=d*sum[tot]; sqsum[i]+=d*sqsum[tot];
			}
		}
	}
	for(int i=0;i<=maxn;++i){
		num[i]%=mod; sum[i]%=mod; sqsum[i]%=mod;
		if(num[i]>=1) (ans[i]+=sqsum[i]*power[num[i]-1]%mod)%=mod;
		if(num[i]>=2) (ans[i]+=(sum[i]*sum[i]%mod-sqsum[i]+mod)%mod*power[num[i]-2]%mod)%=mod;
	}
	for(int i=0;i<=maxn;++i){
		for(int j=0,t=i;j<6;++j) bit[j]=t%10,t/=10;
		for(int j=1;j<1<<6;++j){
			int tot=0,d=1; bool suc=1;
			for(int k=5;k>=0;--k)
				if(j>>k&1){
					if(bit[k]==9){
						suc=0; break;
					}else d=-d,tot=tot*10+bit[k]+1;
				}else tot=tot*10+bit[k];
			if(suc){
				(ans[i]+=d*ans[tot])%=mod;
				if(ans[i]<0) ans[i]+=mod;
			}
		}
		tot^=i*ans[i];
	}
	printf("%lld",tot);
}