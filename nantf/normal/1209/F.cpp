#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int maxn=1337337,mod=1000000007;
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
int n,m,cnt,h,r,q[maxn],ans[maxn];
vector<int> e[maxn][10];
bool vis[maxn],ch[maxn];
int main(){
	cnt=n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read();
		int tmp=i,pre=v;
		while(tmp>9){
			e[++cnt][tmp%10].push_back(pre);
			tmp/=10;pre=cnt;
		}
		e[u][tmp].push_back(pre);
		tmp=i;pre=u;
		while(tmp>9){
			e[++cnt][tmp%10].push_back(pre);
			tmp/=10;pre=cnt;
		}
		e[v][tmp].push_back(pre);
	}
	q[h=r=1]=1;
	vis[1]=true;
	ans[1]=0;
	while(h<=r){
		int L=h,R=0;
		FOR(i,h+1,r) if(ch[q[i]]){R=i-1;break;}
		if(!R) R=r;
		FOR(j,0,9){
			bool flag=false;
			FOR(i,L,R){
				int u=q[i];
				FOR(k,0,(int)e[u][j].size()-1){
					int v=e[u][j][k];
					if(vis[v]) continue;
					vis[v]=true;
					ans[v]=(10ll*ans[u]+j)%mod;
					if(!flag) flag=ch[v]=true;
					q[++r]=v;
				}
			}
		}
		h=R+1;
	}
	FOR(i,2,n) printf("%d\n",ans[i]);
}