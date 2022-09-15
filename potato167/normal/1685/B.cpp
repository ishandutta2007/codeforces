#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
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
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}


void solve();
// oddloop
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	string S;
	cin>>S;
	int J=a+c+d;
	vector<int> p,q;
	int base=0;
	int L=1;
	char f=S[0];
	int n=S.size();
	for(int i=0;i<n;i++){
		if(S[i]=='A') J--;
		if(i==n-1||S[i+1]==S[i]){
			if(L%2) base+=L/2;
			else if(f=='A') p.push_back(L/2-1);
			else q.push_back(L/2-1);
			L=1;
			f=S[i];
		}else{
			L++;
		}
	}
	if(J!=0){
		yneos(0);
		return ;
	}
	So(p),So(q);
	for(auto x:p){
		if(c>x){
			c-=x+1;
		}else base+=x;
	}for(auto x:q){
		if(d>x){
			d-=x+1;
		}else base+=x;
	}
	yneos(c+d<=base);
}