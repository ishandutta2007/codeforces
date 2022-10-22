#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N;
	vector<pair<pair<int,int>,pair<int,int>>>v(N);
	for(auto &i:v)cin>>i.first.first>>i.first.second>>i.second.first>>i.second.second;
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	auto w=v;
	for(auto &i:w){
		swap(i.first.first,i.first.second);
	}
	sort(w.begin(),w.end());
	reverse(w.begin(),w.end());
	//v...st w...ed
	int vcnt=0;
	int wcnt=0;
	set<int>st;
	set<int>ed;
	while(wcnt<N){
		while(vcnt<N&&v[vcnt].first.first>w[wcnt].first.first){
			st.insert(v[vcnt].second.first);
			ed.insert(-v[vcnt].second.second);
			vcnt++;
		}
		auto it=st.lower_bound(w[wcnt].second.first);
		if(it!=st.end()){
			if(*it<=w[wcnt].second.second){
				cout<<"NO\n";
				return 0;
			}
		}
		it=ed.lower_bound(-w[wcnt].second.second);
		if(it!=ed.end()){
			if(*it<=-w[wcnt].second.first){
				cout<<"NO\n";
				return 0;
			}
		}
		wcnt++;
	}
	for(auto &i:w){
		swap(i.first.first,i.first.second);
		swap(i.first,i.second);
		swap(i.first.first,i.first.second);
	}
	for(auto &i:v){
		swap(i.first,i.second);
	}
	st.clear();
	ed.clear();
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	sort(w.begin(),w.end());
	reverse(w.begin(),w.end());
	vcnt=wcnt=0;
	while(wcnt<N){
		//cout<<w[wcnt].first.first<<" "<<w[wcnt].first.second<<endl;
		while(vcnt<N&&v[vcnt].first.first>w[wcnt].first.first){
			st.insert(v[vcnt].second.first);
			ed.insert(-v[vcnt].second.second);
			vcnt++;
		}
		auto it=st.lower_bound(w[wcnt].second.first);
		if(it!=st.end()){
			if(*it<=w[wcnt].second.second){
				cout<<"NO\n";
				return 0;
			}
		}
		it=ed.lower_bound(-w[wcnt].second.second);
		if(it!=ed.end()){
			if(*it<=-w[wcnt].second.first){
				cout<<"NO\n";
				return 0;
			}
		}
		wcnt++;
	}
	cout<<"YES\n";
	
	
}