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
#define all(p) p.begin(),p.end()
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

//
long long Lcm(long long a,long long b){
	return (a/Gcd(a,b))*b;
}
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
	ll n,m;
	cin>>n>>m;
	vector<ll> X(n+1,-1),Y(n+1,-1);
	int L=20;
	vector<ll> base(L+1);
	for(int i=1;i<=L;i++){
		rep(j,(1<<(i))){
			if(j==0) continue;
			ll c=-1;
			ll B=1;
			ll D=-1;
			rep(k,i){
				if(j&(1<<k)){
					c*=-1;
					B=Lcm(B,k+1);
					if(D==-1) D=k+1;
				}
				if(B>m*i){
					B=mod;
					break;
				}
			}
			base[i]+=c*((m*D)/B);
		}
	}
	ll ans=1;
	rep(i,n+1){
		if(i<2) continue;
		if(X[i]==-1){
			ll D=i*i;
			ll C=2;
			while(D<=n){
				if(X[D]==-1){
					X[D]=i;
					Y[D]=C;
				}
				C++;
				D*=i;
			}
			ans+=base[C-1];
		}
	}
	cout<<ans<<"\n";
}