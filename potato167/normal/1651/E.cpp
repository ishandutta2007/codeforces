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
	ll n;
	cin>>n;
	vector<vector<int>> G(n*2);
	rep(i,n*2){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> seen(2*n);
	ll ans=0;
	rep(i,n*2){
		if(seen[i]) continue;
		vector<ll> p={i};
		int ind=i;
		int L=0;
		while(true){
			seen[ind]=1;
			for(auto x:G[ind]){
				if(seen[x]==0){
					ind=x;
					p.push_back(ind);
					break;
				}
			}
			L++;
			if(L==(int)(p.size())){
				break;
			}
		}
		rep(j,L+5) p.push_back(p[j]);
		rep(j,L){
			ll A=p[j],B=p[j],C=p[j+1],D=p[j+1];
			rep(k,L/2){
				ll E=p[j+2+k*2];
				if(k==L/2-1){
					if(j==0){
						ans+=(ll)(L/2)*(1+A%n)*(n-B%n)*(1+C%n)*(n-D%n);
					}
					break;
				}
				ll tmp=(1+C%n)*(n-D%n);
				if(E<A){
					ans+=(A-E)*(n-B%n)*tmp;
				}else if(B<E){
					ans+=(1+A%n)*(E-B)*tmp;
				}
				chmin(A,p[j+2+k*2]);
				chmax(B,p[j+2+k*2]);
				chmin(C,p[j+3+k*2]);
				chmax(D,p[j+3+k*2]);
			}
		}
	}
	cout<<ans<<"\n";
}