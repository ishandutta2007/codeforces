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

ll f(ll a){
	ll l=-1,r=INF;
	while(r-l>1){
		ll med=(l+r)/2;
		if(a<=(med*(med-1))/2) r=med;
		else l=med;
	}
	return r;
}

ll g(ll a,ll len){
	ll x=(len*(len-1))/2-a;
	ll l=0,r=len/2;
	while(r-l>1){
		ll med=(r+l)/2;
		if(x<=med*(len-med)) r=med;
		else l=med;
	}
	return r;
}

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	ll n;
	cin>>n;
	ll base,tmp,med=0;
	cout<<"? 1 "<<n<<endl;
	cin>>base;
	ll l=1,r=n;
	while(true){
		med=(l+r)/2;
		cout<<"? 1 "<<med<<endl;
		cin>>tmp;
		if(tmp==base) r=med;
		else if(tmp==0) l=med;
		else break;
	}
	ll a,b,c;
	ll tmp2=0;
	cout<<"? 1 "<<med-1<<endl;
	cin>>tmp2;
	ll diff=tmp-tmp2;
	if((diff)*(diff+1)==tmp*2ll){
		a=med-diff;
		l=med;
		while(r-l>1){
			med=(l+r)/2;
			cout<<"? 1 "<<med<<endl;
			cin>>tmp;
			if(tmp==base) r=med;
			else l=med;
		}
		c=r;
		b=c-g(base,c-a+1)+1;
		cout<<"? 1 "<<b-1<<endl;
		cin>>tmp;
		if(tmp!=((b-a)*(b-a-1))/2){
			b=a+g(base,c-a+1);
		}
	}else{
		b=med-diff;
		ll tmp3=tmp-((diff)*(diff+1))/2;
		a=b-f(tmp3);
		c=b-1+f(base-tmp3);
	}
	cout<<"! "<<a<<" "<<b<<" "<<c<<endl;
}