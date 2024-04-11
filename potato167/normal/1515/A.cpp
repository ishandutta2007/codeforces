#include <bits/stdc++.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll I=1167167167167167167;
ll Q=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end());reverse(v.begin(),v.end());}
template<class T> void print_tate(vector<T> &v) {rep(i,v.size()) cout<<v[i]<<"\n";}
void yneos(bool a){if(a) cout<<"Yes"<<"\n"; else cout<<"No"<<"\n";}

void solve(){
	int N,x,S=0;
	cin>>N>>x;
	vector<int> p(N);
	rep(i,N) cin>>p[i],S+=p[i];
	if(S==x){
		cout<<"NO"<<"\n";
		return ;
	}
	cout<<"YES"<<"\n";
	int A=0;
	rep(i,N){
		if(A+p[i]==x){
			swap(p[i],p[i+1]);
		}
		A+=p[i];
		cout<<p[i];
		if(i==N-1) cout<<"\n";
		else cout<<" ";
	}
}

//main
int main() {
	int T;
	cin>>T;
	rep(i,T) solve();
}