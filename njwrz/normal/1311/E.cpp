#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
struct node{
	int x,y,z;
};
int size[5005][5005],de[5005][5005],fa[5005];
node nod(int x1,int y1,int z1){
	node re;
	re.x=x1;re.y=y1;re.z=z1;
	RE re;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	V<node> now;
	now.PB(nod(1,0,1));
	FOR(i,0,5000)FOR(j,0,5000)de[i][j]=-1;
	size[1][0]=1;de[1][0]=0;
	int maxi;
	FOR(t,1,100){
		V<node> nxt;
		for(auto &u:now){
			maxi=u.z<<1;
			for(int i=1;i<=maxi&&u.x+i<=5000&&u.y+t*i<=5000;i++){
				if(de[u.x+i][u.y+t*i]==-1){
					de[u.x+i][u.y+t*i]=t;
					size[u.x+i][u.y+t*i]=i;
					nxt.PB(nod(u.x+i,u.y+t*i,i));
				}
			}
		}
		now=nxt;
	}
	int t,n,d,nxn,nxd,cnt,len,tn;
	cin>>t;
	while(t--){
		cin>>n>>d;tn=n;
		if(de[n][d]==-1){
			cout<<"NO\n";continue;
		}
		V<int> g[5005];
		len=de[n][d];
		for(int i=de[n][d];i>=0;i--){
			g[i].resize(size[n][d],0);
			nxn=n-size[n][d];
			nxd=d-i*size[n][d];
			n=nxn;d=nxd;
		}
		cnt=0;
		FOR(i,0,len)rep(j,0,g[i].size())g[i][j]=++cnt;
		FOR(i,1,len)rep(j,0,g[i].size())fa[g[i][j]]=g[i-1][j/2];
		cout<<"YES\n";
		FOR(i,2,tn)cout<<fa[i]<<' ';
		cout<<'\n';
	}
	RE 0;
}