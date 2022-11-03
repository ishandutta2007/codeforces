// luogu-judger-enable-o2
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
char s[510];
int f[510][510];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi();
	scanf("%s",s+1);
	for(int sz=1;sz<=n;++sz)
		for(int l=1,r=sz;r<=n;++l,++r){
			f[l][r]=1+f[l+1][r];
			for(int i=l+1;i<=r;++i)if(s[i]==s[l])f[l][r]=std::min(f[l][r],f[l+1][i-1]+f[i][r]);
		}
	printf("%d\n",f[1][n]);
	return 0;
}