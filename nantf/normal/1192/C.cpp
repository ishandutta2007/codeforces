#include<bits/stdc++.h>
using namespace std;
const int maxn=100010,mod=998244353,val[2][2][2]={{{24,12},{12,4}},{{12,6},{4,1}}};
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
int n,cnt[62][62],tot[62][62][62],l[maxn],ans;
char s[maxn][13];
bool pali[maxn];
map<string,bool> vis;
inline int id(char c){
	if(c>='a' && c<='z') return c-'a';
	if(c>='A' && c<='Z') return c-'A'+26;
	if(c>='0' && c<='9') return c-'0'+52;
}
int main(){
	n=read();
	FOR(i,1,n){
		scanf("%s",s[i]);
		l[i]=strlen(s[i]);
		pali[i]=true; 
		FOR(j,0,l[i]-1) if(s[i][j]!=s[i][l[i]-1-j]) pali[i]=false;
	}
	FOR(len,3,10){
		MEM(cnt,0);MEM(tot,0);
		vis.clear();
		int upr=0;
		FOR(i,1,n) if(l[i]==len){
			if(vis[string(s[i])]) continue;
			string tmp=string(s[i]);
			reverse(tmp.begin(),tmp.end());
			vis[tmp]=true;
			cnt[id(s[i][0])][id(s[i][l[i]-1])]++;
			if(!pali[i]) cnt[id(s[i][l[i]-1])][id(s[i][0])]++;
			upr=max(upr,id(s[i][0]));
			upr=max(upr,id(s[i][l[i]-1]));
		}
		FOR(i,0,upr) FOR(j,i,upr) FOR(k,j,upr) FOR(l,0,upr)
			tot[i][j][k]=(tot[i][j][k]+1ll*cnt[i][l]*cnt[j][l]%mod*cnt[k][l])%mod;
		FOR(i,0,upr) FOR(j,i,upr) FOR(k,j,upr) FOR(l,k,upr){
			int s=1ll*tot[i][j][k]*tot[i][j][l]%mod*tot[i][k][l]%mod*tot[j][k][l]%mod,hhh=0;
			ans=(ans+1ll*s*val[i==j][j==k][k==l])%mod;
		}
	}
	printf("%d\n",ans);
}