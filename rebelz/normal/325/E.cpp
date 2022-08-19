#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,cnt;
int ans[100005];
bool vis[100005];

void dfs(int u){
	if(vis[u]) return;
	vis[u]=1;
	dfs((u<<1)%n),dfs((u<<1|1)%n);
	ans[++cnt]=u;
}

int main(){
	n=readint();
	if(n&1) return printf("-1\n"),0;
	dfs(0);
	for(int i=cnt;i>=1;i--) printf("%d ",ans[i]);
	printf("0\n");
	return 0;
}