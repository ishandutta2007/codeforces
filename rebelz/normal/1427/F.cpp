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
	int x,y,z;
	node(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
}a[405];

int n,m,top;
int du[405];
bool vis[1205];
pii s[405];
vector<int> now[405],adj[405];

int main(){
	n=readint();
	for(int i=1;i<=3*n;i++) vis[readint()]=1;
	for(int i=1;i<=6*n;i++){
		if(i<=6*n-2&&vis[i]==vis[i+1]&&vis[i]==vis[i+2]){
			a[++m]=node(i,i+1,i+2);
			now[top].pb(m);
			i+=2;
		}
		else{
			if(!top||vis[s[top].fi]!=vis[i]) s[++top]=mp(i,0);
			else{
				pii tmp=s[top];
				if(tmp.se){
					a[++m]=node(tmp.fi,tmp.se,i);
					for(auto r:now[top]) adj[r].pb(m),du[m]++;
					now[top].clear();
					top--;
					now[top].pb(m);
				}
				else s[top].se=i;
			}
		}
	}
	int opt=0;
	for(auto r:now[0]) if(!vis[a[r].x]) opt=r;
	for(int i=1;i<=2*n;i++){
		for(int j=1;j<=m;j++){
			if(du[j]) continue;
			if(vis[a[j].x]!=(i&1)) continue;
			if(j==opt&&i<2*n) continue;
			printf("%d %d %d\n",a[j].x,a[j].y,a[j].z);
			for(auto r:adj[j]) du[r]--;
			du[j]=-1;
			break;
		}
	}
	return 0;
}