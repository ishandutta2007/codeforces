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

namespace po167{
template<class T,T(*op)(T,T)>
struct Doubling_op
{
	int _n;
	long long Log;
	std::vector<std::vector<int>> index_data;
	std::vector<std::vector<T>> value_data;
	Doubling_op(int n,long long limit,std::vector<int> index,std::vector<T> value):_n(n){
		Log=2;
		while(limit){
			limit/=2;
			Log++;
		}
		index_data.resize(Log);
		value_data.resize(Log);
		index_data[0]=index;
		value_data[0]=value;
		for(int i=1;i<Log;i++){
			index_data[i].resize(_n);
			value_data[i].resize(_n);
			for(int j=0;j<_n;j++){
				int tmp=index_data[i-1][j];
				index_data[i][j]=index_data[i-1][tmp];
				value_data[i][j]=op(value_data[i-1][j],value_data[i-1][tmp]);
			}
		}
	}
	std::pair<int,T> query(long long times,int start_index,T start_value){
		for(int i=0;i<Log;i++){
			if(times&1){
				start_value=op(start_value,value_data[i][start_index]);
				start_index=index_data[i][start_index];
			}
			times>>=1;
		}
		return std::make_pair(start_index,start_value);
	}
};

struct Doubling
{
	int _n;
	long long Log;
	std::vector<std::vector<int>> index_data;
	Doubling(int n,long long limit,std::vector<int> index):_n(n){
		Log=2;
		while(limit){
			limit/=2;
			Log++;
		}
		index_data.resize(Log);
		index_data[0]=index;
		for(int i=1;i<Log;i++){
			index_data[i].resize(_n);
			for(int j=0;j<_n;j++){
				int tmp=index_data[i-1][j];
				index_data[i][j]=index_data[i-1][tmp];
			}
		}
	}
	int query(long long times,int start_index){
		for(int i=0;i<Log;i++){
			if(times&1){
				start_index=index_data[i][start_index];
			}
			times>>=1;
		}
		return start_index;
	}
};
}
using po167::Doubling_op;
using po167::Doubling;
using doubleing_F=long long;
doubleing_F d_op(doubleing_F l,doubleing_F r){
	return l+r;
}

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
	int n;
	cin>>n;
	vector<int> p(n),A(n),rev(n,-1);
	int M=0;
	set<int> s;
	rep(i,n) cin>>p[i],p[i]--,s.insert(p[i]);
	rep(i,n){
		cin>>A[i];
		A[i]--;
		chmax(M,A[i]);
		if(A[i]<n) rev[A[i]]=i;
	}
	int op=(M+1-n)/(n-(int)(s.size()));
	Doubling D(n,op+10,p);
	//cout<<op<<endl;
	vector<int> q(n);
	rep(i,n) q[i]=D.query(op,i);//,cout<<q[i]<<" "<<rev[i]<<endl;
	vector<vector<int>> G(n);
	rep(i,n) G[q[i]].push_back(i);
	rep(i,n) G[i].push_back(INF);
	_pq<tuple<int,int,int>> pq;
	vector<int> ans(n,-1);
	rep(i,n){
		if(rev[i]!=-1){
			ans[G[rev[i]][0]]=i+1;
			pq.push({G[rev[i]][1],rev[i],1});
		}
		else{
			int a,b,c; 
			tie(a,b,c)=pq.top();
			pq.pop();
			ans[a]=i+1;
			pq.push({G[b][c+1],b,c+1});
		}
	}
	vec_out(ans);
}