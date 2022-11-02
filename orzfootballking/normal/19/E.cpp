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
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int t;
int a[10005],b[10005],lst[20005],id[10005][2];
V<int> p;
struct dsu{
	int s[20005];
	void init(int len){
		FOR(i,1,len)s[i]=i;
	}
	int get(int x){
		p.PB(x);
		if(s[x]==x)RE x;
		else RE s[x]=get(s[x]);
	}
	void update(int x,int y){
		x=get(x);
		y=get(y);
		if(x!=y){
			p.PB(x);
			s[x]=y;
		}
	}
}s;
V<int> ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	if(!m){
		cout<<"0\n";RE 0;
	}
	FOR(i,1,m){
		cin>>a[i]>>b[i];
	}
	int S=sqrt(m);
	int cnt=0;
	FOR(i,1,n){
		FOR(j,0,1)id[i][j]=++cnt;
	}
	for(int t=1;t<=m;t+=S){
		int l=t,r=min(m,t+S-1);
		s.init(cnt);
		rep(i,1,l){
			s.update(id[a[i]][1],id[b[i]][0]);
			s.update(id[b[i]][1],id[a[i]][0]);
		}
		FOR(i,r+1,m){
			s.update(id[a[i]][1],id[b[i]][0]);
			s.update(id[b[i]][1],id[a[i]][0]);
		}
		bool f=1;
		FOR(i,1,n){
			if(s.get(id[i][0])==s.get(id[i][1])){
				f=0;break;
			}
		}
		if(!f)continue;
		FOR(i,1,cnt)lst[i]=s.s[i];
		FOR(i,l,r){
			p.clear();
			V<int> tv;
			rep(j,l,i){
				s.update(id[a[j]][1],id[b[j]][0]);tv.PB(a[j]);
				s.update(id[b[j]][1],id[a[j]][0]);tv.PB(b[j]);
			}
			FOR(j,i+1,r){
				s.update(id[a[j]][1],id[b[j]][0]);tv.PB(a[j]);
				s.update(id[b[j]][1],id[a[j]][0]);tv.PB(b[j]);
			}
			f=1;
			for(auto u:tv){
				if(s.get(id[u][0])==s.get(id[u][1])){
					f=0;break;
				}
			}
			if(f)ans.PB(i);
			for(auto u:p)s.s[u]=lst[u];
		}
	}
	cout<<ans.size()<<'\n';
	for(auto u:ans)cout<<u<<' ';
	RE 0;
}