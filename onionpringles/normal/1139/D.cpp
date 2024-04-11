#include <bits/stdc++.h>
using namespace std;
const int N=101010;
const int mod=1000000007;
#define mul(x,y) ((long long)(x)*(y)%mod)
vector<int> V[N],W[N];
int pf[N],pp[N],dp[N];
int inv(int i){
	if(i==1)return 1;
	else return mul(mod-mod/i,inv(mod%i));
}
int main(){
	int m;scanf("%d",&m);
	for(int i=1;i<=m;i++)V[i].resize(1+m/i);
	for(int i=2;i<N;i++){
		if(pf[i])continue;
		for(int j=i;j<N;j+=i)pf[j]=i;
	}
	for(int i=1;i<N;i++)for(int j=i;j<N;j+=i)W[j].push_back(i);
	for(int i=2;i<N;i++){
		pp[i]=i;
		while(pp[i]%pf[i]==0)pp[i]/=pf[i];
	}
	for(int i=m;i;i--){
		V[i][1]=m/i;
		for(int j=2;j<=m/i;j++){
			int p=pf[j],k=pp[j];
			V[i][j]=V[i][k];
			if(p*i<=m)V[i][j]-=V[p*i][k];
		}
	}
	for(int i=2;i<=m;i++){
		dp[i]=m;
		for(auto &d:W[i]){
			if(d==i)continue;
			dp[i]+=mul(V[d][i/d],dp[d]);
			if(dp[i]>=mod)dp[i]-=mod;
		}
		dp[i]=mul(dp[i],inv(m-m/i));
	}
	dp[0]=1;
	for(int i=1;i<=m;i++){
		dp[0]+=mul(dp[i],inv(m));
		if(dp[0]>=mod)dp[0]-=mod;
	}
	printf("%d\n",dp[0]);
}