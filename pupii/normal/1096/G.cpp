#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 998244353
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
const int G=3,iG=pow(G,mod-2);
int rev[1048583],P[1048583],iP[1048583],Ans[1048583],X[1048583];
il vd ntt(int*A,int n,int t){
	for(int i=0;i<n;++i)if(rev[i]>i)std::swap(A[i],A[rev[i]]);
	for(int o=1;o<n;o<<=1){
		int w=t?P[o]:iP[o];
		for(int*p=A;p!=A+n;p+=o<<1)
			for(int i=0,W=1;i<o;++i,W=1ll*W*w%mod){
				int t=1ll*W*p[i+o]%mod;
				p[i+o]=(p[i]-t+mod)%mod,p[i]=(p[i]+t)%mod;
			}
	}
	if(!t){
		int inv=pow(n,mod-2);
		for(int i=0;i<n;++i)A[i]=1ll*A[i]*inv%mod;
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi()>>1,k=gi();
	for(int i=1;i<1048583;i<<=1)P[i]=pow(G,(mod-1)/(i<<1)),iP[i]=pow(iG,(mod-1)/(i<<1));
	Ans[0]=1;while(k--)++X[gi()];
	int N=1,M=10,NN,lg;
	while(n){
		if(n&1){
			NN=1,lg=0;while(NN<(N+M))NN<<=1,++lg;
			for(int i=0;i<NN;++i)rev[i]=(rev[i>>1]>>1)|((i&1)<<lg-1);
			ntt(Ans,NN,1),ntt(X,NN,1);
			for(int i=0;i<NN;++i)Ans[i]=1ll*Ans[i]*X[i]%mod;
			ntt(Ans,NN,0),ntt(X,NN,0);
			N=N+M;
		}
		n>>=1;
		if(n){
			NN=1,lg=0;while(NN<M<<1)NN<<=1,++lg;
			for(int i=0;i<NN;++i)rev[i]=(rev[i>>1]>>1)|((i&1)<<lg-1);
			ntt(X,NN,1);
			for(int i=0;i<NN;++i)X[i]=1ll*X[i]*X[i]%mod;
			ntt(X,NN,0);
			M<<=1;
		}
	}
	int ans=0;
	for(int i=0;i<N;++i)ans=(ans+1ll*Ans[i]*Ans[i])%mod;
	printf("%d\n",ans);
	return 0;
}