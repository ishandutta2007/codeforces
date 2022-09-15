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

//main
int main() {
	ll N,M,K;
	cin>>N>>M>>K;
	vector<vector<ll>> p(N,vector<ll>(M-1)),q(N-1,vector<ll>(M));
	rep(i,N) rep(j,M-1) cin>>p[i][j];
	rep(i,N-1) rep(j,M) cin>>q[i][j];
	if(K%2==1){
		rep(i,N){
			rep(i,M-1) cout<<"-1 ";
			cout<<"-1"<<"\n";
		}
		return 0;
	}
	vector<vector<ll>> ans(N,vector<ll>(M));
	vector<ll> x={0,0,-1,1},y={-1,1,0,0};
	rep(h,K/2){
		vector<vector<ll>> ans_n(N,vector<ll>(M,I));
				rep(i,N) rep(j,M) rep(k,4){
					ll v=i+x[k],u=j+y[k];
					ll a,b,d;
					if(v==-1||u==-1||v==N||u==M) continue;
					ll l=ans[v][u];
					if(k%2==0) a=v,b=u;
					else a=i,b=j;
					if(k<2) d=p[a][b];
					else d=q[a][b];
					chmin(ans_n[i][j],l+d);
				}
				/*rep(i,N){
		rep(j,M){
			cout<<ans[i][j]*2;
			if(j+1!=M) cout<<" ";
			else cout<<endl;
		}
	}*/
		ans=ans_n;
	}
	rep(i,N){
		rep(j,M){
			cout<<ans[i][j]*2;
			if(j+1!=M) cout<<" ";
			else cout<<endl;
		}
	}
}