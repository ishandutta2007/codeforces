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
template<class T> void print(vector<T> &v) {rep(i,v.size()) cout<<v[i]<<endl;}

//main
int main() {
	ll N;
	cin>>N;
	queue<pair<ll,ll>> 	q1,q2;
	rep(i,N) rep(j,N){
		if((i+j)%2==0) q1.push({i+1,j+1});
		else q2.push({i+1,j+1});
	}
	while(!q1.empty()&&!q2.empty()){
		ll a,b,c;
		cin>>a;
		if(a==1){
			tie(b,c)=q2.front();
			q2.pop();
			cout<<"2 "<<b<<" "<<c<<endl;
		}
		else{
			tie(b,c)=q1.front();
			q1.pop();
			cout<<"1 "<<b<<" "<<c<<endl;
		}
	}
	ll A=1;
	auto q=q1;
	if(q.empty()) q=q2,A=2;
	while(!q.empty()){
		ll a,b,c;
		cin>>a;
		tie(b,c)=q.front();
		q.pop();
		ll B=A;
		if(a==A) B=3;
		cout<<B<<" "<<b<<" "<<c<<endl;
	}
}