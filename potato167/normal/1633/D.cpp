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

int M=1010;
vector<int> table(M,M);

void solve();
//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int v=0;
	table[1]=0;
	for(int i=1;i<M;i++){
		for(int j=1;j<=i;j++){
			int x=i+i/j;
			if(x<M) chmin(table[x],table[i]+1);
		}
		chmax(v,table[i]);
	}
	//cout<<v<<"\n";
	int t=1;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n,k;
	cin>>n>>k;
	int L=n*14;
	vector<int> dp(L,0);
	vector<int> b(n),c(n);
	rep(i,n) cin>>b[i];
	rep(i,n) cin>>c[i];
	rep(i,n){
		for(int j=L-1;j>=table[b[i]];j--){
			chmax(dp[j],dp[j-table[b[i]]]+c[i]);
		}
	}
	cout<<dp[min(L-1,k)]<<"\n";
}