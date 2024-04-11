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

ll f(string S){
	ll A=0;
	rep(i,S.size()){
		A*=27;
		if(S[i]=='_') A+=26;
		else A+=(S[i]-'a');
	}
	return A;
}

ll judge(string S,string T){
	ll a=1;
	rep(i,S.size()){
		if(S[i]!='_' && S[i]!=T[i]) a=0;
	}
	return a;
}

int main() {
	ll N,M,K;
	cin>>N>>M>>K;
	map<string,ll> m;
	vector<string> q(N+1);
	rep(i,N){
		cin>>q[i+1];
		m[q[i+1]]=i+1;
	}
	vector<vector<ll>> G(N+1);
	vector<ll> p(N+1);
	rep(i,M){
		string S;
		ll A;
		cin>>S>>A;
		if(judge(q[A],S)){
			rep(j,(1<<K)){
				string T=S;
				rep(l,K){
					if(j&(1<<l)) T[l]='_';
				}
				if(m.count(T)&&T!=q[A]){
					ll a=m[T];
					G[A].push_back(a),p[a]++;
				}
			}
		}
		else{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	vector<ll> ans;
	ll X=0;
	for(int i=1;i<=N;i++){
		if(p[i]==0) ans.push_back(i),X++;
	}
	for(int i=0;i<N;i++){
		if(X==i&&i!=N-1){
			cout<<"NO"<<endl;
			return 0;
		}
		ll a=ans[i];
		for(auto x:G[a]){
			p[x]--;
			if(p[x]==0) X++,ans.push_back(x);
		}
	}
	cout<<"YES"<<endl;
	rep(i,N-1) cout<<ans[i]<<" ";
	cout<<ans[N-1]<<endl;
}