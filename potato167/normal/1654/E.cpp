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
const ll mod=998244353;
#define rep(i,a) for (int i=0;i<a;i++)
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



int solve(int n,vector<int> &p);
// oddloop
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//int t=1;
	//cin>>t;
	int n;
	cin>>n;
	vector<int> p(n);
	rep(i,n) cin>>p[i];
	int x=solve(n,p);
	cout<<n-x<<"\n";
}

int solve(int n,vector<int> &p){
	int ans=0;
	int B=320,L=1e5+10;
	vector<int> m(L*B);
	vector<int> use;
	rep(i,B){
		rep(j,n){
			int z=p[j]+j*i;
			m[z]++;
			chmax(ans,m[z]);
		}rep(j,n){
			m[p[j]+j*i]--;
		}
	}
	reverse(all(p));
	rep(i,B){
		rep(j,n){
			int z=p[j]+j*i;
			m[z]++;
			chmax(ans,m[z]);
		}
		rep(j,n){
			m[p[j]+j*i]--;
		}
	}
	rep(i,n){
		for(int j=i+1;j<min(i+B,n);j++){
			if(abs(p[j]-p[i])%(j-i)!=0) continue;
			int c=(p[j]-p[i])/(j-i)+L;
			m[c]++;
			chmax(ans,m[c]+1);
			use.push_back(c);
		}
		for(auto x:use) m[x]=0;
		use={};
	}
	return ans;
}