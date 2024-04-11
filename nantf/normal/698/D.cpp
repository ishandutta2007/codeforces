#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxk=11,maxn=1111;
#define MP make_pair
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
int k,n,sx[maxk],sy[maxk],tx[maxn],ty[maxn],p[maxn],piv,ans,seq[maxk],cur,tmp[maxk],tl;
vector<int> v[maxk][maxn];
bool used[maxk],vis[maxn];
inline ll dis(int x1,int y1,int x2,int y2){
	int xd=x1-x2,yd=y1-y2;
	return 1ll*xd*xd+1ll*yd*yd;
}
inline bool cmp(int x,int y){
	return dis(sx[piv],sy[piv],tx[x],ty[x])>dis(sx[piv],sy[piv],tx[y],ty[y]);
}
inline bool on(int x,int y,int x1,int y1,int x2,int y2){
	int xd1=x1-x,yd1=y1-y,xd2=x2-x,yd2=y2-y;
	if(1ll*xd1*yd2!=1ll*yd1*xd2) return false;
	if(x<min(x1,x2) || x>max(x1,x2)) return false;
	if(y<min(y1,y2) || y>max(y1,y2)) return false;
	return true; 
}
bool check(int to){
	int now=--cur;
	FOR(i,0,(int)v[seq[now]][to].size()-1){
		int x=v[seq[now]][to][i];
		if(vis[x]) continue;
		if(!check(x) || !cur) return false;
	}
	if(cur) return vis[tmp[++tl]=to]=true;
	else return false;
}
bool dfs(int dep,int to){
	if(dep>k){
		cur=k+1;tl=0;
		bool flag=check(to);
		FOR(i,1,tl) vis[tmp[i]]=false;
		return flag;
	}
	FOR(i,1,k) if(!used[i]){
		used[i]=true;
		seq[dep]=i;
		bool flag=dfs(dep+1,to);
		used[i]=false;
		if(flag) return true;
	}
	return false;
}
int main(){
	k=read();n=read();
	FOR(i,1,k) sx[i]=read(),sy[i]=read();
	FOR(i,1,n) tx[i]=read(),ty[i]=read();
	FOR(i,1,k){
		piv=i;
		FOR(j,1,n) p[j]=j;
		sort(p+1,p+n+1);
		FOR(j,1,n) FOR(k,1,n) if(j!=p[k] && on(tx[p[k]],ty[p[k]],sx[i],sy[i],tx[j],ty[j])) v[i][j].push_back(p[k]);
	}
	FOR(i,1,n) if(dfs(1,i)) ans++;
	printf("%d\n",ans);
}