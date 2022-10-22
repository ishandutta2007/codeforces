#include<bits/stdc++.h>
#define ll long long
#define lb long double
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
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
bitset<1005> a[1005],full,emp,tf;
int n,vis[1005];
V<int> v[1005],g[1005];
bool leaf[1005];
bool ed[1005][1005];
int hav[1005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	if(n==2){
		cout<<1<<' '<<2;RE 0;
	}
	FOR(i,1,n)full[i]=1;
	FOR(i,1,n){
		int len;
		cin>>len;
		FOR(j,1,len){
			int x;
			cin>>x;
			a[i][x]=1;
		}
	}
	bool f=1;
	FOR(i,1,n){
		if(a[i]!=full){
			f=0;break;
		}
	}
	if(f){
		FOR(i,2,n){
			cout<<1<<' '<<i<<'\n';
		}
		RE 0;
	}
	bitset<1005> now;
	FOR(i,1,n)FOR(j,i+1,n){
		if((a[i]&a[j]).count()==2){
			now=a[i]&a[j];
			int x=now._Find_first(),y=now._Find_next(x);
			vis[x]=vis[y]=1;
			if(ed[x][y])continue;
			ed[x][y]=ed[y][x]=1;
			g[x].PB(y);
			g[y].PB(x);
		}
	}
	int cnt=0;
	FOR(i,1,n)cnt+=vis[i];
	if(cnt==2){
		bitset<1005> now1=emp,now2=emp;
		int x=-1,y=-1;
		FOR(i,1,n)if(vis[i]){
			if(x==-1)x=i;else y=i;
		}
		FOR(i,1,n)if(a[i]!=full){
			if(a[i]!=now1&&a[i]!=now2){
				if(now1==emp){
					now1=a[i];
					FOR(j,1,n)if(a[i][j]&&!vis[j])v[x].PB(j),v[j].PB(x);
				}else {
					now2=a[i];
					FOR(j,1,n)if(a[i][j]&&!vis[j])v[y].PB(j),v[j].PB(y);
				}
			}
		}
	}else{
		FOR(i,1,n)leaf[i]=1;
		FOR(i,1,n)FOR(j,1,n)if((a[i]&a[j])==a[j])hav[j]++;
		FOR(i,1,n)leaf[i]=hav[i]==(int)a[i].count();
		FOR(i,1,n)if(vis[i])tf[i]=1;
		FOR(i,1,n)rep(j,1,i)if(leaf[i]&&leaf[j]&&a[i]==a[j])leaf[i]=0;
		FOR(i,1,n)if(vis[i]){
			now=emp;now[i]=1;
			for(auto u:g[i])now[u]=1;
			FOR(j,1,n)if(leaf[j]&&(a[j]&tf)==now){
				FOR(k,1,n)if(a[j][k]&&!vis[k])v[i].PB(k),v[k].PB(i);
				break;
			}
		}
	}
	FOR(i,1,n)for(auto u:g[i])v[i].PB(u);
	FOR(i,1,n){
		for(auto u:v[i])if(i<u){
			cout<<i<<' '<<u<<'\n';
		}
	}
	RE 0;
}