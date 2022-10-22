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
int p[300005],iter[300005],a[300005],b[300005];
void solve(){
	int n,m;
	V<int> pos;
	cin>>n>>m;
	FOR(i,0,n){
		p[i]=0;
	}
	FOR(i,1,n){
		int x;
		cin>>x;b[i]=x;
		int now=x-i;
		if(now<0)now+=n;
		p[now]++;
	}
	rep(i,0,n){
		if(m*2+p[i]>=n){
			pos.PB(i);
		}
	}
	V<int> ans;
	for(auto u:pos){
		FOR(i,1,n){
			a[i]=b[i];
			iter[a[i]]=i;
		}
		int cnt=0;
//		cout<<u<<'\n';
		FOR(i,1,n){
			int now=i+u;
			if(now>n)now-=n;
//			cout<<now<<' '<<a[i]<<' ';
			if(a[i]!=now){
				cnt++;
				int ta=a[i];
				swap(a[i],a[iter[now]]);
				swap(iter[ta],iter[now]);
			}
		}
//		cout<<'\n';
		if(cnt<=m)ans.PB((n-u)%n);
	}
	sort(ALL(ans));
	cout<<ans.size()<<' ';
	for(auto u:ans)cout<<u<<' ';cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}