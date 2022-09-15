#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=2167167167167167167;
const int INF=2100000000;
const ll mod=998244353;
#define rep(i,a) for (ll i=0;i<a;i++)
#define all(p) p.begin(),p.end()
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}


void solve();
// oddloop
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	int N;
	cin>>N;
	string S;
	cin>>S;
	ll ans=1;
	vector<int> p((1<<N));
	map<ll,int> m;
	int ind=2;
	for(int i=(1<<N)-1;i>0;i--){
		if(i>=(1<<(N-1))){
			if(S[i-1]=='A') p[i]=0;
			else p[i]=1;
		}
		else{
			ll x=p[2*i],y=p[2*i+1];
			if(x>y) swap(x,y);
			if(x!=y) ans=(ans*2ll)%mod;
			ll val=x*mod*2ll+y*2ll;
			if(S[i-1]=='A') val++;
			if(!m.count(val)){
				m[val]=ind;
				ind++;
			}
			p[i]=m[val];
		}
	}
	cout<<ans<<"\n";
}