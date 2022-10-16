#include<bits/stdc++.h>
using namespace std;
const int maxn=111;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int q,n,nxt[maxn][26];
char s[maxn],t[maxn],tmps[maxn],tmpt[maxn];
int main(){
	q=read();
	while(q--){
		n=read();
		scanf("%s%s",s+1,t+1);
		FOR(i,1,n) tmps[i]=s[i],tmpt[i]=t[i];
		sort(tmps+1,tmps+n+1);sort(tmpt+1,tmpt+n+1);
		bool flag=true;
		FOR(i,1,n) if(tmps[i]!=tmpt[i]){flag=false;break;}
		if(!flag){puts("-1");continue;}
		FOR(i,0,25) nxt[n][i]=n+1;
		ROF(i,n-1,0) FOR(j,0,25) nxt[i][j]=(s[i+1]==j+'a')?i+1:nxt[i+1][j];
		int ans=n;
		FOR(i,1,n){
			int cur=0;
			FOR(j,i,n){
				cur=nxt[cur][t[j]-'a'];
				if(cur>n) break;
				ans=min(ans,i-1+n-j);
			}
		}
		printf("%d\n",ans);
	}
}