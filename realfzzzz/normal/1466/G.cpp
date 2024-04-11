#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
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
const int maxn=1e5+5,maxw=1e6+5;
int n,q,l0,lw;
char s[maxw*2],t[maxn],w[maxw];
const ll mod=1e9+7,inv2=5e8+4;
ll pw1[maxn],pw2[maxn],sum[26][maxn];
int nxt[maxw];
bool match(int& u,char c){
	while(u&&w[u+1]!=c) u=nxt[u];
	if(w[u+1]==c) u++;
	if(u==lw){
		u=nxt[lw];
		return 1;
	}
	return 0;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	q=readint();
	scanf("%s%s",s+1,t+1);
	int l=l0=strlen(s+1);
	for(int i=1;i<=n&&l<maxw;i++){
		s[l+1]=t[i];
		for(int j=1;j<=l;j++) s[j+l+1]=s[j];
		l=l*2+1;
	}
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=n;i++){
		pw1[i]=pw1[i-1]*2%mod;
		pw2[i]=pw2[i-1]*inv2%mod;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++) sum[j][i]=sum[j][i-1];
		sum[t[i]-'a'][i]=(sum[t[i]-'a'][i]+pw2[i])%mod;
	}
	while(q--){
		int k=readint();
		scanf("%s",w+1);
		lw=strlen(w+1);
		int u=0;
		for(int i=2;i<=lw;i++){
			while(u&&w[u+1]!=w[i]) u=nxt[u];
			if(w[u+1]==w[i]) u++;
			nxt[i]=u;
		}
		int cnt=u=0;
		for(int i=1;i<=l0;i++) cnt+=match(u,s[i]);
		ll ans=pw1[k]*cnt%mod;
		int p=1;
		l=l0;
		for(;p<=k&&l<lw;p++){
			cnt=u=0;
			for(int i=l-min(lw-1,l)+1;i<=l+min(lw-1,l)+1;i++) cnt+=match(u,s[i]);
			ans=(ans+pw1[k-p]*cnt%mod)%mod;
			l=l*2+1;
		}
		if(p<=k) for(int i=0;i<26;i++){
			cnt=u=0;
			for(int j=l-lw+2;j<=l;j++) cnt+=match(u,s[j]);
			cnt+=match(u,'a'+i);
			for(int j=1;j<=lw-1;j++) cnt+=match(u,s[j]);
			ans=(ans+(sum[i][k]-sum[i][p-1]+mod)%mod*pw1[k]%mod*cnt%mod)%mod;
		}
		printf("%lld\n",ans);
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}