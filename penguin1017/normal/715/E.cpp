#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
using namespace std;
const int N=1e3+9;
const int mod=998244353;
inline int add(int a,const int &b){
	a+=b;
	if(a>=mod)a-=mod;
	return a;
}
inline int mul(const int &a,const int &b){return 1ll*a*b%mod;}
int inv[N],jie[N],S[N][N];
int C(int n,int m){
	if(m>n||n<0||m<0)return 0;
	return mul(jie[n],mul(inv[n-m],inv[m]));
}
int a[N],b[N],pos[N];
int f[N],g[N],h[N];
bool vis[N]; 
int c[4];
void dfs(int u){
	if(!u){
		c[1]++;
		return;
	}
	vis[u]=1;
	if(!b[u]){
		c[3]++;
		return;
	}
	dfs(pos[b[u]]);
}
int ok;
void dfs2(int u){
	if(!u)return;
	if(vis[u]){
		ok=u;
		return;
	} 
	vis[u]=1;
	dfs2(pos[a[u]]);
}
int ans[N];
int main(){
	S[0][0]=1;
	rep(i,1,N){
		rep(j,1,i+1)S[i][j]=add(S[i-1][j-1],mul(i-1,S[i-1][j]));
	} 
	inv[0]=inv[1]=1;
	jie[0]=1;
	rep(i,2,N)inv[i]=-1ll*mod/i*inv[mod%i]%mod+mod;
	rep(i,1,N)jie[i]=mul(jie[i-1],i),inv[i]=mul(inv[i],inv[i-1]);
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%d",&a[i]);
	rep(i,1,n+1)scanf("%d",&b[i]);
	rep(i,1,n+1){
		if(a[i])pos[a[i]]=i;
	}
	rep(i,1,n+1){
		if(!a[i]){
			vis[i]=1;
			if(!b[i]){
				c[3]++;
			}
			else {
				dfs(pos[b[i]]);
			}
		}
	}
	memset(pos,0,sizeof pos);
	rep(i,1,n+1)if(b[i])pos[b[i]]=i;
	rep(i,1,n+1){
		if(vis[i])continue;
		if(!b[i])vis[i]=1,c[2]++,dfs2(pos[a[i]]);
	}
	rep(i,1,n+1){
		if(vis[i])continue;
		vis[i]=1;
		ok=0;
		dfs2(pos[a[i]]);
		if(ok==i)c[0]++;
	}
//	c[0]=3,c[1]=4,c[2]=9,c[3]=8;
//	cout<<c[0]<<' '<<c[1]<<' '<<c[2]<<' '<<c[3]<<"check\n";
	rep(i,0,c[1]+1){
		rep(j,i,c[1]+1){
			if(c[3])f[i]=add(f[i],mul(mul(jie[c[3]-1+c[1]-j],inv[c[3]-1]),mul(C(c[1],j),S[j][i])));
			else if(j==c[1])f[i]=add(f[i],S[j][i]);
		}
//		cout<<i<<' '<<f[i]<<"F\n";
	}
	rep(i,0,c[2]+1){
		rep(j,i,c[2]+1){
			if(c[3])g[i]=add(g[i],mul(mul(jie[c[3]-1+c[2]-j],inv[c[3]-1]),mul(C(c[2],j),S[j][i])));
			else if(j==c[2])g[i]=add(g[i],S[j][i]);
		}
//		cout<<i<<' '<<g[i]<<"G\n";
	}
	rep(i,0,c[3]+1)h[i]=mul(jie[c[3]],S[c[3]][i]);//,cout<<h[i]<<"H\n";
	rep(i,0,n+1){
		rep(j,0,i+1){
			rep(k,0,i-j+1){
				ans[i]=add(ans[i],mul(mul(f[j],g[k]),h[i-j-k]));
			//	cout<<j<<' '<<k<<' '<<i-j-k<<' '<<"val\n"<<f[j]<<' '<<g[k]<<' '<<h[i-j-k]<<"ok\n";
			}
		}
	}
	per(i,c[0],n+1)ans[i]=ans[i-c[0]];
	rep(i,0,c[0])ans[i]=0;
//	cout<<c[0]<<' '<<c[1]<<' '<<c[2]<<' '<<c[3]<<endl;
//	cout<<ans[n-218]<<"??\n";
	per(i,1,n+1)printf("%d ",ans[i]);
}