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
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}

void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	vector<ll> p(n);
	rep(i,n) cin>>p[i];
	map<ll,ll> m;
	m[ILL]=-1;
	ll ans=0;
	ll tmp=0;
	rep(i,n){
		if(i%2){
			//if(m.count(tmp-p[i])) ans+=m[tmp-p[i]];
			/*while((*m.begin()).first<tmp-p[i]){
				m.erase((*m.begin()).first);
			}*/
			while((*m.upper_bound(tmp)).first!=ILL){
				m.erase(((*m.upper_bound(tmp)).first));
			}
		}else{
			//if(m.count(tmp+p[i])) ans+=m[tmp+p[i]];
			while((*m.begin()).first<tmp){
				m.erase((*m.begin()).first);
			}
			/*while((*m.upper_bound(tmp+p[i])).first!=ILL){
				m.erase(((*m.upper_bound(tmp+p[i])).first));
			}*/
		}
		m[tmp]++;
		if(i%2) tmp-=p[i];
		else tmp+=p[i];
		if(m.count(tmp)) ans+=m[tmp];
	}
	cout<<ans<<"\n";
}