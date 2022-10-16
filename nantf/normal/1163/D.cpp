#include<bits/stdc++.h>
using namespace std;
const int maxn=1010,mod=998244353;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int l,n,m,f[maxn][55][55],nxts[55],nxtt[55],ans=-1e9;
char c[maxn],s[55],t[55];
void get_nxt(char s[],int l,int nxt[]){
	int j=0;
	FOR(i,2,l){
		while(j && s[i]!=s[j+1]) j=nxt[j];
		if(s[i]==s[j+1]) j++;
		nxt[i]=j;
	}
}
inline void chkmax(int &x,int y){if(y>x) x=y;}
void use(int i,int j,int k,char x){
	int jj=j,kk=k;
	while(jj && x!=s[jj+1]) jj=nxts[jj];
	if(x==s[jj+1]) jj++;
	while(kk && x!=t[kk+1]) kk=nxtt[kk];
	if(x==t[kk+1]) kk++;
	if(jj==n){
		if(kk==m) chkmax(f[i+1][nxts[n]][nxtt[m]],f[i][j][k]);
		else chkmax(f[i+1][nxts[n]][kk],f[i][j][k]+1);
	}
	else{
		if(kk==m) chkmax(f[i+1][jj][nxtt[m]],f[i][j][k]-1);
		else chkmax(f[i+1][jj][kk],f[i][j][k]);
	}
}
int main(){
	scanf("%s%s%s",c+1,s+1,t+1);
	l=strlen(c+1);n=strlen(s+1);m=strlen(t+1);
	get_nxt(s,n,nxts);
	get_nxt(t,m,nxtt);
	MEM(f,~0x3f);
	f[0][0][0]=0;
	FOR(i,0,l-1) FOR(j,0,n) FOR(k,0,m){
		if(c[i+1]!='*') use(i,j,k,c[i+1]);
		else FOR(x,'a','z') use(i,j,k,x);
	}
	FOR(j,0,n) FOR(k,0,m) ans=max(ans,f[l][j][k]);
	printf("%d\n",ans);
}
// orz CDW AK