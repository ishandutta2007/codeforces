#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,cnt;
int a[1000005],b[1000005],vis[1000005];

bool dfs(int u){
	b[++cnt]=u;
	vis[u]=cnt;
	if(vis[a[u]]){
		printf("%d\n",cnt-vis[a[u]]+1);
		for(int i=vis[a[u]];i<=cnt;i++) printf("%d ",b[i]);
		printf("\n");
		return true;
	}
	return dfs(a[u]);
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		cnt=0;
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=n;i++) a[i]=i-readint();
		for(int i=1;i<=n;i++) if(dfs(i)) break;
	}
	return 0;
}