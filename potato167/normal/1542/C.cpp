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
ll Q=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
template<class T> void print_tate(vector<T> &v) {rep(i,v.size()) cout<<v[i]<<"\n";}
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
//
long long carmichael(long long a){
	long long ans=1,A=1;
	//2
	while(a%2==0) A*=2,a/=2;
	if(A==4) ans=2;
	else if(A>4) ans=A/4;
	A=a;
	for(long long k=3;k*k<=a;k++){
	//for(auto k:div){ //divsqrt(a)
		if(A%k==0){
			long long B=k-1;
			A/=k;
			while(A%k==0) A/=k,B*=k;
			ans=Lcm(ans,B);
		}
	}
	if(A!=1) ans=Lcm(ans,A-1);
	return ans;
}


void solve();

//
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	rep(i,T) solve();
}

void solve(){
	ll n;
	cin>>n;
	ll ans=0;
	ll sum=1;
	ll now=2;
	while(n!=0){
		ll w=now/Gcd(now,sum);
		ans+=(now*((n-n/w)%Q))%Q;
		ans%=Q;
		n/=w;
		sum=Lcm(sum,now);
		now++;
	}
	//cout<<sum<<endl;
	cout<<ans%Q<<endl;
}