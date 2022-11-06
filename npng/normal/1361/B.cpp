#include<bits/stdc++.h>
using namespace std;
const int N=1000100;
typedef long long ll;
const int mod=1000000007;
int T,n,p,a[N],tmp; ll k;
typedef long long ll;
int qpw(int x,int n){
	int ret=1; for(;n;n>>=1,x=1ll*x*x%mod)
	if(n&1) ret=1ll*ret*x%mod; return ret;
}
int jud(ll x,int n){
	ll ret=1;
	for(;n;n>>=1,x=x*x){
		if(x>1000000)return -1;
		ret=ret*x;
		if(ret>1000000)return -1;
	}
	return ret;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&p),tmp=false;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+1+n),k=1;
		for(int i=n-1;i>=1;i--){
			if(!tmp){
				int t=jud(p,a[i+1]-a[i]);
				if(k&&t==-1)tmp=true;
				if(t!=-1&&1ll*t*k>1000000)tmp=true;
			}
			if(tmp)k=1ll*k*qpw(p,a[i+1]-a[i])%mod-1;
			else k=k?k*qpw(p,a[i+1]-a[i])-1:1;
		}
		k=1ll*k*qpw(p,a[1])%mod,printf("%d\n",(k+mod)%mod);
	}
}