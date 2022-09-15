#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
template<class T> void print_tate(vector<T> &v) {rep(i,v.size()) cout<<v[i]<<"\n";}
void yneos(bool a){if(a) cout<<"Yes"<<"\n"; else cout<<"No"<<"\n";}

void solve();

//
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	rep(i,T) solve();
	return 0;
}

void solve(){
	int N;
	cin>>N;
	int p[N];
	int q[N];
	int p_order[N];
	int seen[N]={0};
	ll ans=1;
	rep(i,N){
		cin>>p[i];
		p[i]--;
		p_order[p[i]]=i;
	}
	rep(i,N) cin>>q[i],q[i]--;
	rep(i,N){
		if(seen[i]!=0) continue;
		ans*=2;
		if(ans>Q) ans-=Q;
		int k=i;
		while(seen[k]==0){
			seen[k]=1;
			k=p_order[q[k]];
		}
	}
	cout<<ans<<"\n";
	return ;
}