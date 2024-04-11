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

void solve(){
	ll N,J=0;
	cin>>N;
	string S;
	cin>>S;
	string T,U;
	rep(i,N) T+=".",U+=".";
	ll M=0;
	rep(i,N) if(S[i]=='1') M++;
	if(M%2==1){
		J=1;
	}
	ll k=0,l=0;
	rep(i,N){
		if(S[i]=='1'){
			if(k<M/2) T[i]='(',U[i]='(';
			else T[i]=')',U[i]=')';
			k++;
		}
		else{
			l^=1;
			if(l==1) T[i]='(',U[i]=')';
			else T[i]=')',U[i]='(';
		}
		if(M/2-abs(k-M/2)<l){
			J=1;
			break;
		}
	}
	if(J==1) cout<<"NO"<<endl;
	else{
		cout<<"YES"<<"\n"<<T<<"\n"<<U<<"\n";
	}
}


//main
int main() {
	ll T;
	cin>>T;
	rep(i,T) solve();
}