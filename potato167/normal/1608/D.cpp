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
ll jyo(ll x,ll y,ll z){
  ll H=y; //
       ll a=1,b=x,c=1;
       while(H>0){
         a*=2;
         if(H%a!=0){
           H-=a/2;
           c*=b;
           c%=z;
         }
        b*=b;
         b%=z;
      } //
 return c;
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
	int n;
	cin>>n;
	int A=0,B=0;
	ll X=1;
	vector<set<int>> s(2);
	rep(i,n){
		string S;
		cin>>S;
		if(S=="BB") A--;
		int tmp=1;
		rep(j,2){
			if(S[j]=='?') B++;
			if(S[j]=='B') tmp=0;
			s[j].insert(S[j]);
		}
		A+=tmp;
		if(S=="??") X*=2ll;
		if(S=="BB"||S=="WW") X=0;
		X%=mod;
	}
	if(A>B||A<0){
		cout<<"0\n";
		return ;
	}
	ll C=1,D=1;
	rep(i,A){
		D*=(i+1);
		C*=(B-i);
		D%=mod,C%=mod;
	}
	if(!s[0].count('B')&&!s[1].count('W')) X--;
	if(!s[1].count('B')&&!s[0].count('W')) X--;
	cout<<((C*jyo(D,mod-2,mod))%mod-X+mod)%mod<<"\n";
}