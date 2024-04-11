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

vector<int> t(2e5+10);

namespace po167{
struct UFtree
{
	std::vector<int> q;
	int component;
	UFtree(int n):par(n),component(n){
		for(int i=0;i<n;i++){
			par[i]=i;
		}
	}
	void intialize(){
		for(auto x:q){
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
		if(t[a]>t[b]) std::swap(a,b);
		par[b]=a;
		q.push_back(b);
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
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n,k;
    cin>>n>>k;
    map<int,vector<int>> mx,my;
    vector<int> x(n),y(n);
    rep(i,n){
        cin>>x[i]>>y[i]>>t[i];
        mx[x[i]].push_back(i);
        my[y[i]].push_back(i);
    }
    UFtree T(n);
    for(auto Z:mx){
        vector<int> p=Z.second;
        sort(p.begin(),p.end(),[&](int l,int r){
            return y[l]<y[r];
        });
        rep(i,(int)(p.size())-1){
            if(y[p[i+1]]-y[p[i]]<=k){
                T.unite(p[i],p[i+1]);
            }
        }
    }
    for(auto Z:my){
        vector<int> p=Z.second;
        sort(p.begin(),p.end(),[&](int l,int r){
            return x[l]<x[r];
        });
        rep(i,(int)(p.size())-1){
            if(x[p[i+1]]-x[p[i]]<=k){
                T.unite(p[i],p[i+1]);
            }
        }
    }
    vector<int> p;
    rep(i,n){
        if(T.root(i)==i){
            p.push_back(t[i]);
        }
    }
    So(p);
    int l=-1,r=p.size();
    int m=p.size();
    p.push_back(INF);
    //rep(i,m) cout<<p[i]<<" ";
    //cout<<endl;
    while(r-l>1){
        int med=(r+l)/2;
        int b=UB(p,med);
        if(b+med+1>=m){
            r=med;
        }else l=med;
    }
    cout<<r<<"\n";
}