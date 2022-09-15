#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
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




void solve();
// oddloop
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	string S;
	cin>>S;
	int k;
	cin>>k;
	vector<int> p(26);
	rep(i,k){
		char a;
		cin>>a;
		p[a-'a']=1;
	}
	vector<int> q;
	int front=0;
	rep(i,n){
		if(p[S[i]-'a']) q.push_back(i-front),front=i+1;
	}
	if(q.empty()){
		cout<<"0\n";
		return ;
	}
	int ans=0;
	while((int)q.size()!=1){
		ans++;
		vector<int> n_q;
		int ind=-1;
		rep(i,(int)(q.size())){
			if(i==0){
				n_q.push_back(max(q[i]-1,0));
				ind++;
			}
			else{
				if(q[i]) n_q.push_back(q[i]-1),ind++;
			}
		}
		swap(n_q,q);
	}
	cout<<ans+q[0]<<"\n";
}