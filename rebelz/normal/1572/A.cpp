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

int n;
int d[200005],du[200005],q[200005];
vector<int> adj[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) adj[i].clear(),du[i]=0;
		int x;
		for(int i=1;i<=n;i++){
			du[i]=x=readint();
			while(x--) adj[readint()].pb(i);
		}
		int front=0,rear=0;
		for(int i=1;i<=n;i++) d[i]=0;
		for(int i=1;i<=n;i++) if(!du[i]) q[rear++]=i,d[i]=1;
		while(front<rear){
			int t=q[front++];
			for(auto v:adj[t]){
				if(v<t) chkmax(d[v],d[t]+1);
				else chkmax(d[v],d[t]);
				if(!(--du[v])) q[rear++]=v;
			}
		}
		if(rear!=n) printf("-1\n");
		else{
			int ans=0;
			for(int i=1;i<=n;i++) chkmax(ans,d[i]);
			printf("%d\n",ans);
		}
	}
	return 0;
}