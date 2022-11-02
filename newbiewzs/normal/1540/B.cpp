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
//#include<unordered_map>
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
const int N=205;
const int mod=1e9+7;
int n,x,y;
vi v[N];
int g[N][N],deep[N],f[N][8];
int ksm(int x,int k){
	int base=1;
	while(k){
		if(k&1)base=1ll*base*x%mod;
		k>>=1;
		x=1ll*x*x%mod;
	}
	return base;
}
int inv(int x){
	return ksm(x,mod-2);
}
int ans=0;
void dfs(int u,int fa){
	f[u][0]=fa;deep[u]=deep[fa]+1;
	for(int i=1;i<=7;i++)f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<v[u].size();i++){
		if(v[u][i]==fa)continue;
		dfs(v[u][i],u);
	}
}
int lca(int x,int y){
	if(deep[x]<deep[y])swap(x,y);
	for(int i=7;i>=0;i--){
		if(deep[x]-(1<<i)>=deep[y]){
			x=f[x][i];
		}
	}
	if(x==y)return x;
	for(int i=7;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		x=read();y=read();
		v[x].pb(y);v[y].pb(x);
	}
	for(int i=1;i<=n;i++)g[i][0]=1;
	int er=inv(2);
	//cout<<"???"<<er<<endl;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			g[i][k]=1ll*er*(g[i-1][k]+g[i][k-1])%mod;
		//	cout<<i<<" "<<k<<" "<<f[i][k]<<endl;
		}
	}
//	cout<<f[1][0]<<endl;
	int da=0;
	for(int i=1;i<=n;i++){
		ans=0;
		dfs(i,0);
		//cout<<"!!!"<<i<<":"<<endl<<endl;
		for(int k=1;k<=n;k++){
			for(int j=1;j<=n;j++){
				if(k==j)continue;
				if(k>j)continue;
				int L=lca(k,j);
				int la=deep[k]-deep[L];
				int lb=deep[j]-deep[L];
			//	cout<<f[1][0]<<"????"<<endl;
			//	cout<<"se:"<<la<<" "<<lb<<" "<<f[la][lb]<<endl;
				ans=(ans+g[la][lb])%mod;
			}
		}
		ans=1ll*ans*inv(n)%mod;
		da=(da+ans)%mod;
	}
	cout<<da;
	return 0;
}