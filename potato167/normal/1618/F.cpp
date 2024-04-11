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

string f(ll a){
	string S;
	while(a!=0){
		S+=(char)('0'+(a%2));
		a/=2;
	}
	reverse(S.begin(),S.end());
	return S;
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
	ll x,y;
	cin>>x>>y;
	if(x==y){
		yneos(1);
		return ;
	}if(y%2==0){
		yneos(0);
		return ;
	}
	vector<string> p(4);
	p[0]=f(x);
	p[1]=p[0];
	reverse(p[1].begin(),p[1].end());
	while(x%2==0) x/=2;
	p[2]=f(x);
	p[3]=p[2];
	reverse(p[3].begin(),p[3].end());
	int J=0;
	string T=f(y);
	int n=T.size();
	rep(i,4){
		//cout<<p[i].size()<<endl;
		for(int j=0;j<=n-(int)(p[i].size());j++){
			int tmp=1;
			rep(k,n){
				if(k<j||j+p[i].size()<=k){
					if(T[k]=='0') tmp=0;
				}else{
					if(p[i][k-j]!=T[k]) tmp=0;
				}
			}
			J+=tmp;
		}
	}
	yneos(J);
}