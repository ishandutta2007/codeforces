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
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int n,m,a[1000005],ans[1000005];
V<int> v[1000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int s=0;
	set<P<int,int> > st;
	FOR(i,1,m)cin>>a[i],s+=a[i],st.emplace(MP(a[i],i));
	int t=(s+n-1)/n;cout<<t<<'\n';
	int tt=t;
	int pos=1;
	V<int> num;
	while(!st.empty()){
		while(!st.empty()&&!(*st.begin()).F)st.erase(st.begin());
		if(st.empty())break;
		while(1){
			auto it=st.lwb(MP(n,0));
			if(it==st.end())break;
			P<int,int> now=*it;st.erase(it);
//			cout<<now.F<<' '<<now.S<<' ';
			while(now.F>=n){
				now.F-=n;
				t--;s-=n;
				FOR(i,pos,m)v[i].PB(now.S);
			}
//			cout<<now.F<<"\n";
			if(now.F)st.emplace(now);
		}
//		cout<<"ok"<<'\n';
		if(st.empty())break;
		int val=(*st.begin()).F,cnt=t;
		num.PB(val);n-=val;
		s-=t*val;
		V<P<int,int> > ad;
		while(!st.empty()){
			P<int,int> now=*st.begin();st.erase(st.begin());
			int t=now.F/val;
			if(t>=cnt){
				t=cnt;
				now.F-=t*val;
				FOR(i,1,t)v[pos].PB(now.S);
				if(now.F)st.emplace(now);break;
			}else{
				now.F%=val;
				if(now.F)ad.PB(now);
				now.F-=t*val;
				FOR(i,1,t)v[pos].PB(now.S);
				cnt-=t;
			}
		}
		for(auto u:ad)st.emplace(u);
		pos++;
//		cout<<st.size()<<'\n';RE 0;
	}
	if(n){
		if(sz(num)==m)num[m-1]+=n;
		else num.PB(n);
	}
	for(auto u:num)cout<<u<<' ';
	FOR(i,1,m-sz(num))cout<<0<<' ';
	cout<<'\n';
	FOR(i,1,tt){
		FOR(j,1,m){
			if(sz(v[j])<i)cout<<1<<' ';
			else cout<<v[j][i-1]<<' ';
		}
		cout<<'\n';
	}
	RE 0;
}