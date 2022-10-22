#pragma GCC optimize(2)
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
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int fa[150005],iter[1000005],a[150005];
bool pri[1000005];
int get(int x){
	RE (x==fa[x])?x:(fa[x]=get(fa[x]));
}
void merge(int x,int y){
	x=get(x);y=get(y);
	fa[x]=y;
}
map<int,int> to[150005];
int num[1000005];
V<int> v[1000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,q;
	cin>>n>>q;
	FOR(i,1,n){
		cin>>a[i];
		iter[a[i]]=i;
		fa[i]=i;
	}
	m=1e6+1;
	for(int i=2;i<=m;i++){
		if(!pri[i]){
			int lst=0;
			for(int j=i;j<=m;j+=i){
				pri[j]=1;
				if(iter[j]){
					if(lst)merge(lst,iter[j]);
					lst=iter[j];
				}
				v[j].PB(i);
			}
			num[i]=lst;
		}
	}
	FOR(i,1,n)get(i);
	FOR(i,1,n){
		int t=a[i]+1;
		for(auto u:v[t]){
			if(num[u]){
				to[fa[i]][fa[num[u]]]=1;
				for(auto tu:v[t])if(num[tu]){
					to[fa[num[u]]][fa[num[tu]]]=1;
				}
			}
		}
	}
	FOR(i,1,q){
		int x,y;
		cin>>x>>y;
		if(fa[x]==fa[y]){
			cout<<0;
		}else if(to[fa[x]].count(fa[y])||to[fa[y]].count(fa[x])){
			cout<<1;
		}else cout<<2;
		cout<<'\n';
	}
	RE 0;
}