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
	ll n;
	cin>>n;
	vector<int> p(n),q(n),m(n);
	vector<int> A(n);
	map<int,vector<int>> M;
	rep(i,n){
		cin>>p[i]>>q[i]>>m[i];
		M[p[i]+q[i]-m[i]].push_back(i);
	}
	int ans=0;
	for(auto v:M){
		vector<tuple<int,int,int>> ran(v.second.size());
		rep(i,v.second.size()){
			int a=v.second[i];
			ran[i]={min(p[a],v.first),max(0,p[a]-m[a]),a};
		}
		So(ran);
		int tmp=-1;
		rep(i,v.second.size()){
			if(tmp<(get<1>(ran[i]))){
				tmp=get<0>(ran[i]);
				ans++;
			}
			A[get<2>(ran[i])]=tmp;
		}
	}
	cout<<ans<<"\n";
	rep(i,n) cout<<p[i]-A[i]<<" "<<m[i]-p[i]+A[i]<<"\n";
}