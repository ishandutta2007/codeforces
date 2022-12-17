// LUOGU_RID: 92361027
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e3+5;
int n,a[maxn],s[maxn];
const ll mod=998244353;
ll f[maxn][maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++) a[read()]++;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) s[i]+=min(a[j],i);
	f[0][0]=1;
	for(int i=n;i>=0;i--)
		for(int j=1;j<=n&&i*j<=s[j];j++)
			for(int k=i*j;k<=s[j];k++)
				f[j][k]=(f[j][k]+f[j-1][k-i])%mod;
	printf("%lld\n",f[n][n]);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}