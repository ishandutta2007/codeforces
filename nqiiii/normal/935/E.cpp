#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10000,maxk=200;
int lc[maxn+10],rc[maxn+10],sz[maxn+10],n,mp[maxn+10];
int stk[maxn+10],stkcnt,cnt,p,m;
int f[maxn+10][maxk+10],g[maxn+10][maxk+10],rt;
char s[maxn+10];
int work(int l,int r){
	while(mp[l]==r) ++l,--r;
	if(l==r){
		++cnt; f[cnt][0]=g[cnt][0]=s[l]-'0'; return cnt;
	}
	int x=++cnt; int lst=mp[l]?mp[l]:l; lc[x]=work(l,lst);
	rc[x]=work(lst+2,r); sz[x]=sz[lc[x]]+sz[rc[x]]+1;
	return x;
}
void dp(int x){
	int l=lc[x],r=rc[x];
	if(l&&r){
		dp(l); dp(r);
		for(int i=0;i<=sz[l]&&i<=p;++i)
			for(int j=0;j<=sz[r]&&i+j<=p;++j){
				f[x][i+j]=min(f[x][i+j],f[l][i]-g[r][j]);
				g[x][i+j]=max(g[x][i+j],g[l][i]-f[r][j]);
				if(i+j+1<=p){
					f[x][i+j+1]=min(f[x][i+j+1],f[l][i]+f[r][j]);
					g[x][i+j+1]=max(g[x][i+j+1],g[l][i]+g[r][j]);
				}
			}
	}
}
void dp2(int x){
	int l=lc[x],r=rc[x];
	if(l&&r){
		dp2(l); dp2(r);
		for(int i=0;i<=sz[l]&&i<=m;++i)
			for(int j=0;j<=sz[r]&&i+j<=m;++j){
				f[x][i+j]=min(f[x][i+j],f[l][i]+f[r][j]);
				g[x][i+j]=max(g[x][i+j],g[l][i]+g[r][j]);
				if(i+j+1<=m){
					f[x][i+j+1]=min(f[x][i+j+1],f[l][i]-g[r][j]);
					g[x][i+j+1]=max(g[x][i+j+1],g[l][i]-f[r][j]);
				}
			}
	}
}
int main(){
	scanf("%s%d%d",s+1,&p,&m); n=strlen(s+1);
	memset(f,0x3f,sizeof f); memset(g,-0x3f,sizeof g);
	for(int i=1;i<=n;++i){
		if(s[i]=='(') stk[++stkcnt]=i;
		else if(s[i]==')'){
			mp[stk[stkcnt]]=i; mp[i]=stk[stkcnt--];
		}
	}
	rt=work(1,n);
	if(p<m) dp(rt); else dp2(rt);
	printf("%d",g[rt][p<m?p:m]);
}