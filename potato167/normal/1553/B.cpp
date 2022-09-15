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

//
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	rep(i,T) solve();
}

void solve(){
	string S,T;
	cin>>S>>T;
	bool ans=false;
	int N=S.size();
	int M=T.size();
	rep(i,N) for(int j=i;j<N;j++){
		if(2*j+1-i<M) continue;
		int k=0;
		bool J=true;
		for(int l=i;l<j;l++){
			if(S[l]!=T[k]) J=false;
			k++;
			if(k==M) break;
		}
		if(k==M){
			ans|=J;
			break;
		}
		for(int l=j;l>=0;l--){
			if(S[l]!=T[k]) J=false;
			k++;
			if(k==M) break;
		}
		ans|=J;
	}
	yneos(ans);
}