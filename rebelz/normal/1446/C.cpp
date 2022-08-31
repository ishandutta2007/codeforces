#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
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

int n,ncnt;
int ch[6000005][2],siz[6000005],d[6000005];

void insert(int x){
	int p=0;
	for(int i=29;i>=0;i--){
		if(!ch[p][(x>>i)&1]) ch[p][(x>>i)&1]=++ncnt;
		p=ch[p][(x>>i)&1];
		siz[p]++;
	}
}

void dfs(int u){
	if(ch[u][0]) dfs(ch[u][0]);
	if(ch[u][1]) dfs(ch[u][1]);
	if(!ch[u][0]&&!ch[u][1]) return;
	if(!ch[u][0]) return (void)(d[u]=d[ch[u][1]]);
	if(!ch[u][1]) return (void)(d[u]=d[ch[u][0]]);
	d[u]=min(d[ch[u][0]]+siz[ch[u][1]]-1,d[ch[u][1]]+siz[ch[u][0]]-1);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) insert(readint());
	dfs(0);
	printf("%d\n",d[0]);
	return 0;
}