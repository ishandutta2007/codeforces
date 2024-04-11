#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#include<math.h>
#include<unordered_map>
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define ci ios::sync_with_stdio(false)
//#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int read(){
	char c=getchar();
	ll x=1,s=0;
	while(c<'0'||c>'9'){
	   if(c=='-')x=-1;c=getchar();
	}
	while(c>='0'&&c<='9'){
	   s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=4000;
int n,x,y,top,flag,deep[N],pd[N],st[N],vis[N],f[N][13],bh[N],cnt,cd[N],head;
vi v[N];
double ans=0;
void dfs(int u,int fa){
	f[u][0]=fa;deep[u]=deep[fa]+1;
	for(int i=1;i<=12;i++)f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<v[u].size();i++){
		if(v[u][i]==fa || vis[v[u][i]])continue;
		dfs(v[u][i],u);
	}
}
void find(int u,int fa){
	if(pd[u]){
		vis[u]=1;
		while(st[top]!=u){
			vis[st[top]]=1;
			bh[st[top]]=++cnt;
			cd[++head]=st[top];
			top--;
		}
		flag=1;
		cd[++head]=u;
		bh[u]=++cnt;
		return ;
	}
	pd[u]=1;
	st[++top]=u;
	for(int i=0;i<v[u].size();i++){
		if(v[u][i]==fa)continue;
		find(v[u][i],u);
		if(flag)return ;
	}
}
int tiao(int x){
	for(int i=12;i>=0;i--){
		if(f[x][i])x=f[x][i];
	}
	return x;
}
int lca(int x,int y){
	if(deep[x]<deep[y])swap(x,y);
	for(int i=12;i>=0;i--){
		if(deep[x]-(1<<i)>=deep[y])x=f[x][i];
	}
	if(x==y)return x;
	for(int i=12;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		x=read()+1;y=read()+1;
		v[x].pb(y);v[y].pb(x);
	}
	find(1,0);
	for(int i=1;i<=head;i++)dfs(cd[i],cd[i]);
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
		//	if(i==k)continue;
			int u=tiao(i);
			int v=tiao(k);
			if(u==v){
				int g=lca(i,k);
				int D=deep[i]+deep[k]-2*deep[g]+1;
				ans+=1.0/D;
			}
			else{
				int l1=abs(bh[u]-bh[v])+1;
				int l2=cnt-l1+2;
			//	l1-=1;l2-=1;
				int L=deep[i]-deep[v]+deep[k]-deep[u];
				if(L+l1)ans+=1.0/(L+l1);
				if(L+l2)ans+=1.0/(L+l2);
				ans-=1.0/(L+cnt);
			}
		}
	}
	printf("%.8lf",ans);
	return 0;
}