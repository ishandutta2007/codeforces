#include<bits/stdc++.h>
#define int long long
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
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
P<int,int> ans[1005];
const int INF=1e18;
int n,T;
mt19937_64 rnd(time(0));
int lst[1005];
int ask(int x,int y){
//	RE y;
	cout<<"? "<<x<<' '<<y<<'\n';
	fflush(stdout);
	int re;cin>>re;
	RE re;
}
int get(int x,int y){
//	RE y;
	int l=0,r=INF,mid;
	while(r>=l){
		mid=(l+r)>>1;
		int t=ask(x,mid);
		if(t==y)RE mid;
		if(t<y)l=mid+1;else r=mid-1;
	}
	RE -1;
}
void solve(V<int> node,int l,int r,int tl,int tr){
//	cout<<l<<' '<<r<<'\n';
	int cnt=node.size();
	if(cnt==1){
		ans[node[0]]=MP(l,r);RE ;
	}
	int mid=(cnt+1)/2;
	int midval=tl+mid*(T/n);
	V<int> posi=node;
	while(1){
		int now=rnd()%posi.size();
		now=posi[now];
		int it=get(now,midval);
		int cnt1=0,cnt2=0;
		for(auto u:node){
			int t=ask(u,it);lst[u]=t;
			if(t>midval)cnt1++;
			if(t>=midval)cnt2++;
		}
//		cout<<midval<<' '<<it<<' '<<mid<<' '<<cnt1<<' '<<cnt2<<'\n';RE ;
		if(cnt1<=mid&&cnt2>=mid){
			V<int> vl,vr;
			int cc=mid-cnt1;
			for(auto u:node){
				if(lst[u]>midval)vl.PB(u);
				else if(lst[u]<midval)vr.PB(u);
				else{
					if(cc)vl.PB(u),cc--;else vr.PB(u);
				}
			}
			solve(vl,l,it,tl,midval);solve(vr,it,r,midval,tr);
			RE;
		}
		V<int> to;
		if(cnt2<mid){
			for(auto u:posi)if(lst[u]<midval)to.PB(u);
		}else{
			for(auto u:posi)if(lst[u]>midval)to.PB(u);
		}
		posi=to;
	}
}
signed main(){
	cin>>n>>T;
	V<int> node;
	FOR(i,1,n)node.PB(i);
	solve(node,0,INF,0,T);
	cout<<"!\n";
	FOR(i,1,n)cout<<ans[i].F<<' '<<ans[i].S<<'\n';
	fflush(stdout);
	RE 0;
}