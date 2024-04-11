#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
//#define int long long
using namespace std;
typedef long long ll;
int read(){
	char c=getchar();int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=5005;
const int mod=998244353;
int n,m,k,ans,s[N][N],f[N];
int ksm(int x,int k){
	int base=1;
	while(k){
		if(k&1)base=1ll*base*x%mod;
		k>>=1;
		x=1ll*x*x%mod;
	}
	return base;
}
int main(){
	n=read();m=read();k=read();
	s[0][0]=1;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=i;j++){
			s[i][j]=(s[i-1][j-1]+1ll*s[i-1][j]*j%mod)%mod;
		}
	}
	f[0]=1;
	for(int i=1;i<=k;i++)f[i]=1ll*f[i-1]*(n-i+1)%mod;
	int tmp=ksm(m,mod-2);
	for(int i=0;i<=k;i++){
		ans=((ans+1ll*s[k][i]*f[i]%mod*ksm(tmp,i)%mod)%mod+mod)%mod;
	}
	cout<<ans;
	return 0;
}