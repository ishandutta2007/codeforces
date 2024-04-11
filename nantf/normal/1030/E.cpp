#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=300030;
int n,bc[maxn],pre[maxn];
ll a[maxn];
int bitcnt(ll x){
	int ans=0;
	for(;x;x&=x-1) ans++;
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",a+i),pre[i]=(pre[i-1]+(bc[i]=bitcnt(a[i])));
	int odd=1,even=0;
	ll ans=0;
	for(int i=1;i<=n;i++) ans+=((pre[i]&1)?even++:odd++);
	for(int i=1;i<=n;i++){
		int upr=min(n,i+61),maxn=0;
		for(int j=i;j<=upr;j++){
			maxn=max(maxn,bc[j]);
			if((pre[j]-pre[i-1])&1) continue;
			if(maxn*2>pre[j]-pre[i-1]) ans--;
		}
	}
	printf("%lld\n",ans);
}