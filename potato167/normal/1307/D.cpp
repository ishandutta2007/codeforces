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



using len_type=int;
struct edge{
    int to;
    len_type length;
};

len_type dijkstra_movement(edge e,int from,len_type t){
    return t+e.length;
}


vector<len_type> dijkstra(vector<vector<edge>> &G,int start,len_type inf){
    int M=G.size();
    assert(M>start&&start>=0);
    vector<len_type> seen(M,inf);
    seen[start]=0;
    priority_queue<pair<len_type,int>,vector<pair<len_type,int>>,greater<pair<len_type,int>>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        len_type time;
        int ver;
        tie(time,ver)=pq.top();
        pq.pop();
        if(seen[ver]<time) continue;
        for(edge x:G[ver]){
            len_type T=dijkstra_movement(x,ver,time);
            if(T<seen[x.to]){
                pq.push({T,x.to});
                seen[x.to]=T;
            }
        }
    }
    return seen;
}


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
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> sp(k);
	rep(i,k){
		cin>>sp[i];
		sp[i]--;
	}
	vector<vector<edge>> G(n);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].push_back({b,1});
		G[b].push_back({a,1});
	}
	auto seen1=dijkstra(G,0,INF);
	auto seen2=dijkstra(G,n-1,INF);
	int ans=0;
	vector<pair<int,int>> p(k);
	rep(i,k) p[i]={seen1[sp[i]],seen2[sp[i]]};
	So(p);
	int tmp=-INF;
	for(int i=k-1;i>=0;i--){
		chmax(ans,p[i].first+min(p[i].second,tmp)+1);
		chmax(tmp,p[i].second);
	}
	cout<<min(ans,seen2[0])<<"\n";
}