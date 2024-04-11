#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
#endif
char S[200010];
int s[200010][26];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%s",S+1);
	int n=strlen(S+1);
	for(int i=1;i<=n;++i){
		++s[i][S[i]-'a'];
		for(int j=0;j<26;++j)s[i][j]+=s[i-1][j];
	}
	int q=gi(),l,r,MX,c;
	while(q--){
		l=gi(),r=gi();c=0;
		MX=0;for(int i=0;i<26;++i)c+=!!(s[r-1][i]-s[l][i]),MX=std::max(MX,s[r-1][i]-s[l][i]);
		bool ans=0;
		if(S[l]==S[r]&&c-!!(s[r-1][S[l]-'a']-s[l][S[l]-'a'])<2)ans=1;
		if(l==r)ans=0;
		puts(ans?"No":"Yes");
	}
	return 0;
}