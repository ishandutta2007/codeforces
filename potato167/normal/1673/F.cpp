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
	int N=32;
	vector<vector<int>> p(N,vector<int>(N));
	vector<int> r;
	int v=1;
	rep(i,5){
		vector<int> q;
		for(auto x:r) q.push_back(x);
		q.push_back(v);
		v*=4;
		for(auto x:r) q.push_back(x);
		swap(q,r);
	}
	vector<int> ans(N*N,-1);
	rep(i,N) rep(j,N){
		if(i!=0){
			p[i][j]=(p[i-1][j]^r[i-1]);
		}else if(j!=0){
			p[i][j]=(p[i][j-1]^(r[j-1]*2));
		}
		assert(ans[p[i][j]]==-1);
		ans[p[i][j]]=(i*N+j);
		assert(p[i][j]<N*N);
	}
	int M,K;
	cin>>M>>K;
	rep(i,M){
		rep(j,M-1){
			if(j) cout<<" ";
			cout<<r[j]*2;
		}
		cout<<endl;
	}
	rep(i,M-1){
		rep(j,M){
			if(j) cout<<" ";
			cout<<r[i];
		}
		cout<<endl;
	}
	int front=0;
	rep(i,K){
		int a;
		cin>>a;
		front^=a;
		cout<<ans[front]/N+1<<" "<<ans[front]%N+1<<endl;
	}
}