#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,mod,q;
int w[100010],phi[33];
int calcphi(int x){
	int ans=x;
	for(int i=2;i*i<=x;i++)
		if(x%i==0){
			ans=ans/i*(i-1);
			while(x%i==0) x/=i;
		}
	if(x>1) ans=ans/x*(x-1);
	return ans;
}
int phimod(ll x,int mod){
	return x>=mod?x%mod+mod:x;
}
int quickpow(int a,int b,int c){
	int ans=phimod(1,c),fac=phimod(a,c);
	while(b){
		if(b&1) ans=phimod(1ll*ans*fac,c);
		fac=phimod(1ll*fac*fac,c);
		b>>=1;
	}
	return ans;
}
int dfs(int l,int r,int pos){
	if(l==r || phi[pos]==1) return phimod(w[l],phi[pos]);
	return quickpow(w[l],dfs(l+1,r,pos+1),phi[pos]);
}
int main(){
	scanf("%d%d",&n,&mod);
	phi[0]=mod;
	for(int i=1;i<=30;i++) phi[i]=calcphi(phi[i-1]);
	for(int i=1;i<=n;i++) scanf("%d",w+i);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",dfs(l,r,0)%mod);
	}
}