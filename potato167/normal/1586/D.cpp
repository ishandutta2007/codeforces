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



//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	vector<int> ans(n);
	ans[n-1]=1;
	int k;
	rep(i,n-1){
		cout<<"?";
		rep(j,n){
			if(j!=n-1) cout<<" 1";
			else cout<<" "<<i+2;
		}
		cout<<endl;
		cin>>k;
		if(k==0){
			ans[n-1]=n-i;
			break;
		}
	}
	for(int i=n;i>0;i--){
		if(i==ans[n-1]) continue;
		cout<<"?";
		rep(j,n-1){
			cout<<" "<<ans[n-1];
		}
		cout<<" "<<i<<endl;
		cin>>k;
		ans[k-1]=i;
	}
	cout<<"!";
	rep(i,n){
		cout<<" "<<ans[i];
	}
	cout<<endl;
}