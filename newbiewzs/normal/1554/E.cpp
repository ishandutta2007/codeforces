#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
//#define int long long
using namespace std;
typedef long long ll;
int read(){
	char c=getchar();int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int mod=998244353;
const int N=1e5+5;
int T,n,x,y,f[N],ans[N];
vi v[N];
int ksm(int x,int k){
	int base=1;
	while(k){
		if(k&1)base=1ll*base*x%mod;
		k>>=1;
		x=1ll*x*x%mod;
	}
	return base;
}
int gcd(int x,int y){
	if(!x)return y;
	return gcd(y%x,x);
}
void dfs(int u,int fa,int p){
	int siz=0;
	for(int i=0;i<v[u].size();i++){
		if(v[u][i]==fa)continue;
		dfs(v[u][i],u,p);
		siz++;
	}
	if(!siz){
		f[fa]++;
	}
	else{
		if(fa){
			if(f[u]%p==0)f[fa]++;
			else f[u]++;
		}
	}
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<n;i++){
			x=read();y=read();
			v[x].pb(y);
			v[y].pb(x);
		}
		int tmp=ksm(2,n-1);
		int pre=0;
		for(int i=2;i<n;i++){
			if((n-1)%i==0){
				memset(f,0,(n+1)*4);
				dfs(1,0,i);int mi=0;bool flag=0;
				for(int k=1;k<=n;k++){
					mi=gcd(f[k],mi);
					if(f[k]%i)flag=1;
				}
				if(!flag && mi==i)ans[i]=1,pre++;
			}
		}
		cout<<(tmp-pre+mod)%mod<<" ";
		for(int i=2;i<=n;i++){
			cout<<ans[i]<<" ";
		}
		memset(ans,0,(n+1)*4);
		for(int i=1;i<=n;i++)v[i].clear();
		puts("");
	}
	return 0;
}
/*
1
7
3 1
4 1
5 1
6 1
1 2
2 7
*/