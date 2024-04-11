#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111,maxm=111111,maxs=1111111,mod=998244353;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,m,T,el,head[maxn],to[maxm],nxt[maxm],deg[maxn],q[maxn],h=1,r=0,id[maxn],tl,x[4444],y[4444],S[maxn],at[22];
char op[4444],ver[10];
bool vis[maxs];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
inline void add(char c,int xx,int yy){
	tl++;
	op[tl]=c;
	x[tl]=xx;
	y[tl]=yy;
}
int main(){
	n=read();m=read();T=read();
	FOR(i,1,m){
		int u=read(),v=read();
		add(u,v);
		deg[v]++;
	}
	FOR(i,1,n) if(!deg[i]) q[++r]=i;
	while(h<=r){
		int u=q[h++];
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(!--deg[v]) q[++r]=v;
		}
	}
	FOR(i,1,n) id[i]=-1;
	ROF(i,r,max(1,r-19)) id[q[i]]=r-i,at[r-i]=q[i];
	FOR(i,max(1,r-19),r) FOR(j,i+1,r) add('+',q[i],q[j]);
	if(r-20>=1){
		FOR(i,1,r-20){
			add('+',q[i],q[i]);
			for(int j=head[q[i]];j;j=nxt[j]) if(~id[to[j]]) S[q[i]]|=1<<id[to[j]];
			bool flag=false;
			ROF(x,20,0){
				ROF(y,20,x+1){
					ROF(z,20,y+1){
						int tmp=S[q[i]];
						if(x<=19) tmp^=1<<x;
						if(y<=19) tmp^=1<<y;
						if(z<=19) tmp^=1<<z;
						if(!vis[tmp]){
							FOR(w,0,19){
								int a=(S[q[i]]>>w)&1,b=(tmp>>w)&1;
								if(!a && b) add('+',q[i],at[w]);
								if(a && !b) add('-',q[i],at[w]);
							}
							S[q[i]]=tmp;
							vis[tmp]=true;
							flag=true;
							break;
						}
					}
					if(flag) break;
				}
				if(flag) break;
			}
			if(!flag) return puts("/kk"),1;
		}
	}
	printf("%d\n",tl);
	FOR(i,1,tl) printf("%c %d %d\n",op[i],x[i],y[i]);
	fflush(stdout);
	while(T--){
		int s=0,flag=0;
		FOR(i,0,min(r-1,19)){
			printf("? 1 %d\n",at[i]);
			fflush(stdout);
			scanf("%s",ver);
			switch(ver[0]){
				case 'W':
					s|=1<<i;
					break;
				case 'L':
					flag=at[i];
					break;
				case 'D':
					break;
			}
		}
		if(flag) printf("! %d\n",flag);
		else{
			FOR(i,1,r-20) if(S[q[i]]==s){
				printf("! %d\n",q[i]);
				break;
			}
		}
		fflush(stdout);
		scanf("%s",ver);
		if(ver[0]=='W') return puts("/kk"),2;
	}
}