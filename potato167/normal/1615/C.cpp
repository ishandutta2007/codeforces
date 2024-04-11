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
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	string S,T;
	cin>>S>>T;
	if(S==T){
		cout<<"0\n";
		return ;
	}
	string Z;
	rep(i,n) Z+='0';
	if(Z==S||Z==T){
		cout<<"-1\n";
		return ;
	}
	vector<int> p(4);
	rep(i,n){
		int a=0;
		if(S[i]=='1') a++;
		if(T[i]=='1') a+=2;
		p[a]++;
	}
	/*rep(i,4) cout<<p[i]<<" ";
	cout<<"\n";*/
	int ans=INF;
	if(p[0]+1==p[3]) chmin(ans,p[0]*2+1);
	if(p[1]==p[2]) chmin(ans,p[1]*2);
	if(ans==INF) cout<<"-1\n";
	else cout<<ans<<"\n";
}