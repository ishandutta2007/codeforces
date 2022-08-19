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

int n,m,tot;
int v[1000005],nxt[1000005],h[505],a[505][505],col[505];
char ans[505];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

bool dfs(int u){
	for(int p=h[u];p;p=nxt[p]){
		if(col[v[p]]<0){
			col[v[p]]=col[u]^1;
			if(!dfs(v[p])) return false;
		}
		else if(col[v[p]]!=(col[u]^1)) return false;
	}
	return true;
}

int main(){
	n=readint(); m=readint();
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		a[x][y]=a[y][x]=1;
	}
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(!a[i][j]) addedge(i,j);
	memset(col,-1,sizeof(col));
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(col[i]<0&&h[i]){
			cnt++;
			col[i]=0;
			if(!dfs(i)) return printf("No\n"),0;
			if(cnt==2) return printf("No\n"),0;
		}
		else ans[i]='b';
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(col[i]>=0&&col[j]>=0&&col[i]!=col[j]&&a[i][j]==1) return printf("No\n"),0;
		}
	}
	for(int i=1;i<=n;i++) if(col[i]>=0) ans[i]=col[i]?'a':'c';
	printf("Yes\n");
	for(int i=1;i<=n;i++) printf("%c",ans[i]);
	printf("\n");
	return 0;
}