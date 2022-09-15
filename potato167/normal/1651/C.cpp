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
const ll mod=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
#define all(p) p.begin(),p.end()
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}

ll f(vector<ll> p,ll a){
	So(p);
	p.push_back(ILL);
	int b=UB(p,a);
	if(b==0) return p[b]-a;
	return min(p[b]-a,a-p[b-1]);
}

void solve();
// oddloop
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	vector<ll> p(n),q(n);
	rep(i,n) cin>>p[i];
	rep(i,n) cin>>q[i];
	ll A=f(p,q[0]);
	ll B=f(p,q[n-1]);
	ll C=f(q,p[0]);
	ll D=f(q,p[n-1]);
	ll E=min(abs(p[0]-q[0]),A+C);
	ll F=min(abs(p[n-1]-q[n-1]),B+D);
	ll G=min(abs(p[0]-q[n-1]),C+B);
	ll H=min(abs(q[0]-p[n-1]),A+D);
	cout<<min(E+F,G+H)<<"\n";
}