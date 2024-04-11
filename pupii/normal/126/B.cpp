#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char S[1000010];int nxt[1000010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%s",S+1);int n=strlen(S+1),m=0;
	for(int i=2;i<=n;++i){
		int p=nxt[i-1];
		while(p&&S[i]!=S[p+1])p=nxt[p];
		if(S[p+1]==S[i])++p;nxt[i]=p;
	}
	for(int i=2;i<n;++i)m=std::max(m,nxt[i]);
	for(int i=nxt[n];i;i=nxt[i])if(m>=i)printf("%s",S+n-i+1),exit(0);
	puts("Just a legend");
	return 0;
}