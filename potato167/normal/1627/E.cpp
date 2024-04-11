#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=1167167167167167167;
const int INF=2100000000;
const ll mod=998244353;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

int Gcd(int a,int b){
	if(b==0) return a;
	return Gcd(b,a%b);
}

void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<ll> x(n);
	rep(i,n) cin>>x[i];
	vector<int> a(k),b(k),c(k),d(k);
	vector<ll> h(k);
	set<pair<int,int>> s;
	s.insert({0,0});
	s.insert({n-1,m-1});
	rep(i,k){
		cin>>a[i]>>b[i]>>c[i]>>d[i]>>h[i];
		a[i]--,b[i]--,c[i]--,d[i]--;
		s.insert({a[i],b[i]});
		s.insert({c[i],d[i]});
	}
	vector<pair<int,int>> rev;
	map<pair<int,int>,int> order;
	int ind=0;
	for(auto z:s) order[z]=ind,rev.push_back(z),ind++;
	vector<vector<pair<int,ll>>> G(ind);
	rep(i,k){
		G[order[{a[i],b[i]}]].push_back({order[{c[i],d[i]}],-h[i]});
	}
	rep(i,ind-1){
		if(rev[i].first==rev[i+1].first){
			ll tmp=((ll)(rev[i+1].second-rev[i].second))*x[rev[i].first];
			G[i].push_back({i+1,tmp});
			G[i+1].push_back({i,tmp});
		}
	}
	vector<ll> dp(ind,ILL);
	_pq<tuple<int,ll,int>> pq;//{i,dist,v}
	pq.push({0,0,0});
	dp[0]=0;
	while(!pq.empty()){
		int i,v;
		ll dis;
		tie(i,dis,v)=pq.top();
		pq.pop();
		if(dp[v]<dis) continue;
		for(auto x:G[v]){
			ll t=dis+x.second;
			if(chmin(dp[x.first],t)){
				pq.push({rev[x.first].first,t,x.first});
			}
		}
	}
	if(dp[ind-1]==ILL){
		cout<<"NO ESCAPE\n";
	}
	else cout<<dp[ind-1]<<"\n";
}