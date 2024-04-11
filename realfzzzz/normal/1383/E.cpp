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
const int maxn=1e6+5;
int n,pre1[maxn],nxt[maxn][2];
char a[maxn];
const ll mod=1e9+7;
inline void add(ll& x,ll y){
	x=(x+y)%mod;
}
ll f[maxn];
int s[maxn],tp,t[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	scanf("%s",a+1);
	n=strlen(a+1);
	for(int i=1;i<=n;i++) pre1[i]=a[i]=='1'?i:pre1[i-1];
	nxt[n+1][0]=nxt[n+1][1]=n+1;
	for(int i=n;i>0;i--){
		nxt[i][0]=nxt[i+1][0];
		nxt[i][1]=nxt[i+1][1];
		nxt[i][a[i]-'0']=i;
	}
	s[tp=0]=n+1;
	for(int i=n;i>0;i--){
		while(tp&&nxt[s[tp]][1]-s[tp]<=nxt[i][1]-i) tp--;
		t[i]=s[tp];
		s[++tp]=i;
	}
	if(nxt[1][1]>n){
		printf("%d\n",n);
		return 0;
	}
	int l=nxt[1][1],r=pre1[n];
	f[l]=1;
	for(int i=l;i<r;i++){
		if(nxt[i+1][1]<=r) add(f[nxt[i+1][1]],f[i]);
		if(a[i]=='0'){
			if(a[i+1]=='0') add(f[i+1],f[i]);
			else{
				int x=pre1[i]+1;
				if(t[x]<=r) add(f[t[x]+i-x+1],f[i]);
			}
		}
		else if(nxt[i+1][0]<=r) add(f[nxt[i+1][0]],f[i]);
	}
	ll ans=0;
	for(int i=l;i<=r;i++) if(a[i]=='1') add(ans,f[i]);
	printf("%lld\n",ans*l%mod*(n-r+1)%mod);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}