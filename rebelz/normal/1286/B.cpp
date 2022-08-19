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

int n,rt,tot;
vector<int> vec[2005];
int v[2005],nxt[2005],h[2005],a[2005],f[2005];

void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;}

void dfs(int u){
	bool fl=0;
	if(a[u]==0) vec[u].push_back(u),fl=1;
	for(int p=h[u];p;p=nxt[p]){
		dfs(v[p]);
		for(auto x:vec[v[p]]){
			vec[u].push_back(x);
			if(vec[u].size()==a[u]) vec[u].push_back(u),fl=1;
		}
	}
	if(!fl){
		printf("NO\n");
		exit(0);
	}
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++){
		f[i]=readint();
		if(!f[i]) rt=i;
		else addedge(f[i],i);
		a[i]=readint();
	}
	dfs(rt);
	printf("YES\n");
	int cnt=0;
	for(auto x:vec[rt]) a[x]=++cnt;
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}