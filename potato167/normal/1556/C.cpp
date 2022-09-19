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
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}



//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	vector<pair<ll,ll>> p(n);
	ll tmp=0;
	set<ll> s;
	s.insert(tmp);
	rep(i,n){
		ll a;
		cin>>a;
		if(i%2==0){
			p[i]={tmp,tmp+a};
			tmp+=a;
		}else{
			p[i]={tmp-a,tmp};
			tmp-=a;
		}
		s.insert(tmp);
	}
	int L=0;
	map<ll,int> m;
	vector<ll> q;
	for(auto x:s){
		m[x]=L;
		if(L!=0) q[L-1]+=x;
		q.push_back(-x);
		L++;
	}
	vector<ll> table(L-1),just(L-1);
	ll ans=0;
	rep(i,n){
		ll l,r;
		tie(l,r)=p[i];
		int a=m[l],b=m[r];
		if(i%2==0){
			for(int j=a;j<b;j++) table[j]+=q[j];
		}else{
			for(int j=a;j<b;j++){
				ans+=table[j]+just[j];
				if(j==a) just[j]+=table[j]/q[j];
				else just[j]=0;
				table[j]=0;
			}
		}
		/*rep(j,L-1) cout<<table[j]<<" ";
		cout<<"\n";*/
	}
	cout<<ans<<"\n";
}