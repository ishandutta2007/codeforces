#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 1000000007
#define inv2 500000004
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
il vd FWTor(int*A,int n,int t){
    for(int o=1;o<n;o<<=1)
        for(int*p=A;p!=A+n;p+=o<<1)
            for(int i=0;i<o;++i)
                if(t)p[i+o]=(p[i+o]+p[i])%mod;
                else p[i+o]=(p[i+o]-p[i]+mod)%mod;
}
il vd FWTand(int*A,int n,int t){
    for(int o=1;o<n;o<<=1)
        for(int*p=A;p!=A+n;p+=o<<1)
            for(int i=0;i<o;++i)
                if(t)p[i]=(p[i]+p[i+o])%mod;
                else p[i]=(p[i]-p[i+o]+mod)%mod;
}
il vd FWTxor(int*A,int n,int t){
    for(int o=1;o<n;o<<=1)
        for(int*p=A;p!=A+n;p+=o<<1)
            for(int i=0;i<o;++i){
                int x=p[i],y=p[i+o];
                p[i]=(x+y)%mod,p[i+o]=(x-y+mod)%mod;
                if(!t)p[i]=1ll*p[i]*inv2%mod,p[i+o]=1ll*p[i+o]*inv2%mod;
            }
}
int fib[131111],S[1000010],s1[131111],s2[131111],s[131111];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	fib[1]=1;for(int i=2;i<1<<17;++i)fib[i]=(fib[i-1]+fib[i-2])%mod;
	int n=gi();
	for(int i=1;i<=n;++i)S[i]=gi(),++s[S[i]];
	for(int i=0;i<1<<17;++i){
		int U=((1<<17)-1)^i;
		for(int j=U;;j=(j-1)&U){
			s1[i+j]=(s1[i+j]+1ll*s[i]*s[j])%mod;
			if(!j)break;
		}
	}
	for(int i=0;i<1<<17;++i)s1[i]=1ll*s1[i]*fib[i]%mod;
	memcpy(s2,s,sizeof s);
	FWTxor(s2,1<<17,1);
	for(int i=0;i<1<<17;++i)s2[i]=1ll*s2[i]*s2[i]%mod;
	FWTxor(s2,1<<17,0);
	for(int i=0;i<1<<17;++i)s2[i]=1ll*s2[i]*fib[i]%mod,s[i]=1ll*s[i]*fib[i]%mod;
	FWTand(s1,1<<17,1);FWTand(s2,1<<17,1);FWTand(s,1<<17,1);
	for(int i=0;i<1<<17;++i)s[i]=1ll*s[i]*s1[i]%mod*s2[i]%mod;
	FWTand(s,1<<17,0);
	int ans=0;
	for(int i=1;i<1<<17;i<<=1)ans=(ans+s[i])%mod;
	printf("%d\n",ans);
	return 0;
}