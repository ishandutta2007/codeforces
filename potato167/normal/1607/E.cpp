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
	
	int T;
	cin>>T;
	rep(i,T) solve();
}

void solve(){
	int n,m;
	cin>>n>>m;
	string S;
	cin>>S;
	int x=0,y=0;
	int max_x=0,min_x=0,max_y=0,min_y=0;
	int ans_x=1,ans_y=1;
	rep(i,S.size()){
		if(S[i]=='L') y--;
		else if(S[i]=='R') y++;
		else if(S[i]=='U') x--;
		else if(S[i]=='D') x++;
		chmax(max_x,x);
		chmin(min_x,x);
		chmax(max_y,y);
		chmin(min_y,y);
		if(n<=max_x-min_x||m<=max_y-min_y) break;
		else ans_x=1-min_x,ans_y=1-min_y;
	}
	cout<<ans_x<<" "<<ans_y<<"\n";
}