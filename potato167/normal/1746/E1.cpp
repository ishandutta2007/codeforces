#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=2167167167167167167;
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
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<endl;}
template<class T> T min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
template<class T> T max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}



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
	int local=0,c=0,ans=167;
	int n;
	cin>>n;
	vector<int> p,q;
	rep(i,n){
		if(i&1) p.push_back(i+1);
		else q.push_back(i+1);
	}
	auto out=[&](vector<int> p)->bool{
		c++;
		//assert(c<=53);
		if(local){
			bool J=0;
			for(auto x:p){
				if(x==ans) J=1;
			}
			return J;
		}
		cout<<"? "<<p.size()<<" ";
		vec_out(p);
		string S;
		cin>>S;
		return S[0]=='Y';
	};
	auto fin=[&](int a)->bool{
		if(local){
			if(ans==a){
				cout<<"clear "<<c<<endl;
				return true;
			}else{
				return false;
			}
		}
		cout<<"! "<<a<<endl;
		string S;
		cin>>S;
		return S==":)";
	};
	if(n==3){
		if(out({1})){
			if(!fin(1)){
				if(out({2})) fin(2);
				else fin(3);
			}
		}else{
			if(out({1})){
				if(!fin(1)){
					if(out({2})) fin(2);
					else fin(3);
				}
			}else{
				if(!fin(2)) fin(3);
			}
		}
		return;
	}
	if(!out(p)){
		swap(p,q);
	}
	while((int)(q.size())+(int)(p.size())>=4){
		vector<int> A,B,C,D,E;
		rep(i,(int)(p.size())){
			if(i&1) A.push_back(p[i]),E.push_back(p[i]);
			else B.push_back(p[i]);
		}
		rep(i,(int)(q.size())){
			if(i&1) D.push_back(q[i]);
			else C.push_back(q[i]),E.push_back(q[i]);
		}
		if(!out(E)){
			swap(A,B);
			swap(C,D);
		}
		p=A;
		q=B;
		for(auto x:C) p.push_back(x);
	}
	string S;
	if((int)(p.size())==1){
		if(!fin(p[0])) fin(q[0]);
	}
	else if((int)(p.size())==2){
		if(out(p)){
			if(!fin(p[0])) fin(p[1]);
		}else{
			if(!fin(q[0])){
				if(out({p[0]})) fin(p[0]);
				else fin(p[1]);
			}
		}
	}else{
		assert(false);
	}
}