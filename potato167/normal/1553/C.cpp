#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll I=1167167167167167167;
ll mod=1e9+7;
#define rep(i,a) for (int i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

void solve();

//
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	rep(i,T) solve();
}

void solve(){
	string S;
	cin>>S;
	int ans=10;
	int a=0,b=0;
	rep(roop,2){
		a=0,b=0;
	rep(i,10){
		if(S[i]=='1'){
			if(i%2==0) a++;
			else b++;
		}
		if(S[i]=='?'){
			if(i%2==0){
				if(roop%2==0) a++;
			}
			else{
				if(roop%2==1) b++;
			}
		}
		if(a+(9-i)/2<b||b+(10-i)/2<a){
			chmin(ans,i+1);
		}
	}
	}
	cout<<ans<<"\n";
}