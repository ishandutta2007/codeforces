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
#define rep(i,a) for (int i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}



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
	int n,r;
	cin>>r>>n;
	vector<int> t(n+1),x(n+1),y(n+1);
	rep(i,n) cin>>t[i+1]>>x[i+1]>>y[i+1],x[i+1]--,y[i+1]--;
	vector<int> ans(n+1,-INF),sum(n+1);
	ans[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=0;j--){
			if(t[i]-t[j]>=2*r){
				chmax(ans[i],sum[j]);
				break;
			}
			if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j]) chmax(ans[i],ans[j]);
		}
		ans[i]++;
		sum[i]=max(ans[i],sum[i-1]);
	}
	cout<<sum[n]<<"\n";
}