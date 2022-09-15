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
struct UFtree
{
	std::vector<int> wei;
	std::vector<int> q;
	int component;
	UFtree(int n):wei(n),component(n),par(n){
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
		if(wei[a]<wei[b]) std::swap(a,b);
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
	vector<int> p(n),ans(n,-1);
	int ind=0;
	map<int,int> m;
	rep(i,n){
		cin>>p[i];
		if(m.count(p[i])){
			ans[ind]=i;
			ans[n-ind-1]=m[p[i]];
			m.erase(p[i]);
			ind++;
		}else m[p[i]]=i;
	}
	if(m.size()>1){
		yneos(0);
		return;
	}
	if(m.size()==1){
		int v=(*m.begin()).first;
		if(m[v]!=n/2){
			ans[n/2]=m[v];
		}
		rep(i,n/2){
			if(p[ans[i]]==v){
				ans[n/2]=ans[i];
				ans[i]=m[v];
				if(ans[n/2]==n/2){
					swap(ans[i],ans[n/2]);
				}
				break;
			}
		}
		if(ans[n/2]==-1){
			yneos(0);
			return;
		}
	}
	yneos(1);
	UFtree T(n);
	rep(i,n) T.unite(i,ans[i]);
	rep(i,n/2){
		if(T.same(i,n-1-i)==0){
			swap(ans[i],ans[n-i-1]);
			T.unite(i,n-1-i);
		}
	}
	//vec_out(ans);
	rep(i,n/2-1){
		if(T.same(0,i+1)==0){
			int tmp=ans[0];
			ans[0]=ans[i+1];
			ans[i+1]=ans[n-1];
			ans[n-1]=ans[n-2-i];
			ans[n-2-i]=tmp;
			T.unite(0,i+1);
		}
	}/*
	rep(i,n){
		cout<<p[ans[i]];
	}
	cout<<"\n";*/
	rep(i,n) ans[i]++;
	vec_out(ans);
}