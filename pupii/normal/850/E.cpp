#include<bits/stdc++.h>
#define mod 1000000007
#define inv 500000004
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char f[1048569];
int F[1048569],S[1048569];
void FWT(int*A,int N,int t){
	for(int o=1;o<N;o<<=1)
		for(int*p=A;p!=A+N;p+=o<<1)
			for(int i=0;i<o;++i){
				int x=p[i],y=p[i+o];
				p[i]=(x+y)%mod,p[i+o]=(x-y+mod)%mod;
				if(!t)p[i]=1ll*p[i]*inv%mod,p[i+o]=1ll*p[i+o]*inv%mod;
			}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),N=1<<n;
	scanf("%s",f);
	for(int i=0;i<N;++i)S[i]=1<<n-__builtin_popcount(i);
	for(int i=0;i<N;++i)F[i]=f[i]-'0';
	FWT(S,N,1),FWT(F,N,1);
	for(int i=0;i<N;++i)F[i]=1ll*F[i]*S[i]%mod;
	FWT(F,N,0);
	int ans=0;
	for(int i=0;i<N;++i)if(f[i]=='1')ans=(ans+F[i])%mod;
	printf("%d\n",ans*3ll%mod);
	return 0;
}