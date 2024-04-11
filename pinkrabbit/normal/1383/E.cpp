#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1000005
#define ll long long
#define mod 1000000007
#define inf 0x3f3f3f3f
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,a[MN];char s[MN];
int ans;
int suf0[MN],nxt1[MN],nxt0s[MN],stk[MN],tp;
int f[MN];
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	F(i,1,n)a[i]=s[i]-'0';
	int pre=0,suf=0;
	while(pre<n&&!a[pre+1])++pre;
	while(suf<n&&!a[n-suf])++suf;
	if(pre==n&&suf==n)return printf("%d\n",n),0;
	if(pre+suf==n-1)return printf("%lld\n",(ll)(pre+1)*(suf+1)%mod),0;
	F(i,1,n-pre-suf-2)a[i]=a[pre+1+i];
	n-=pre+suf+2;
//	printf("%d : ",n);
//	F(i,1,n)printf("%d",a[i]);
//	puts("");
	suf0[0]=0;
	F(i,1,n)suf0[i]=a[i]?0:suf0[i-1]+1;
	nxt1[n]=n+1;
	dF(i,n-1,0)nxt1[i]=a[i+1]?i+1:nxt1[i+1];
	dF(i,n,0){
		while(tp&&suf0[stk[tp]]<=suf0[i])--tp;
		if(tp)nxt0s[i]=stk[tp];
		else nxt0s[i]=n+1;
		stk[++tp]=i;
	}
//	printf("suf0  : ");F(i,0,n)printf("%3d, ", suf0[i]);puts("");
//	printf("nxt1  : ");F(i,0,n)printf("%3d, ", nxt1[i]);puts("");
//	printf("nxt0s : ");F(i,0,n)printf("%3d, ", nxt0s[i]);puts("");
	f[0]=1;
	F(i,0,n-1){
		if(nxt1[i]<=n)f[nxt1[i]]=(f[nxt1[i]]+f[i])%mod;
		if(nxt0s[i]<=n)f[nxt0s[i]]=(f[nxt0s[i]]+f[i])%mod;
	}
//	printf("  f   : ");F(i,0,n)printf("%3d, ", f[i]);puts("");
	ans=1; // "1"
	F(i,0,n)ans=(ans+f[i])%mod;
	printf("%lld\n",(ll)ans*(pre+1)%mod*(suf+1)%mod);
	return 0;
}