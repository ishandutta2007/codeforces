#include <bits/stdc++.h>
using namespace std;
using std::cout;
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
template<class T> void print(vector<T> v) {rep(i,v.size()) cout<<v[i]<<endl;}

//main
int main() {
	ll N;
	cin>>N;
	vector<ll> p(N);
	rep(i,N) cin>>p[i];
	vector<ll> q={0};
	ll k=0,a=0;
	rep(i,N-1){
		if(a^(p[i]>p[i+1])) q.push_back(1),a^=1,k++;
		else q[k]++;
	}
	if(q.size()%2==1) q.push_back(0);
	ll M=q.size();
	vector<pair<ll,ll>> r(M/2);
	rep(i,M/2){
		//cout<<q[i*2]<<" "<<q[i*2+1]<<endl;
		if(q[i*2]>q[i*2+1]) swap(q[i*2],q[i*2+1]);
		r[i]={q[i*2+1],q[i*2]};
	}
	Sore(r);
	ll J=1;
	if(r[0].second!=r[0].first) J=0;
	if(r[0].second%2==1) J=0;
	if(r.size()!=1){
		if(r[0].second%2==1||r[0].second==r[1].first) J=0;
	}
	cout<<J<<endl;
}