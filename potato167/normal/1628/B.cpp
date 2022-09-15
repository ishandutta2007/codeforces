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
	int n;
	cin>>n;
	set<string> s,t;
	int J=0;
	rep(i,n){
		string T;
		cin>>T;
		if(T.size()==1){
			J=1;
			continue;
		}
		else if(T.size()==2){
			if(s.count(T)) J=1;
			if(T[0]==T[1]) J=1;
			rep(j,26){
				char c='a'+j;
				string U="";
				U+=c;
				U+=T;
				if(t.count(U)) J=1;
			}
			reverse(T.begin(),T.end());
			s.insert(T);
		}
		else{
			string U="";
			U+=T[1];
			U+=T[2];
			//if(n==3) cout<<U<<"\n";
			if(s.count(U)) J=1;
			U=T;
			reverse(U.begin(),U.end());
			t.insert(U);
			if(t.count(T)) J=1;
		}
	}
	yneos(J);
}