#include<algorithm>
#include<map>
#include<cstring>
#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
	int x=0;
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
const int maxn=1e3+5,maxd=50+5;
int n,d;
char s[maxn],x[maxd],y[maxd];
int sz,last,len[maxn*2],link[maxn*2];
map<char,int> nxt[maxn*2];
void init(){
	sz=1;
	last=0;
	len[0]=0;
	link[0]=-1;
}
void extend(char c){
	int cur=sz++;
	len[cur]=len[last]+1;
	int p=last;
	while(p>=0&&!nxt[p].count(c)){
		nxt[p][c]=cur;
		p=link[p];
	}
	if(p<0) link[cur]=0;
	else{
		int q=nxt[p][c];
		if(len[p]+1==len[q]) link[cur]=q;
		else{
			int clone=sz++;
			len[clone]=len[p]+1;
			link[clone]=link[q];
			nxt[clone]=nxt[q];
			while(p>=0&&nxt[p][c]==q){
				nxt[p][c]=clone;
				p=link[p];
			}
			link[q]=link[cur]=clone;
		}
	}
	last=cur;
}
int trans[maxn*2][10];
typedef long long ll;
const ll mod=1e9+7;
ll f[maxd][2][maxn*2][maxd][2];
bool vis[maxd][2][maxn*2][maxd][2];
ll dp(int x,bool f1,int u,int l,bool f2,char* s,bool t){
	if(x==d) return f2&&(!f1||t);
	ll& ans=f[x][f1][u][l][f2];
	if(vis[x][f1][u][l][f2]) return ans;
	vis[x][f1][u][l][f2]=1;
	ans=0;
	for(int i=0;i<=(f1?s[x]-'0':9);i++)
		if(trans[u][i]<0) ans=(ans+dp(x+1,f1&&i==s[x]-'0',0,0,f2,s,t))%mod;
		else{
			int v=trans[u][i],_l=min(v==u?l+1:len[v]+1,d/2);
			ans=(ans+dp(x+1,f1&&i==s[x]-'0',nxt[v][i+'0'],_l,f2||_l==d/2,s,t))%mod;
		}
	return ans;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%s%s%s",s,x,y);
	n=strlen(s);
	d=strlen(x);
	init();
	for(int i=0;i<n;i++) extend(s[i]);
	for(int i=0;i<sz;i++) for(int j=0;j<10;j++){
		int u=i;
		while(u>=0&&!nxt[u].count(j+'0')) u=link[u];
		trans[i][j]=u;
	}
	ll ans=dp(0,1,0,0,0,y,1);
	memset(vis,0,sizeof(vis));
	ans=(ans+mod-dp(0,1,0,0,0,x,0))%mod;
	printf("%lld\n",ans);
	return 0;
}