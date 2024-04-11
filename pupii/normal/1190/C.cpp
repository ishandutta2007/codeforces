#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 998244353
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
#ifdef mod
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
#endif
char s[100010];
int pre[2][100010],suf[2][100010];
int S[2][100010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),k=gi();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		++S[s[i]-'0'][i];
		S[0][i]+=S[0][i-1];
		S[1][i]+=S[1][i-1];
	}
	for(int c=0;c<2;++c){
		int fst=0,lst=0;
		for(int i=1;i<=n;++i){
			if(s[i]==c+'0'){
				if(!fst)fst=i;lst=i;
			}
			if(lst-fst+1<=k)pre[c][i]=1;
		}
		fst=lst=0;
		for(int i=n;i;--i){
			if(s[i]==c+'0'){
				if(!fst)fst=i;lst=i;
			}
			if(fst-lst+1<=k)suf[c][i]=1;
		}
	}
	pre[0][0]=pre[1][0]=1;
	suf[0][n+1]=suf[1][n+1]=1;
	int qaq=0;
	for(int l=1,r=k;r<=n;++l,++r){
		for(int c=0;c<2;++c){
			if(S[c][l-1]==l-1&&S[c][n]-S[c][r]==n-r)
				return puts("tokitsukaze"),0;
			bool now=0;
			if(!S[c][l-1]&&suf[c][r+1])now=1;
			if(!(S[c][n]-S[c][r])&&pre[c][l-1])now=1;
			if(!now)qaq=1;
		}
	}
	if(qaq)puts("once again");
	else puts("quailty");
	return 0;
}