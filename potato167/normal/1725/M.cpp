#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=2167167167167167167;
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
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}
template<class T> T min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
template<class T> T max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}

using len_type=ll;
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
// oddloop
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	int N,M;
	cin>>N>>M;
	vector<vector<edge>> G(N*2);
	rep(i,M){
		int a,b;ll c;
		cin>>a>>b>>c;
		a--,b--;
		G[a].push_back({b,c});
		G[b+N].push_back({a+N,c});
	}
	rep(i,N){
		G[i].push_back({(int)i+N,0});
	}
	auto seen=dijkstra(G,0,ILL);
	rep(i,N-1){
		if(i) cout<<" ";
		if(seen[i+1+N]==ILL) cout<<"-1";
		else cout<<seen[i+N+1];
	}
	cout<<"\n";
}