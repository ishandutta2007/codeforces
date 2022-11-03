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
int f[51][51][51][51];
char s[52][52];int S[52][52];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1]+(s[i][j]=='#');
	for(int s1=1;s1<=n;++s1)
		for(int s2=1;s2<=n;++s2)
			for(int i=1,j=s1;j<=n;++i,++j)
				for(int k=1,l=s2;l<=n;++k,++l){
					if(!(S[j][l]-S[i-1][l]-S[j][k-1]+S[i-1][k-1]))continue;
					f[i][j][k][l]=std::max(s1,s2);
					for(int o=i;o<j;++o)f[i][j][k][l]=std::min(f[i][j][k][l],f[i][o][k][l]+f[o+1][j][k][l]);
					for(int o=k;o<l;++o)f[i][j][k][l]=std::min(f[i][j][k][l],f[i][j][k][o]+f[i][j][o+1][l]);
				}
	printf("%d\n",f[1][n][1][n]);
	return 0;
}