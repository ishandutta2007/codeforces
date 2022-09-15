#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll I=1167167167167167167;
ll mod=1e9+7;
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

//
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T=1;
	rep(i,T) solve();
}

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> p(n*k);
	rep(i,n*k) cin>>p[i],p[i]--;
	vector<int> seen(n,-1);
	vector<int> ans1(n),ans2(n);
	int ok=0;
	while(ok!=n){
		rep(i,n*k){
			if(seen[p[i]]==-1) seen[p[i]]=i;
			else if(seen[p[i]]>=0){
				ans1[p[i]]=seen[p[i]];
				ans2[p[i]]=i;
				seen[p[i]]=-2;
				rep(j,n){
					chmin(seen[j],-1);
				}
				ok++;
			}
		}
		rep(j,n) chmin(seen[j],-1);
	}
	rep(i,n){
		cout<<ans1[i]+1<<" "<<ans2[i]+1<<"\n";
	}
}