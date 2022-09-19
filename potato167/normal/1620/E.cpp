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
const int INF=1000000000;
const ll mod=1e9+7;
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
struct UFtree
{
	std::vector<int> wei;
	std::vector<int> q;
	int component;
	UFtree(int n):par(n),wei(n),component(n){
		for(int i=0;i<n;i++){
			wei[i]=1,par[i]=i;
		}
	}
	void intialize(){
		for(auto x:q){
			wei[root(x)]=1;
			par[x]=x;
		}
		component=(int)par.size();
		q={};
	}
	//
	int root(int a){
		if(a==par[a]) return a;
		return par[a]=root(par[a]);
	}
	//true1,false0
	int same(int a,int b){
		if(root(a)==root(b)) return 1;
		else return 0;
	}
	//a,b,true
	bool unite(int a,int b){
		a=root(a),b=root(b);
		if(a==b) return false;
		par[b]=a;
		q.push_back(b);
		wei[a]+=wei[b];
		component--;
		return true;
	}
	private:
	std::vector<int> par;
};
}
using po167::UFtree;


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
    int n,M=5e5+4;
	cin>>n;
	UFtree T(n);
	vector<tuple<int,int,int>> p(n);
	rep(i,n){
		int a,b;
		cin>>a>>b;
		int c=-1;
		if(a==2) cin>>c;
		p[i]={a,b,c};
	}
	vector<int> q;
	vector<int> ore(M,-1);
	rep(i,n){
		int t,x,y;
		tie(t,x,y)=p[i];
		//cout<<t<<" "<<x<<" "<<y<<endl;
		if(t==1){
			q.push_back(i);
			if(ore[x]==-1){
				ore[x]=i;
			}else{
				T.unite(ore[x],i);
			}
		}else{
			if(x==y) continue;
			if(ore[x]!=-1){
				if(ore[y]!=-1){
					T.unite(ore[x],ore[y]);
				}
				ore[y]=ore[x];
				ore[x]=-1;
			}
		}
	}
	vector<int> rev(n,-1);
	rep(i,M){
		if(ore[i]!=-1) rev[ore[i]]=i;
	}
	rep(i,q.size()){
		if(i) cout<<" ";
		cout<<rev[T.root(q[i])];
		//cout<<" "<<T.root(i);
	}
	cout<<"\n";
}