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
const int INF=200000000;
const ll mod=998244353;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}


namespace po167{
template<class T>
struct my_set_max{
	priority_queue<T> exist;
	priority_queue<T> absent;
	void op(){
		while(!absent.empty()&&exist.top()==absent.top()){
			exist.pop();
			absent.pop();
		}
	}
	size_t size(){
		op();
		return exist.size()-absent.size();
	}
	T get(){
		op();
		return exist.top();
	}
	void insert(T a){
		exist.push(a);
	}
	void delate(T a){
		absent.push(a);
	}
};
template<class T>
struct my_set_min{
	priority_queue<T, vector<T>, greater<T>> exist;
	priority_queue<T, vector<T>, greater<T>> absent;
	void op(){
		while(!absent.empty()&&exist.top()==absent.top()){
			exist.pop();
			absent.pop();
		}
	}
	T get(){
		op();
		return exist.top();
	}
	size_t size(){
		op();
		return exist.size()-absent.size();
	}
	void insert(T a){
		exist.push(a);
	}
	void delate(T a){
		absent.push(a);
	}
};
template<class T>
struct my_set_med{
	my_set_max<T> pq_left;
	my_set_min<T> pq_right;
	void op(){
		while(pq_left.size()>pq_right.size()){
			T tmp=pq_left.get();
			pq_left.delate(tmp);
			pq_right.insert(tmp);
		}
		while(pq_left.size()<pq_right.size()){
			T tmp=pq_right.get();
			pq_right.delate(tmp);
			pq_left.insert(tmp);
		}
	}
	void insert(T a){
		if(pq_left.size()!=0&&pq_left.get()>a) pq_left.insert(a);
		else pq_right.insert(a);
	}
	void delate(T a){
		if(pq_left.size()!=0&&pq_left.get()>=a) pq_left.delate(a);
		else pq_right.delate(a);
	}
	std::pair<T,T> get(){
		op();
		assert(pq_left.size()!=0);
		if(pq_left.size()==pq_right.size()){
			return {pq_left.get(),pq_right.get()};
		}
		else return {pq_left.get(),pq_left.get()};
	}
	size_t size(){
		return pq_left.size()+pq_right.size();
	}
};
}
using po167::my_set_max;
using po167::my_set_min;
using po167::my_set_med;


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
	vector<int> p(n),last(n);
	rep(i,n) cin>>p[i],p[i]--,last[p[i]]=i;
	vector<int> ans(n+1,-INF);
	int v=-INF;
	ans[0]=0;
	vector<vector<int>> q(n);
	my_set_max<int> pq;
	pq.insert(-INF);
	rep(i,n){
		ans[i+1]=ans[i]-1;
		chmax(ans[i+1],pq.get()-1);
		q[last[p[i]]].push_back(ans[i+1]);
		pq.insert(ans[i+1]);
		for(auto x:q[i]){
			pq.delate(x);
		}
	}
	cout<<n+ans[n]<<"\n";
}