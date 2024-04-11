#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e3+5,maxl=800+5;
int lenl,lenr,n;
char l[maxl],r[maxl];
int sz=1,nxt[maxl*20][10],g[maxl*20][maxl];
int get(int u,int c){
	return nxt[u][c]?nxt[u][c]:nxt[u][c]=sz++;
}
void dfs(int u,int tp,int len){
	if(tp==-1) g[u][lenl-len]++;
	else if(tp==-2) g[u][lenr-len]++;
	else if(tp==1){
		if(len==lenr) g[u][0]++;
		else if(l[len+1]==r[len+1]) dfs(get(u,r[len+1]-'0'),1,len+1);
		else{
			dfs(get(u,l[len+1]-'0'),2,len+1);
			for(int i=l[len+1]-'0'+1;i<r[len+1]-'0';i++) dfs(get(u,i),-1,len+1);
			dfs(get(u,r[len+1]-'0'),3,len+1);
		}
	}
	else if(tp==2){
		if(len==lenl) g[u][0]++;
		else{
			dfs(get(u,l[len+1]-'0'),2,len+1);
			for(int i=l[len+1]-'0'+1;i<10;i++) dfs(get(u,i),-1,len+1);
		}
	}
	else{
		if(len==lenr) g[u][0]++;
		else{
			for(int i=!len;i<r[len+1]-'0';i++) dfs(get(u,i),-2,len+1);
			dfs(get(u,r[len+1]-'0'),3,len+1);
		}
	}
};
int fail[maxl*20];
void build(){
	queue<int,list<int>> q;
	for(int i=0;i<10;i++){
		int v=nxt[0][i];
		if(!v) continue;
		q.push(v);
		for(int j=0;j<=lenr;j++) g[v][j]+=g[0][j];
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=0;i<10;i++){
			int& v=nxt[u][i];
			if(v){
				fail[v]=nxt[fail[u]][i];
				q.push(v);
				for(int j=0;j<=lenr;j++) g[v][j]+=g[fail[v]][j];
			}
			else v=nxt[fail[u]][i];
		}
	}
	for(int i=0;i<sz;i++) for(int j=1;j<=lenr;j++) g[i][j]+=g[i][j-1];
}
int f[maxn][maxl*20];
const int inf=2e9;
bool c[maxn][maxl*20];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%s%s",l+1,r+1);
	lenl=strlen(l+1);
	lenr=strlen(r+1);
	n=readint();
	if(lenl==lenr) dfs(0,1,0);
	else{
		dfs(get(0,l[1]-'0'),2,1);
		for(int i=l[1]-'0'+1;i<10;i++) dfs(get(0,i),-1,1);
		for(int i=lenl+1;i<lenr;i++) g[0][i]++;
		for(int i=1;i<r[1]-'0';i++) dfs(get(0,i),-2,1);
		dfs(get(0,r[1]-'0'),3,1);
	}
	build();
	for(int i=0;i<=n;i++) for(int j=0;j<sz;j++) f[i][j]=-inf;
	f[0][0]=g[0][min(n,lenr)];
	for(int i=0;i<n;i++) for(int j=0;j<sz;j++) if(f[i][j]>-inf)
		for(int k=0;k<10;k++){
			int v=nxt[j][k];
			f[i+1][v]=max(f[i+1][v],f[i][j]+g[v][min(n-i-1,lenr)]);
		}
	int ans=0;
	for(int i=0;i<sz;i++) ans=max(ans,f[n][i]);
	printf("%d\n",ans);
	for(int i=0;i<sz;i++) if(f[n][i]==ans) c[n][i]=1;
	for(int i=n-1;i>=0;i--) for(int j=0;j<sz;j++)
		if(f[i][j]>-inf) for(int k=0;k<10;k++){
			int v=nxt[j][k];
			if(f[i+1][v]==f[i][j]+g[v][min(lenr,n-i-1)]) c[i][j]|=c[i+1][v];
		}
	int u=0;
	for(int i=0;i<n;i++) for(int j=0;j<10;j++){
		int v=nxt[u][j];
		if(f[i+1][v]==f[i][u]+g[v][min(lenr,n-i-1)]&&c[i+1][v]){
			printf("%d",j);
			u=v;
			break;
		}
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}//