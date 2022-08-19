// xtqqwq
#include<bits/stdc++.h>

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

int n,m;
int dis[200005],sum[200005];
bool vis[200005];
vector<int> adj1[200005],adj2[200005];
priority_queue<pii> q;

void dij(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	q.push(mp(0,s));
	while(!q.empty()){
		int t=q.top().se; q.pop();
		if(vis[t]) continue;
		vis[t]=1;
		for(auto v:adj2[t]){
			sum[v]++;
			if(chkmin(dis[v],(int)adj1[v].size()-sum[v]+dis[t]+1)) q.push(mp(-dis[v],v));
		}
	}
}

int main(){
	n=readint(); m=readint();
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		adj1[x].pb(y);
		adj2[y].pb(x);
	}
	dij(n);
	printf("%d\n",dis[1]);
	return 0;
}