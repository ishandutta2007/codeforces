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
#define rep(i,a) for (int i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

vector<ll> g(vector<ll> &p,vector<ll> &q,int ind,ll a){
	if(p.size()==0&&q.size()==0) return {};
	if(p.size()==0) return {q[0]};
	if(q.size()==0) return {p[0]};
	if(ind==-1) return {p[0],q[0]};
	vector<ll> A,B,C,D;
	rep(i,p.size()){
		if(p[i]&(1<<ind)) A.push_back(p[i]);
		else B.push_back(p[i]);
	}rep(i,q.size()){
		if(q[i]&(1<<ind)) C.push_back(q[i]);
		else D.push_back(q[i]);
	}
	if(0==(a&(1<<ind))){
		if(A.size()!=0&&D.size()!=0) return {A[0],D[0]};
		if(B.size()!=0&&C.size()!=0) return {B[0],C[0]};
		auto X=g(A,C,ind-1,a);
		auto Y=g(B,D,ind-1,a);
		if(X.size()<Y.size()) return Y;
		return X;
	}
	auto X=g(A,D,ind-1,a);
	auto Y=g(B,C,ind-1,a);
	if(X.size()<Y.size()) return Y;
	return X;
}

vector<ll> f(vector<ll> &p,int ind,ll a){
	if(p.size()==0) return p;
	vector<ll> A,B;
	for(auto x:p){
		if(x&(1<<ind)) A.push_back(x);
		else B.push_back(x);
	}
	if(a&(1<<ind)){
		return g(A,B,ind-1,a);
	}else{
		auto C=f(A,ind-1,a);
		auto D=f(B,ind-1,a);
		for(auto z:D) C.push_back(z);
		return C;
	}
	return {};
}

void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	ll n,k;
	cin>>n>>k;
	vector<ll> p(n);
	map<ll,int> m;
	rep(i,n) cin>>p[i],m[p[i]]=i+1;
	if(k==0){
		cout<<n<<"\n";
		rep(i,n){
			if(i) cout<<" ";
			cout<<i+1;
		}
		cout<<"\n";
		return ;
	}
	auto ans=f(p,30,k);
	if(ans.size()<2) cout<<"-1\n";
	else{
		cout<<ans.size()<<"\n";
		rep(i,ans.size()){
			if(i) cout<<" ";
			cout<<m[ans[i]];
		}
		cout<<"\n";
	}
}