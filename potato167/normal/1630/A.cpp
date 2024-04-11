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
	int n,k;
	cin>>n>>k;
	if(k==n-1){
		if(n==4){
			cout<<"-1\n";
			return ;
		}
		vector<bool> p(n);
		int a=1,c=0;
		while(a!=n) a*=2,c++;
		rep(i,c){
			cout<<(1<<i)<<" "<<n-1-(1<<((i+1)%c))<<"\n";
			p[(1<<i)]=1;
			p[n-1-(1<<((i+1)%c))]=1;
		}
		rep(i,n){
			if(p[i]) continue;
			cout<<i<<" "<<((n-1)^i)<<"\n";
			p[(n-1)^i]=1;
		}
		return ;
	}

	k^=(n-1);
	cout<<"0 "<<k<<"\n";
	rep(i,n/2-1){
		int a=i+1,b=n-a-1;
		if(a==k) cout<<n-1<<" ";
		else cout<<a<<" ";
		if(b==k) cout<<n-1<<"\n";
		else cout<<b<<"\n";
	}
	return ;
}