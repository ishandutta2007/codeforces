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
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}
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
	int n,m,k;
	cin>>n>>m>>k;
	string S,T;
	cin>>S>>T;
	sort(all(S));
	sort(all(T));
	string ans;
	int A=0,B=0,f=-1,v=0;
	while(A!=(int)(S.size())&&B!=(int)(T.size())){
		if(v==k){
			if(f==0){
				f=1;
				v=1;
				ans+=T[B];
				B++;
			}
			else{
				f=0;
				v=1;
				ans+=S[A];
				A++;
			}
		}else{
			if(S[A]<T[B]){
				if(f==0) v++;
				else v=1;
				f=0;
				ans+=S[A];
				A++;
			}else{
				if(f==1) v++;
				else v=1;
				f=1;
				ans+=T[B];
				B++;
			}
		}
	}
	cout<<ans<<"\n";
}