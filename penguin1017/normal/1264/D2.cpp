#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
using namespace std;
const int N=1e6+9;
const ll mod=998244353;
char s[N];
ll inv[N],jie[N],s1[N],s2[N],c[N];
void pre(){
	jie[0]=1;
	inv[0]=inv[1]=1;
	rep(i,2,N){
		int k=mod/i,r=mod%i;
		inv[i]=-k*inv[r]%mod;
		inv[i]+=mod;
	}
	rep(i,1,N)jie[i]=jie[i-1]*i%mod,inv[i]=inv[i]*inv[i-1]%mod;
}
int l[N],r[N],q[N];
int main(){
	pre();
	scanf("%s",s+1);
	int n=strlen(s+1);
	rep(i,1,n+1){
		l[i]=l[i-1]+(s[i]=='(');
		r[i]=r[i-1]+(s[i]==')');
		q[i]=q[i-1]+(s[i]=='?'); 
	}
	int m=q[n];
	rep(i,0,m+1)c[i]=jie[m]*inv[i]%mod*inv[m-i]%mod;
	s1[0]=c[0];
	rep(i,1,m+1)s1[i]=(c[i]+s1[i-1])%mod;
	if(m){
		--m;
		rep(i,0,m+1)c[i]=jie[m]*inv[i]%mod*inv[m-i]%mod;
		s2[0]=c[0];
		rep(i,1,m+1)s2[i]=(c[i]+s2[i-1])%mod;
	}
	ll ans=0;
	rep(i,1,n+1){
		if(s[i]==')')continue;
		int f=q[i-1],g=q[n]-q[i],a=l[i-1]+1,b=r[n]-r[i];
		int w=min(f+g,b+g-a);
		if(w>=0){
			if(f+g==q[n]){
				ans=(ans+s1[w])%mod; 
			}
			else{
				ans=(ans+s2[w])%mod;
			}
		}
		//cout<<w<<' '<<ans<<"ans\n"; 
	}
	printf("%lld",ans);
}