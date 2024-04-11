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

int n,k,ncnt;
int ch[10000005][2],mina[10000005],maxa[10000005],res[10000005],ans[1100005];
vector<int> vec[25];

void insert(int x){
	int p=0;
	for(int i=k-1;i>=0;i--){
		int t=(x>>i)&1;
		if(!ch[p][t]){
			ch[p][t]=++ncnt;
			if(i) vec[i-1].pb(ncnt);
		}
		p=ch[p][t];
	}
}

void update(int u,int dep,int lim){
	if(dep==lim){
		mina[u]^=1<<lim,maxa[u]^=1<<lim;
		return;
	}
	res[u]=1<<30;
	if(ch[u][0]) update(ch[u][0],dep-1,lim),chkmin(res[u],res[ch[u][0]]);
	if(ch[u][1]) update(ch[u][1],dep-1,lim),chkmin(res[u],res[ch[u][1]]);
	if(ch[u][0]&&ch[u][1]) chkmin(res[u],mina[ch[u][1]]-maxa[ch[u][0]]);
	mina[u]=1<<30,maxa[u]=0;
	if(ch[u][0]) chkmin(mina[u],mina[ch[u][0]]),chkmax(maxa[u],maxa[ch[u][0]]);
	if(ch[u][1]) chkmin(mina[u],mina[ch[u][1]]),chkmax(maxa[u],maxa[ch[u][1]]);
}

void dfs(int u,int now,int dep){
	if(dep<0){
		mina[u]=maxa[u]=now,res[u]=1<<30;
		return;
	}
	res[u]=1<<30;
	if(ch[u][0]) dfs(ch[u][0],now,dep-1),chkmin(res[u],res[ch[u][0]]);
	if(ch[u][1]) dfs(ch[u][1],now^(1<<dep),dep-1),chkmin(res[u],res[ch[u][1]]);
	if(ch[u][0]&&ch[u][1]) chkmin(res[u],mina[ch[u][1]]-maxa[ch[u][0]]);
	mina[u]=1<<30,maxa[u]=0;
	if(ch[u][0]) chkmin(mina[u],mina[ch[u][0]]),chkmax(maxa[u],maxa[ch[u][0]]);
	if(ch[u][1]) chkmin(mina[u],mina[ch[u][1]]),chkmax(maxa[u],maxa[ch[u][1]]);
}

void work(int dep,int now){
	if(dep==k){
		ans[now]=res[0];
		return;
	}
	work(dep+1,now);
	now^=1<<dep;
	for(auto r:vec[dep]) swap(ch[r][0],ch[r][1]);
	update(0,k,dep);
	work(dep+1,now);
	for(auto r:vec[dep]) swap(ch[r][0],ch[r][1]);
}

int main(){
	n=readint(); k=readint();
	vec[k-1].pb(0);
	for(int i=1;i<=n;i++) insert(readint());
	dfs(0,0,k-1);
	work(0,0);
	for(int i=0;i<(1<<k);i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}