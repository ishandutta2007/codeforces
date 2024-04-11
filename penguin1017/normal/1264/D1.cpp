#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
using namespace std;
const int N=2e3+9;
const ll mod=998244353;
char s[N];
ll c[N][N],sc[N][N];
void pre(){
	c[0][0]=1;
	rep(i,1,2001){
		c[i][0]=1;
		rep(j,1,i+1)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	rep(i,0,2001){
		per(j,0,i+1)sc[i][j]=(sc[i][j+1]+c[i][j])%mod;
	}
}
int l[N],r[N],q[N];
ll getc(int m,int n){
	if(n<0||n>m)return 0;
	return c[m][n];
}
ll getsc(int m,int n){
	n=max(0,n);
	if(n>m)return 0;
	return sc[m][n];
}
int main(){
	pre();
	scanf("%s",s+1);
	int n=strlen(s+1);
	rep(i,1,n+1){
		l[i]=l[i-1]+(s[i]=='(');
		r[i]=r[i-1]+(s[i]==')');
		q[i]=q[i-1]+(s[i]=='?'); 
	}
	ll ans=0;
	rep(p,1,n/2+1){
		rep(i,1,n+1){
			if(s[i]==')')continue;
			if(l[i-1]>p)break;
			ll lnum=getc(q[i-1],p-1-l[i-1]);
			ll rnum=getsc(q[n]-q[i],p-(r[n]-r[i]));
			ans=(ans+lnum*rnum)%mod;
		}
	}
	printf("%lld",ans);
}