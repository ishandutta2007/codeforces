#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=1167167167167167167;
const int INF=2100000000;
const ll mod=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}


void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> left(n),right(n);
	vector<int> p(n);
	rep(i,n){
		int a;
		cin>>a;
		right[a-1]++;
		p[i]=a-1;
	}
	vector<vector<ll>> cownt(n,vector<ll>(n+1));
	rep(i,m){
		int a,b;
		cin>>a>>b;
		a--;
		cownt[a][b]++;
	}
	rep(i,n) rep(j,n) cownt[i][j+1]+=cownt[i][j];
	int ans=0;
	ll val=1;
	rep(i,n){
		if(cownt[i][right[i]]!=0) ans++,val=(val*cownt[i][right[i]])%mod;
	}
	rep(i,n){
		int a=p[i];
		right[a]--;
		left[a]++;
		if(cownt[a][left[a]]-cownt[a][left[a]-1]==1){
			int tmp_ans=1;
			ll tmp_val=1;
			rep(i,n){
				if(i==a){
					if(left[a]<=right[a]){
						if(cownt[a][right[a]]>1){
							tmp_ans++;
							tmp_val*=cownt[a][right[a]]-1;
						}
					}else if(cownt[a][right[a]]>=1){
						tmp_ans++;
						tmp_val*=cownt[a][right[a]];
					}
				}else{
					int b=left[i],c=right[i];
					if(b>c) swap(b,c);
					if(cownt[i][b]>=2||(cownt[i][b]==1&&cownt[i][c]>=2)){
						tmp_ans+=2;
						tmp_val*=(cownt[i][b])*(cownt[i][c]-1);
					}else if(cownt[i][b]){
						tmp_ans++;
						tmp_val*=2;
					}else if(cownt[i][c]){
						tmp_ans++;
						tmp_val*=cownt[i][c];
					}
				}
				tmp_val%=mod;
			}
			if(chmax(ans,tmp_ans)) val=tmp_val;
			else if(ans==tmp_ans) val+=tmp_val;
		}
	}
	cout<<ans<<" "<<(val%mod+mod)%mod<<"\n";
}