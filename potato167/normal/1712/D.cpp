#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}



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
	int n,k;
	cin>>n>>k;
	assert(k!=0);
	vector<int> p(n);
	rep(i,n) cin>>p[i];
	int L=1e9;/*
	if(n==k){
		cout<<L<<"\n";
		return ;
	}
	if(n==2){
		cout<<max(p[0],p[1])<<"\n";
		return ;
	}*/
	int l=0,r=L+1;
	while(r-l>1){
		int med=(r+l)/2;
		auto seen=p;
		int use=0;
		rep(i,n){
			if(p[i]*2<med){
				seen[i]=L;
				use++;
			}
		}
		int a=2;
		rep(i,n-1){
			if(max(seen[i],seen[i+1])>=med){
				a=1;
				if(min(seen[i],seen[i+1])>=med){
					a=0;
					break;
				}
			}
		}
		use+=a;
		if(use<=k) l=med;
		else r=med;
	}
	cout<<l<<"\n";
	
}