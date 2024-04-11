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


	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	vector<int> p(40);
	rep(i,n){
		int a;
		cin>>a;
		int b=0;
		while(a%2==0) a/=2,b++;
		p[b]++;
	}
	ll ans=jyo(2,n,mod)-1;
	ll tmp=0;
	for(int i=39;i>0;i--){
		tmp+=p[i];
		if(tmp!=0&&p[i]!=0) ans-=jyo(2,tmp-1,mod);
	}
	cout<<(ans%mod+mod)%mod<<"\n";
}