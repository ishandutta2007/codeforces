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
#define lc (x<<1)
#define rc ((x<<1)^1)
using namespace std;
int a[500005];
set<P<int,int> > s;
int n,m;
V<P<int,int> > v[500005];
int ans[500005];
V<int> num[500005];
P<int,int> hav[1<<20];
P<int,int> lst[500005];
int pos[500005];
set<P<int,int> > nu[1<<20];
void up(int x){
	if(!hav[lc].S)hav[x]=hav[rc];
	else if(!hav[rc].S){
		hav[x]=hav[lc];
	}else{
		hav[x]=min(hav[lc],hav[rc]);
	}
}
void update(int x,int l,int r,int it,int to,int now){
	if(l==r){
		nu[x].emplace(MP(to,now));
		hav[x]=*nu[x].begin();
		RE;
	}
	int mid=(l+r)>>1;
	if(mid>=it){
		update(lc,l,mid,it,to,now);
	}else update(rc,mid+1,r,it,to,now);
	up(x);
}
void erase(int x,int l,int r,int it,P<int,int> to){
	if(l==r){
		nu[x].erase(to);
		if(nu[x].empty()){
			hav[x]=MP(0,0);
		}
		else hav[x]=*nu[x].begin();
		RE;
	}
	int mid=(l+r)>>1;
	if(mid>=it){
		erase(lc,l,mid,it,to);
	}else erase(rc,mid+1,r,it,to);
	up(x);
}
P<int,int> merge(P<int,int> x,P<int,int> y){
	if(!x.S)RE y;
	else if(!y.S)RE x;
	else RE min(x,y);
}
P<int,int> get(int x,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr){
		RE hav[x];
	} 
	if(l>tr||tl>r){
		RE MP(0,0);
	}
	int mid=(l+r)>>1;
	RE merge(get(lc,l,mid,tl,tr),get(rc,mid+1,r,tl,tr));
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n){
		cin>>a[i];
	}
	cin>>m;
	FOR(i,1,m){
		int l,r;
		cin>>l>>r;
		v[r].PB(MP(l,i));
	}
	FOR(i,1,n){
		if(num[a[i]].size()>=1){
			erase(1,1,n,pos[a[i]],lst[a[i]]);
			s.erase(lst[a[i]]);
			lst[a[i]]=MP(num[a[i]].back()+1,a[i]);
			update(1,1,n,i,num[a[i]].back()+1,a[i]);
			s.emplace(MP(num[a[i]].back()+1,a[i]));
		}else {
			lst[a[i]]=MP(1,a[i]);
			update(1,1,n,i,1,a[i]);s.emplace(MP(1,a[i]));
		}
		pos[a[i]]=i;
		num[a[i]].PB(i);
		for(auto u:v[i]){
			P<int,int> now=get(1,1,n,u.F,i);
			if(now.F<=u.F){
				ans[u.S]=now.S;
			}
		}
	}
	FOR(i,1,m)cout<<ans[i]<<'\n';
	RE 0;
}