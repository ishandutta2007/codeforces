#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<"-----------------------------------"<<endl
#define LL long long
#define DB double
using namespace std;
inline LL read(){
	LL nm=0; bool fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define M 100100
#define mod 1000000007
int n,m; LL pr[M][26],f[26][26];
char ch[M];
LL ans;
int main(){
	scanf("%s",ch+1),n=strlen(ch+1);
	for(int i=1;i<=n;i++){
		memcpy(pr[i],pr[i-1],sizeof(pr[i])),pr[i][ch[i]-'a']++;
		for(int j=0;j<26;j++) f[j][ch[i]-'a']+=pr[i-1][j];
	}
	for(int i=0;i<26;i++) for(int j=0;j<26;j++) ans=max(ans,f[i][j]);
	for(int i=0;i<26;i++) ans=max(ans,pr[n][i]);
	printf("%lld\n",ans);
	return 0;
}