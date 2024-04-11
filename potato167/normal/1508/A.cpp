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

void han(string &S){
	rep(i,S.size()){
		if(S[i]=='0') S[i]='1';
		else S[i]='0';
	}
}

string solve(){
	ll N;
	cin>>N;
	vector<pair<ll,string>> p(3);
	rep(i,3) cin>>p[i].second;
	rep(i,3){
		rep(j,N*2) if(p[i].second[j]=='1') p[i].first++;
	}
	So(p);
	ll J=0,A;
	string S,T;
	if(p[1].first<N){
		S=p[1].second;
		T=p[0].second;
		han(S),han(T);
		J=1;
		A=2*N-p[0].first;
	}
	else{
		S=p[2].second;
		T=p[1].second;
		A=p[2].first;
	}
	//cout<<A<<" "<<S<<" "<<T<<endl;
	vector<ll> q(A+1);
	vector<string> r={S,T};
	rep(i,2){
		ll k=0;
		rep(j,2*N){
			if(r[i][j]=='1') k++;
			else q[k]++;
		}
	}
	string ans;
	rep(i,A+1){
		rep(l,q[i]) ans+='0';
		if(i!=A) ans+='1';
		if(i==A){
			while(ans.size()!=3*N) ans+='0';
		}
	}
	if(J==1) han(ans);
	return ans;
	return "I";
}

//main
int main() {
	ll T;
	cin>>T;
	vector<string> ans(T);
	rep(i,T) ans[i]=solve();
	print_tate(ans);
}