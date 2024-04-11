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
char s1[maxn],s2[maxn];
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
			if(len[fail[sz]]*2<len[sz]) top[sz]=sz;
			else if(top[fail[sz]]==fail[sz]){
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
int f[maxn],g[maxn],cf[maxn],cg[maxn];
const int inf=2e9;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%s%s",s1+1,s2+1);
	n=strlen(s1+1)*2;
	for(int i=1;i<=n;i++) s[i]=(i%2==1?s1[(i+1)/2]:s2[i/2])-'a';
	init();
	for(int i=1;i<=n;i++){
		extend(i);
		int u=last;
		f[i]=inf;
		while(u){
			if(top[u]==u){
				g[u]=f[i-len[u]];
				cg[u]=i-len[u];
			}
			else if(f[i-len[top[u]]]<g[fail[u]]){
				g[u]=f[i-len[top[u]]];
				cg[u]=i-len[top[u]];
			}
			else{
				g[u]=g[fail[u]];
				cg[u]=cg[fail[u]];
			}
			if(g[u]+1<f[i]){
				f[i]=g[u]+1;
				cf[i]=cg[u];
			}
			u=fail[top[u]];
		}
		if(i%2==1) f[i]=inf;
		else if(s[i-1]==s[i]&&f[i-2]<f[i]){
			f[i]=f[i-2];
			cf[i]=i-2;
		}
	}
	if(f[n]==inf){
		printf("-1\n");
		return 0;
	}
	printf("%d\n",f[n]);
	int u=n;
	while(u){
		if(u-cf[u]>2) printf("%d %d\n",cf[u]/2+1,u/2);
		u=cf[u];
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}