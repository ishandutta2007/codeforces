#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
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
using namespace __gnu_pbds;
int n,q;
int p[200005],it[200005];
int l[200005],r[200005];
V<int> fac[200005];
V<P<int,int> > now;
V<P<int,int> > v[200005];
int ans[1000005];
struct Bit{
	int s[200005];
	void update(int x,int val){
		while(x<=n){
			s[x]+=val;
			x+=x&-x;
		}
	}
	int get(int x){
		int re=0;
		while(x){
			re+=s[x];
			x-=x&-x;
		}
		RE re;
	}
	void update(int l,int r,int val){
		update(l,val);
		update(r+1,-val);
	}
	int get(int l,int r,int val){
		RE get(r)-get(l-1);
	}
}T1,T2,T3,T4;
V<P<int,int> > v1[200005],v2[200005],v3[200005],v4[200005];
void update1(int to,int p1,int p2){
	v1[to].PB(MP(p1,p2)); 
}
void update2(int to,int p1,int p2){
	v2[to].PB(MP(p1,p2)); 
}
void update3(int to,int p1,int p2){
	v3[to].PB(MP(p1,p2)); 
}
void update4(int to,int p1,int p2){
	v4[to].PB(MP(p1,p2)); 
}
void solve(int l1,int r1,int l2,int r2){
//	cout<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<'\n';
	update1(l1,r2+1,(r1-l1+1)*(r2));
	update1(l1,l2,(r1-l1+1)*(-l2+1));
	update2(l1,l2,(r1-l1+1));
	update2(l1,r2+1,-(r1-l1+1));
	
	update1(r1,r2+1,(r2-l2+1)*(r1+1));
	update3(r1,r2+1,-(r2-l2+1));
	update1(l1,r2+1,-(r2-l2+1)*(r1+1));
	update3(l1,r2+1,(r2-l2+1));
	
	update4(r1,l2,-1);
	update2(r1,l2,(r1+1));
	update3(r1,l2,l2-1);
	update1(r1,l2,-(r1+1)*(l2-1));
	update4(r1,r2+1,1);
	update2(r1,r2+1,-(r1+1));
	update3(r1,r2+1,-l2+1);
	update1(r1,r2+1,(r1+1)*(l2-1));
	
	update4(l1,l2,1);
	update2(l1,l2,-(r1+1));
	update3(l1,l2,-l2+1);
	update1(l1,l2,(r1+1)*(l2-1));
	update4(l1,r2+1,-1);
	update2(l1,r2+1,(r1+1));
	update3(l1,r2+1,l2-1);
	update1(l1,r2+1,-(r1+1)*(l2-1));
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	FOR(i,1,n)cin>>p[i],it[p[i]]=i;
	stack<int> s;
	FOR(i,1,n){
		while(!s.empty()&&p[s.top()]<p[i])s.pop();
		if(!s.empty())l[p[i]]=s.top()+1;else l[p[i]]=1;
		s.emplace(i);
	}
	while(!s.empty())s.pop();
	for(int i=n;i>=1;i--){
		while(!s.empty()&&p[s.top()]<p[i])s.pop();
		if(!s.empty())r[p[i]]=s.top()-1;else r[p[i]]=n;
		s.emplace(i);
	}
//	FOR(i,1,n)cout<<l[i]<<' '<<r[i]<<'\n';
	FOR(i,1,n)for(int j=i*i;j<=n;j+=i)fac[j].PB(i);
	FOR(i,1,n){
		now.clear();
		for(auto u:fac[i])if(u*u<i){
			int t=i/u;
			if(min(it[u],it[t])<l[i]||max(it[u],it[t])>r[i])continue;
			if((it[u]>=l[i]&&it[u]<=it[i])&&(it[t]>=it[i]&&it[t]<=r[i])){
				now.PB(MP(it[u],it[t]));continue;
			}
			swap(t,u);
			if((it[u]>=l[i]&&it[u]<=it[i])&&(it[t]>=it[i]&&it[t]<=r[i])){
				now.PB(MP(it[u],it[t]));continue;
			}
			if(it[u]<=it[i]&&it[t]<=it[i]){
				now.PB(MP(min(it[u],it[t]),it[i]));
			}else if(it[u]>=it[i]&&it[t]>=it[i]){
				now.PB(MP(it[i],max(it[u],it[t])));
			}
		}
		sort(ALL(now));
		reverse(ALL(now));
		int mi=r[i]+1;
//		cout<<i<<'\n';
		for(auto u:now){
//			cout<<u.F<<' '<<u.S<<'\n';
			if(mi<u.S)continue;
			solve(l[i],u.F,u.S,mi-1);
			gmin(mi,u.S);
		}
	}
	FOR(i,1,q){
		int l,r;
		cin>>l>>r;
		v[l].PB(MP(r,i));
	}
	for(int i=n;i>=1;i--){
		for(auto u:v1[i])T1.update(u.F,u.S);
		for(auto u:v2[i])T2.update(u.F,u.S);
		for(auto u:v3[i])T3.update(u.F,u.S);
		for(auto u:v4[i])T4.update(u.F,u.S);
		for(auto u:v[i]){
			ans[u.S]=T1.get(u.F)+T2.get(u.F)*u.F+T3.get(u.F)*i+T4.get(u.F)*i*u.F;
		}
	}
	FOR(i,1,q)cout<<ans[i]<<'\n';
	RE 0;
}