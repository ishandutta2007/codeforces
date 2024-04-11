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
	int n,m;
	cin>>n>>m;
	vector<vector<int>> p(n,vector<int>(m));
	rep(i,n) rep(j,m){
		cin>>p[i][j];
	}
	auto q=p;
	rep(i,n) So(q[i]);
	vector<int> seen(m,1);
	int X=0;
	rep(i,n) rep(j,m){
		if(p[i][j]!=q[i][j]){
			X+=seen[j];
			seen[j]=0;
		}
	}
	if(X>2){
		cout<<"-1\n";
		return ;
	}
	if(X==2){
		vector<int> ind;
		rep(i,m) if(seen[i]==0) ind.push_back(i);
		rep(i,n){
			swap(p[i][ind[0]],p[i][ind[1]]);
		}
		if(p==q) cout<<ind[0]+1<<" "<<ind[1]+1<<"\n";
		else cout<<"-1\n";
	}
	else if(X==1){
		int ind;
		rep(j,m) if(seen[j]==0) ind=j;
		rep(j,m){
			if(j==ind) continue;
			int J=0;
			rep(i,n){
				if(p[i][ind]==q[i][j]&&p[i][j]==q[i][ind]) J++;
			}
			if(J==n){
				cout<<j+1<<" "<<ind+1<<"\n";
				return ;
			}
		}
		cout<<"-1\n";
	}
	else cout<<"1 1\n";
}