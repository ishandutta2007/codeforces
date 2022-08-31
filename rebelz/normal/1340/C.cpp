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

struct node{
	int val,id;
	node(int val=0,int id=0):val(val),id(id){}
	bool operator<(const node c)const{return val<c.val;}
};

int n,m,g,r;
int a[10005];
int d[10005][1005];
bool vis[10005][1005];
priority_queue<node> q;

int id(int x,int y){return (x-1)*g+y-1;}

void dij(){
	memset(d,0x3f,sizeof(d));
	q.push(node(0,id(1,g))); d[1][g]=0;
	while(!q.empty()){
		int tid=q.top().id; q.pop();
		pii t=mp(tid/g+1,tid%g+1);
		if(vis[t.fi][t.se]) continue;
		if(t.fi==m){
			if(t.se==g) printf("%d\n",d[t.fi][t.se]-r);
			else printf("%d\n",d[t.fi][t.se]);
			return;
		}
		vis[t.fi][t.se]=1;
		if(t.fi>1){
			int tx=t.fi-1,ty=t.se-a[t.fi]+a[t.fi-1];
			if(ty>0){
				if(chkmin(d[tx][ty],d[t.fi][t.se]+a[t.fi]-a[t.fi-1])) q.push(node(-d[tx][ty],id(tx,ty)));
			}
			if(t.se==a[t.fi]-a[t.fi-1]){
				ty=g;
				if(chkmin(d[tx][ty],d[t.fi][t.se]+a[t.fi]-a[t.fi-1]+r)) q.push(node(-d[tx][ty],id(tx,ty)));
			}
		}
		if(t.fi<m){
			int tx=t.fi+1,ty=t.se-a[t.fi+1]+a[t.fi];
			if(ty>0){
				if(chkmin(d[tx][ty],d[t.fi][t.se]+a[t.fi+1]-a[t.fi])) q.push(node(-d[tx][ty],id(tx,ty)));
			}
			if(t.se==a[t.fi+1]-a[t.fi]){
				ty=g;
				if(chkmin(d[tx][ty],d[t.fi][t.se]+a[t.fi+1]-a[t.fi]+r)) q.push(node(-d[tx][ty],id(tx,ty)));
			}
		}
	}
	printf("-1\n");
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++) a[i]=readint();
	sort(a+1,a+m+1);
	g=readint(); r=readint();
	dij();
	return 0;
}