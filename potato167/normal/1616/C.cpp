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

int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

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
	int n;
	cin>>n;
	vector<int> p(n);
	rep(i,n) cin>>p[i];
	int ans=1;
	rep(i,n) rep(j,i){
		int X=gcd((int)(i-j),abs(p[i]-p[j]));
		int V=(i-j)/X;
		int diff=(p[i]-p[j])/X;//p[ind]==p[i]+diff*(ind-i)/X
		int tmp=0;
		rep(k,n){
			if(abs(i-k)%V!=0) continue;
			if(p[k]==p[i]+(diff*(k-i))/V) tmp++;
		}
		chmax(ans,tmp);
	}
	cout<<n-ans<<"\n";
}