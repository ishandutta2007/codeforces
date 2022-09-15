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
#define all(p) p.begin(),p.end()
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}

// return val=p(N)
// a=p[0].first^p[0].second * ... *p[N-1].first^p[N-1].second
// for all i: p[i].first is prime number
// O(sqrt(val))
std::vector<std::pair<long long,long long>> Prime_factorization(long long val){
	assert(val>=1);
	if(val==1){
		return {};
	}
	int ind=0;
	std::vector<std::pair<long long,long long>> ans;
	for(long long i=2;i*i<=val;i++){
		if(val%i!=0) continue;
		ans.push_back({i,0});
		while(val%i==0){
			ans[ind].second++;
			val/=i;
		}
		ind++;
	}
	if(val!=1) ans.push_back({val,1});
	return ans;
}
 

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
	ll x,d;
	cin>>x>>d;
	if(x%(d*d)){
		yneos(0);
		return;
	}
	auto p=Prime_factorization(x);
	auto q=Prime_factorization(d);
	if(q.size()!=1){
		auto r=Prime_factorization(x/(d*d));
		yneos(r.size()!=0&&(r.size()!=1||r[0].second!=1));
		return;
	}
	int c=0;
	q.push_back({INF,INF});
	for(auto x:p){
		//cout<<x.first<<" "<<x.second<<"\n";
		int b=LB(q,{x.first,0});
		if(q[b].first!=x.first) c+=x.second;
		else{
			int d=x.second/q[b].second;
			if((2*q[b].second-1)*(d-1)>=x.second) c+=2;
			else{
				int e=x.second-d*q[b].second;
				//cout<<"#"<<e<<endl;
				if(e==1){
					c++;
				}else if(e!=0){
					c++;
					if(q[b].second!=2&&d!=1) c++;
				}
			}
		}
		//cout<<c<<endl;
	}
	yneos(c>=2);
}