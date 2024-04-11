#include<bits/stdc++.h>
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
const int maxn=1e6+5;
int n,s[maxn];
char S[maxn];
int sz=2,last=0,len[maxn],fail[maxn],nxt[maxn][26],top[maxn];
bool flag[maxn];
void init(){
	len[1]=-1;
	fail[0]=1;
}
int getfail(int p,int x){
	while(x-len[p]<=1||s[x]!=s[x-len[p]-1]) p=fail[p];
	return p;
}
void extend(int x){
	int p=getfail(last,x);
	if(!nxt[p][s[x]]){
		nxt[p][s[x]]=sz;
		len[sz]=len[p]+2;
		if(p==1){
			fail[sz]=0;
			top[sz]=sz;
		}
		else{
			fail[sz]=nxt[getfail(fail[p],x)][s[x]];
			if(top[fail[sz]]==fail[sz]){
				if(flag[fail[sz]]) top[sz]=sz;
				else{
					top[sz]=fail[sz];
					flag[fail[sz]]=1;
				}
			}
			else top[sz]=len[sz]+len[fail[fail[sz]]]==len[fail[sz]]*2?top[fail[sz]]:sz;
		}
		sz++;
	}
	last=nxt[p][s[x]];
}
typedef long long ll;
const ll mod=1e9+7;
ll f[maxn],g[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%s",S+1);
	n=strlen(S+1);
	for(int i=1;i<=n;i++) s[i]=(i%2==1?S[(i+1)/2]:S[n-i/2+1])-'a';
	init();
	f[0]=1;
	for(int i=1;i<=n;i++){
		extend(i);
		int u=last;
		while(u){
			if(top[u]==u) g[u]=f[i-len[u]];
			else g[u]=(g[fail[u]]+f[i-len[top[u]]])%mod;
			if(i%2==0) f[i]=(f[i]+g[u])%mod;
			u=fail[top[u]];
		}
	}
	printf("%lld\n",f[n]);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}