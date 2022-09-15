#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=2167167167167167167;
const int INF=2100000000;
const ll mod=998244353;
#define rep(i,a) for (ll i=0;i<a;i++)
#define all(p) p.begin(),p.end()
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}
template<class T> T min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
template<class T> T max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}


void solve();
// oddloop
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	int N;
	cin>>N;
	vector<int> L(N),R(N);
	rep(i,N) cin>>L[i]>>R[i],R[i]++;
	vector<int> p(30);
	vector<int> r(N*2);
	rep(i,30){
		int tmp=0;
		vector<int> q;
		rep(j,N){
			if(R[j]-L[j]>=(1<<i)) tmp++;
			else{
				int a=(L[j]&((1<<i)-1));
				int b=(R[j]&((1<<i)-1));
				if(a>b) tmp++;
				r[j+N]=a;
				r[j]=b;
				q.push_back(j),q.push_back(j+N);
				if(i<3){
					//cout<<i<<" "<<j<<" "<<a<<" "<<b<<endl;
					//cout<<L[i]<<" "<<R[i]<<" "<<(1<<i)-1<<endl;
				}
			}
		}
		sort(all(q),[&](int a,int b){
			return (r[a]<r[b]||(r[a]==r[b]&&a<b));
		});
		p[i]=tmp;
		for(auto x:q){
			if(x<N) tmp--;
			else tmp++;
			chmax(p[i],tmp);
		}
	}
	int Q;
	cin>>Q;
	rep(i,Q){
		int a;
		cin>>a;
		rep(j,30){
			if(a&1){
				cout<<p[j]<<"\n";
				break;
			}
			a>>=1;
		}
	}
}