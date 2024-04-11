#pragma GCC optimize(3)
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
const int maxn=1e5+5,N=(1<<18)-1;
struct segtree{
	#define lc (x<<1)
	#define rc ((x<<1)^1)
	int maxi[(N+10)<<1];
	void update(int x,int y){
		x+=N;maxi[x]=y;
		do{
			x>>=1;
			maxi[x]=max(maxi[lc],maxi[rc]);
		}while(x!=1);
	}
	int get(int x){
		x+=N;
		int re=maxi[x];
		do{
			if(!(x&1))gmax(re,maxi[x^1]);
			x>>=1;
		}while(x!=1);
		RE re;
	}
}thi,titer;
int iter[(maxn+10)<<1],a[maxn],n,m;
set<int> tree;
void solve1(int &now){
	int it,hi;
	cin>>it>>hi;tree.emplace(it);
	hi+=m-now;
	iter[hi]=it;
	a[it]=hi;
	int tl=max(hi-8,1);
	for(int i=hi;i>=tl;i--)if(iter[i]){
		titer.update(iter[i],0);
	}
	for(int i=hi;i>=tl;i--)if(iter[i]){
		int val=titer.get(iter[i]+1)+1;
//		cout<<i<<' '<<iter[i]<<' '<<val<<'\n';
		titer.update(iter[i],val);
		thi.update(i,val);
	}
//	cout<<'\n';
}
void solve2(){
	V<int> out;
	int cnt;
	cin>>cnt;
	rep(i,1,cnt){
		int now=*tree.begin();
		out.PB(now);
		tree.erase(now);
		thi.update(a[now],0);
	}
	int now=*tree.begin();
	tree.erase(now);thi.update(a[now],0);titer.update(now,0);
	iter[a[now]]=0;a[now]=0;
	while(!out.empty()){
		int now=out.back();out.pop_back();
		tree.emplace(now);
		int to=thi.get(a[now]+1)+1;
		thi.update(a[now],to);
		titer.update(now,to);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	rep(_,0,m){
		int tap;
		cin>>tap;
		if(tap&1){
			solve1(_);
		}else solve2();
		cout<<titer.maxi[1]<<'\n';
	}
	RE 0;
}