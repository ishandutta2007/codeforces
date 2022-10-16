#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
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
int n,m,el,head[80],to[222],nxt[222],w[222];
ll f[80][80],ans;
inline void add(int u,int v,int w_){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w[el]=w_;
}
bool check(int x,int y,int l,int r){
	if(x>=1 && x<=2*n){
		for(int i=head[x];i;i=nxt[i]){
			int v=to[i];
			switch(w[i]){
				case 1:if(v>l && v<r && v!=y) return false;break;
				case 0:if(v<=l || v>=r) return false;break;
				case 3:if(v>l && v<r) return false;break;
				case 2:if(v<=l || v>=r || v==y) return false;break;
				case 4:if(v!=y) return false;break;
			}
		}
	}
	else return false;
	if(y>=1 && y<=2*n){
		for(int i=head[y];i;i=nxt[i]){
			int v=to[i];
			switch(w[i]){
				case 1:if(v>l && v<r && v!=x) return false;break;
				case 0:if(v<=l || v>=r) return false;break;
				case 3:if(v>l && v<r) return false;break;
				case 2:if(v<=l || v>=r || v==x) return false;break;
				case 4:if(v!=x) return false;break;
			}
		}
	}
	else return false;
	return true;
}
int main(){
	n=read();m=read();
	FOR(i,1,m){
		int x=read(),y;
		char op[10];scanf("%s",op);
		y=read();
		if(op[0]=='<'){
			if(op[1]=='='){
				if(x==y) continue;
				add(x,y,0),add(y,x,1);
			}
			else{
				if(x==y) return puts("0"),0;
				add(x,y,2),add(y,x,3);
			}
		}
		else if(op[0]=='>'){
			if(op[1]=='='){
				if(x==y) continue;
				add(x,y,1),add(y,x,0);
			}
			else{
				if(x==y) return puts("0"),0;
				add(x,y,3),add(y,x,2);
			}
		}
		else{
			if(x==y) continue;
			add(x,y,4),add(y,x,4);
		}
	}
	f[0][2*n+1]=1;
	FOR(i,1,n) FOR(j,0,2*i){
		if(check(j-1,j,j-2,2*n+1-(2*i-j)))
			f[j][2*n+1-(2*i-j)]+=f[j-2][2*n+1-(2*i-j)];
		if(check(2*n+1-(2*i-j),2*n+1-(2*i-j)+1,j,2*n+1-(2*i-j)+2))
			f[j][2*n+1-(2*i-j)]+=f[j][2*n+1-(2*i-j)+2];
		if(check(j,2*n+1-(2*i-j),j-1,2*n+1-(2*i-j)+1))
			f[j][2*n+1-(2*i-j)]+=f[j-1][2*n+1-(2*i-j)+1];
	}
	FOR(j,0,2*n) ans+=f[j][j+1];
	printf("%lld\n",ans/3);
}