#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
ll I=1167167167167167167;
ll Q=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end());reverse(v.begin(),v.end());}
void operation(ll &L,ll &M,ll &R,ll &a,ll& b,ll& c){
	ll D=(L+M)/2,e;
	cout<<"? "<<D<<endl;
	cin>>e;
	if(b<e) L=D,a=e;
	else R=M,M=D,c=b,b=e;
}

int main() {
	ll N;
	cin>>N;
	ll l=0,m=(N+1)/2,r=N+1;
	ll A=Q,B,C=Q;
	cout<<"? "<<m<<endl;
	cin>>B;
	while(r-l>2){
		if(m-l>r-m) operation(l,m,r,A,B,C);
		else operation(r,m,l,C,B,A);
	}
	cout<<"! "<<m<<endl;
}