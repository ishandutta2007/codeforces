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
	vector<int> p(n);
	set<int> s;
	rep(i,n){
		cin>>p[i];
		if(s.count(p[i])) s.erase(p[i]);
		else s.insert(p[i]);
	}
	if(!s.empty()){
		cout<<"-1\n";
		return ;
	}
	vector<pair<int,int>> op;
	vector<int> ans;
	int front_len=0;
	while(p.size()!=0){
		int ind=1;
		while(p[ind]!=p[0]) ind++;
		for(int j=1;j<ind;j++){
			op.push_back({front_len+ind+j,p[j]});
		}
		front_len+=ind*2;
		ans.push_back((ind)*2);
		vector<int> q((int)(p.size())-2);
		for(int i=0;i<(int)(p.size());i++){
			if(i>ind) q[i-2]=p[i];
			else if(0<i&&i<ind){
				q[ind-i-1]=p[i];
			}
		}
		swap(p,q);
		/*for(int i=0;i<(int)(p.size());i++){
			cout<<p[i]<<" ";
		}
		cout<<"\n";*/
	}
	cout<<op.size()<<"\n";
	rep(i,(int)(op.size())){
		cout<<op[i].first<<" "<<op[i].second<<"\n";
	}
	cout<<ans.size()<<"\n";
	rep(i,(int)(ans.size())){
		if(i) cout<<" ";
		cout<<ans[i];
	}
	cout<<"\n";
}