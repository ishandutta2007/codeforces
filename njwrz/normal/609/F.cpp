#pragma GCC optimize("Ofast")
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
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
multiset<P<int,int> > s;
int n,m;
P<int,P<int,int> > p[500005];
int it[500005],tl[500005];
int maxi[500005],cnt[500005],po[500005],ad[500005],fr[500005];
void update(int x,int v){
	while(x<=n){
		gmax(maxi[x],v);
		x+=x&-x;
	}
}
int get(int x){
	int re=0;
	while(x){
		gmax(re,maxi[x]);
		x-=x&-x;
	}
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n){
		cin>>p[i].F>>p[i].S.F;p[i].S.S=i;
	}
	sort(p+1,p+n+1);
	FOR(i,1,n)tl[i]=p[i].F,it[p[i].S.S]=i;
	FOR(i,1,m){
		cin>>fr[i]>>ad[i];
	}
	FOR(i,1,n)update(i,p[i].F+p[i].S.F);
	FOR(i,1,m){
		s.insert(MP(fr[i],ad[i]));
		int t=upb(tl+1,tl+n+1,fr[i])-tl-1;
		if(!t)continue;
		int l,r,mid,ans=0;
		l=1;r=t;
		while(r>=l){
			mid=(l+r)>>1;
			if(get(mid)<fr[i]){
				l=mid+1;
			}else r=mid-1,ans=mid;
		}
		if(!ans)continue;
		int now=ans;
		auto iter=s.lwb(MP(p[now].F,0));
		while(iter!=s.end()&&(*iter).F<=p[now].F+p[now].S.F){
			p[now].S.F+=(*iter).S;cnt[now]++;
			s.erase(iter);
			iter=s.lwb(MP(p[now].F,0));
		} 
		update(now,p[now].F+p[now].S.F);
	}
//	FOR(i,1,n)cout<<it[i]<<' ';cout<<'\n';
	FOR(i,1,n)cout<<cnt[it[i]]<<' '<<p[it[i]].S.F<<'\n';
	RE 0;
}