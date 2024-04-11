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
ll mod=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}

int GCD(int a,int b){
	if(b==0) return a;
	return GCD(b,a%b);
}

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	rep(i,t){
		int n,d;
		cin>>n>>d;
		vector<int> p(n);
		rep(i,n) cin>>p[i];
		int c=GCD(n,d);
		int s=n/c;
		int ans=0;
		rep(j,c){
			vector<bool> q(2*s);
			rep(k,s*2){
				q[k]=p[(j+k*d)%n];
			}
			int tmp=-1;
			int val=0;
			rep(k,2*s){
				if(q[k]) val++;
				else chmax(tmp,val),val=0;
			}
			if(tmp==-1) ans=INF;
			else chmax(ans,tmp);
		}
		if(ans==INF) cout<<"-1\n";
		else cout<<ans<<"\n";
	}
}