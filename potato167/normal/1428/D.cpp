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
	int n;
	cin>>n;
	int l=1,r=n;
	vector<pair<int,int>> p,q,ans;
	rep(i,n){
		int a;
		cin>>a;
		if(a==1) q.push_back({i+1,1});
		else if(a!=0) p.push_back({i+1,a});
	}
	int ind=0;
	rep(i,q.size()){
		if(ind==p.size()||p[ind].first>q[i].first){
			ans.push_back({r,q[i].first});
			r--;
		}else
		{
			while(true){
				ans.push_back({l,p[ind].first});
				if(ind+1==p.size()||p[ind].second==2||p[ind+1].first>q[i].first){
					ind++;
					ans.push_back({l,q[i].first});
					l++;
					break;
				}
				ind++;
				ans.push_back({l,p[ind].first});
				l++;
			}
			if(p[ind-1].second==3){
				ans.push_back({r,q[i].first});
				r--;
			}
		}
	}
	if(ind!=p.size()){
		cout<<"-1\n";
	}else{
		cout<<ans.size()<<"\n";
		rep(i,ans.size()){
			cout<<ans[i].first<<" "<<ans[i].second<<"\n";
		}
	}
}