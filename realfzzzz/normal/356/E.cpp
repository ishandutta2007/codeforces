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
const int maxn=1e5+5;
int n;
char S[maxn];
int sz=1,last=0,len[maxn*2],link[maxn*2],nxt[maxn*2][26];
vector<int> g[maxn*2];
void extend(int c){
	int cur=sz++;
	len[cur]=len[last]+1;
	int p=last;
	while(p>=0&&!nxt[p][c]){
		nxt[p][c]=cur;
		p=link[p];
	}
	if(p>=0){
		int q=nxt[p][c];
		if(len[q]==len[p]+1) link[cur]=q;
		else{
			int clone=sz++;
			len[clone]=len[p]+1;
			link[clone]=link[q];
			memcpy(nxt[clone],nxt[q],sizeof(nxt[0]));
			while(p>=0&&nxt[p][c]==q){
				nxt[p][c]=clone;
				p=link[p];
			}
			link[cur]=link[q]=clone;
		}
	}
	last=cur;
}
int cur[maxn];
int size[maxn*2],dep[maxn*2],hson[maxn*2];
void dfs1(int u){
	size[u]=1;
	dep[u]=u?dep[link[u]]+1:1;
	hson[u]=-1;
	for(int v:g[u]){
		dfs1(v);
		size[u]+=size[v];
		if(hson[u]<0||size[v]>size[hson[u]]) hson[u]=v;
	}
}
int top[maxn*2];
void dfs2(int u){
	if(hson[u]<0) return;
	top[hson[u]]=top[u];
	dfs2(hson[u]);
	for(int v:g[u]) if(v!=hson[u]){
		top[v]=v;
		dfs2(v);
	}
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=link[top[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	return y;
}
int lcs(int x,int y){
	return len[lca(cur[x],cur[y])];
}
int s[maxn][26];
bool t[20][maxn];
ll sum,c[maxn],f[maxn][26];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%s",S+1);
	n=strlen(S+1);
	link[0]=-1;
	for(int i=1;i<=n;i++){
		extend(S[i]-'a');
		cur[i]=last;
	}
	for(int i=1;i<sz;i++) g[link[i]].push_back(i);
	dfs1(0);
	dfs2(0);
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++) s[i][j]=s[i-1][j];
		s[i][S[i]-'a']++;
	}
	for(int i=1;i<=n;i++) t[1][i]=1;
	sum=n;
	for(int i=2;(1<<i)-1<=n;i++) for(int j=1;j+(1<<i)-2<=n;j++){
		int mid=j+(1<<(i-1))-1,r=j+(1<<i)-2,cs=lcs(mid-1,r);
		ll v=1ll*((1<<i)-1)*((1<<i)-1);
		if(t[i-1][j]&&t[i-1][mid+1]&&s[r][S[mid]-'a']-s[j-1][S[mid]-'a']==1&&cs>=(1<<(i-1))-1){
			t[i][j]=1;
			sum+=v;
			c[j]+=v;
			c[r+1]-=v;
		}
		if(t[i-1][j]&&t[i-1][mid+1]&&cs>=(1<<(i-1))-1)
			for(int k=0;k<26;k++) if(s[r][k]-s[j-1][k]==(S[mid]-'a'==k)) f[mid][k]+=v;
		if(cs<(1<<(i-1))-1&&lcs(mid-cs-2,r-cs-1)>=(1<<(i-1))-cs-2){
			if(t[i-1][j]&&s[r][S[mid]-'a']-s[j-1][S[mid]-'a']-(S[r-cs]==S[mid])==1) f[r-cs][S[mid-cs-1]-'a']+=v;
			if(t[i-1][mid+1]&&s[r][S[mid]-'a']-s[j-1][S[mid]-'a']-(S[mid-cs-1]==S[mid])==1) f[mid-cs-1][S[r-cs]-'a']+=v;
		}
	}
	for(int i=1;i<=n;i++) c[i]+=c[i-1];
	ll ans=sum;
	for(int i=1;i<=n;i++) for(int j=0;j<26;j++) if(j!=S[i]-'a') ans=max(ans,sum-c[i]+f[i][j]);
	printf("%lld\n",ans);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}