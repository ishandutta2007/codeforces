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
ll mod=998244353;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

ll fact(int a){
	ll ans=1;
	rep(i,a){
		ans*=(i+1);
		ans%=mod;
	}
	return ans;
}

ll my_pow(ll a,ll b){
	if(b==0) return 1;
	if(b%2==0) return my_pow((a*a)%mod,b/2);
	return (a*my_pow(a,b-1))%mod;
}

void solve(){
	int n;
	cin>>n;
	vector<int> p(n);
	rep(i,n){
		cin>>p[i];
	}
	So(p);
	if(p[n-1]==p[n-2]){
		cout<<fact(n)<<"\n";
		return;
	}
	if(p[n-1]-1>p[n-2]){
		cout<<"0\n";
		return ;
	}
	int x=1;
	while(x!=n&&p[n-1-x]==p[n-1]-1) x++;
	ll ans=(fact(n)*(x-1))%mod;
	cout<<(ans*my_pow(x,mod-2))%mod<<"\n";
}



//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	rep(i,t) solve();
}