#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,q,al[3],nxt[maxn][26],at[26],f[255][255][255];
char s[maxn],a[3][maxn],op[5],str[5];
inline void update(int i,int j,int k){
	if(i) f[i][j][k]=min(f[i][j][k],nxt[f[i-1][j][k]][a[0][i]-'a']);
	if(j) f[i][j][k]=min(f[i][j][k],nxt[f[i][j-1][k]][a[1][j]-'a']);
	if(k) f[i][j][k]=min(f[i][j][k],nxt[f[i][j][k-1]][a[2][k]-'a']);
}
int main(){
	n=read();q=read();
	scanf("%s",s+1);
	FOR(i,0,25) at[i]=nxt[n+1][i]=n+1;
	ROF(i,n,0){
		FOR(j,0,25) nxt[i][j]=at[j];
		at[s[i]-'a']=i;
	}
	MEM(f,0x3f);
	f[0][0][0]=0;
	while(q--){
		scanf("%s",op);
		int id=read()-1;
		if(op[0]=='+'){
			scanf("%s",str);
			a[id][++al[id]]=str[0];
			if(id==0) FOR(j,0,al[1]) FOR(k,0,al[2]) update(al[0],j,k);
			if(id==1) FOR(i,0,al[0]) FOR(k,0,al[2]) update(i,al[1],k);
			if(id==2) FOR(i,0,al[0]) FOR(j,0,al[1]) update(i,j,al[2]);
		}
		else{
			if(id==0) FOR(j,0,al[1]) FOR(k,0,al[2]) f[al[0]][j][k]=1e9;
			if(id==1) FOR(i,0,al[0]) FOR(k,0,al[2]) f[i][al[1]][k]=1e9;
			if(id==2) FOR(i,0,al[0]) FOR(j,0,al[1]) f[i][j][al[2]]=1e9;
			al[id]--;
		}
		puts(f[al[0]][al[1]][al[2]]<=n?"YES":"NO");
	}
}