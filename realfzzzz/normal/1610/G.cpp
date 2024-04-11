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
const int maxn=3e5+5;
int n;
char s[maxn];
int cnt=1,fa[maxn][20],w[maxn];
const ll mod1=1e9+7,mod2=998244353;
ll pw1[20],pw2[20],hs1[maxn][20],hs2[maxn][20];
int newnode(int u,int c){
	fa[++cnt][0]=u;
	w[cnt]=hs1[cnt][0]=hs2[cnt][0]=c;
	for(int i=1;i<20;i++){
		fa[cnt][i]=fa[fa[cnt][i-1]][i-1];
		if(!fa[cnt][i]) break;
		hs1[cnt][i]=(hs1[fa[cnt][i-1]][i-1]*pw1[i-1]%mod1+hs1[cnt][i-1])%mod1;
		hs2[cnt][i]=(hs2[fa[cnt][i-1]][i-1]*pw2[i-1]%mod2+hs2[cnt][i-1])%mod2;
	}
	return cnt;
}
bool cmp(int x,int y){
	for(int i=19;i>=0;i--)
		if(fa[x][i]&&fa[y][i]&&hs1[x][i]==hs1[y][i]&&hs2[x][i]==hs2[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	return x==1||!w[x];
}
int f[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%s",s+1);
	n=strlen(s+1);
	pw1[0]=2;
	pw2[0]=311;
	for(int i=1;i<20;i++){
		pw1[i]=pw1[i-1]*pw1[i-1]%mod1;
		pw2[i]=pw2[i-1]*pw2[i-1]%mod2;
	}
	stack<int> stk;
	f[n+1]=1;
	for(int i=n;i>0;i--)
		if(s[i]==')'){
			f[i]=newnode(f[i+1],1);
			stk.push(i);
		}
		else{
			f[i]=newnode(f[i+1],0);
			if(!stk.size()) continue;
			if(cmp(f[stk.top()+1],f[i])) f[i]=f[stk.top()+1];
			stk.pop();
		}
	int u=f[1];
	while(u>1){
		printf(w[u]?")":"(");
		u=fa[u][0];
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}