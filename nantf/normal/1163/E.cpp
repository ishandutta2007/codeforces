#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=266666;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
int n,s[maxn],lb[20],vec[20],vl,ans,seq[maxn],sl;
bool vis[maxn],ok;
void insert(int x){
	int tmp=x;
	ROF(i,19,0) if((x>>i)&1){
		if(!lb[i]){
			lb[i]=x;
			vec[++vl]=tmp;
			return;
		}
		else x^=lb[i];
	}
}
bool check(int x){
	FOR(i,0,x-1) if(!lb[i]) return false;
	return true;
}
void dfs(int x){
	vis[x]=true;
	seq[++sl]=x;
	if(sl==(1<<ans)){ok=true;return;}
	FOR(i,1,vl) if(!vis[x^vec[i]]){
		dfs(x^vec[i]);
		if(ok) return;
	}
	vis[x]=false;
	sl--;
}
int main(){
	n=read();
	FOR(i,1,n) s[i]=read();
	ROF(_,19,0){
		MEM(lb,0);MEM(vec,0);vl=0;
		FOR(i,1,n) if(s[i]<=(1<<_)-1) insert(s[i]);
		if(check(_)){ans=_;break;}
	}
	printf("%d\n",ans);
	dfs(0);
	FOR(i,1,sl) printf("%d ",seq[i]);
}