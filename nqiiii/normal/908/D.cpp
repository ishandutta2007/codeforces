#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=1000000007,maxn=1000;
ll f[maxn+10][maxn+10],pa,pb,rada,radb,ans;
int k;
ll fpow(ll a,ll b){
	ll ans=1;
	for(a%=mod;b;b/=2,(a*=a)%=mod) if(b%2) (ans*=a)%=mod;
	return ans;
}
int main(){
	scanf("%d%lld%lld",&k,&pa,&pb); f[1][0]=1;
	rada=pa*fpow(pa+pb,mod-2)%mod; radb=pb*fpow(pa+pb,mod-2)%mod;
	for(int i=1;i<=k;++i)
		for(int j=0;j<k;++j)
			if(i==k){
				(ans+=f[i][j]*(rada*fpow(mod+1-rada,mod-2)%mod+j+i)%mod*radb%mod*fpow(mod+1-rada,mod-2)%mod)%=mod;
			}else{
				(f[i+1][j]+=f[i][j]*rada%mod)%=mod;
				if(j+i<k) (f[i][j+i]+=f[i][j]*radb%mod)%=mod;
				else (ans+=f[i][j]*radb%mod*(j+i)%mod)%mod;
			}
	printf("%lld",ans);
}