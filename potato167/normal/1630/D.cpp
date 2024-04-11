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
#define rep(i,a) for (int i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

//
long long Gcd(long long a,long long b){
	if(b==0) return a;
	else return Gcd(b,a%b);
}



void solve();

//  rainy ~  ~
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
	vector<ll> p(n),q(m);
	rep(i,n) cin>>p[i];
	rep(i,m) cin>>q[i];
	ll x=q[m-1];
	rep(i,m-1) x=Gcd(x,q[i]);
	ll A=0,B=0;
	rep(inter,x){
		ll C=0,D=-ILL;
		for(int j=inter;j<n;j+=x){
			ll E=max(C+p[j],D-p[j]);
			ll F=max(C-p[j],D+p[j]);
			C=E,D=F;
		}
		//cout<<C<<" "<<D<<"\n";
		A+=C,B+=D;
	}
	cout<<max(A,B)<<"\n";
}