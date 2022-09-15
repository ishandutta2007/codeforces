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
const ll mod=1e9+7;
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
	
	int t=1;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	vector<ll> p(n),q(n);
	rep(i,n) cin>>p[i];
	ll tmp=0;
	int x=gcd(abs(p[0]),abs(p[1]));
	for(int i=2;i<n;i++){
		if((tmp<0)^(p[i]<0)){
			q[i]=x;
			tmp+=x*p[i];
		}else{
			q[i]=-x;
			tmp-=x*p[i];
		}
	}
	ll val=ILL;
	for(ll i=-(1e4);i<=1e4;i++){
		if((abs(p[1])*INF-p[0]*i-tmp)%abs(p[1])==0){
			if(tmp+i*p[0]==0||i==0) continue;
			//cout<<tmp<<" "<<i<<"\n";
			
			if(chmin(val,abs(i)+abs((tmp+i*p[0])/p[1]))){
				q[0]=i;
				q[1]=-(tmp+i*p[0])/p[1];
			}
		}
	}
	rep(i,n){
		if(i) cout<<" ";
		cout<<q[i];
	}
	cout<<"\n";
}