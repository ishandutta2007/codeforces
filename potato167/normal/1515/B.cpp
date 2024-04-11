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

bool f(ll a){
	ll l=0,r=a;
	while(r-l>1){
		ll D=(l+r)/2;
		if(D*D>=a) r=D;
		else l=D;
	}
	if(r*r==a) return true;
	else return false;
}

//main
int main() {
	int T;
	cin>>T;
	rep(i,T){
		int a;
		cin>>a;
		if(a%2==1){
			cout<<"NO"<<"\n";
			continue;
		}
		bool T=(f(a/2)||((a%4==0)&&f(a/4)));
		if(T==1) cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}
}