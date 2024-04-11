#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=100+5;
int n,c[maxn],b[maxn],q;
int sb[maxn];
typedef long long ll;
const ll mod=1e9+7;
ll dp[maxn+5][2][maxn*maxn],s[maxn*maxn];
int main(){
	n=readint();
	for(int i=1;i<=n;i++) c[i]=readint();
	for(int i=1;i<n;i++) b[i]=readint();
	for(int i=1;i<n;i++) sb[i]=sb[i-1]+b[i];
	for(int i=1;i<n;i++) sb[i]+=sb[i-1];
	ll prod=1;
	for(int i=1;i<=n;i++) prod=prod*(c[i]+1)%mod;
	int mn=-sb[n-1]/n-1,mx=maxn-sb[n-1]/n+1;
	for(int i=mn;i<=mx;i++){
		for(int j=0;j<maxn*maxn;j++) dp[i-mn][(n+1)%2][j]=1;
		for(int j=n;j>0;j--){
			s[0]=dp[i-mn][(j+1)%2][0];
			for(int k=1;k<maxn*maxn;k++)
				s[k]=(s[k-1]+dp[i-mn][(j+1)%2][k])%mod;
			for(int k=0;k<maxn*maxn;k++){
				int l=max(k,i*j+sb[j-1]),r=min(k+c[j],maxn*maxn-1);
				if(l>r) dp[i-mn][j%2][k]=0;
				else dp[i-mn][j%2][k]=(s[r]-(l?s[l-1]:0)+mod)%mod;
			}
		}
	}
	int q=readint();
	while(q--){
		int x=readint();
		if(x<mn) printf("%lld\n",prod);
		else if(x>mx) printf("0\n");
		else printf("%lld\n",dp[x-mn][1][0]);
	}
	return 0;
}