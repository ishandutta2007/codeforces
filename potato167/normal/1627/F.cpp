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
#define rep(i,a) for (int i=0;i<a;i++)
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
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n,k;
	cin>>n>>k;
	vector<vector<int>> p(k-1,vector<int>(k));
	vector<vector<int>> q(k,vector<int>(k-1));
	rep(i,n){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a--,b--,c--,d--;
		if(a==c){
			q[a][min(b,d)]++;
		}else{
			p[min(a,c)][b]++;
		}
	}
	vector<vector<edge>> G((k+1)*(k+1));
	rep(i,k-1) rep(j,k){
		int tmp=p[i][j]+p[k-2-i][k-1-j];
		G[(i+1)*(k+1)+j].push_back({(i+1)*(k+1)+j+1,tmp});
		G[(i+1)*(k+1)+j+1].push_back({(i+1)*(k+1)+j,tmp});
	}
	rep(i,k) rep(j,k-1){
		int tmp=q[i][j]+q[k-i-1][k-j-2];
		G[i*(k+1)+j+1].push_back({(i+1)*(k+1)+j+1,tmp});
		G[(i+1)*(k+1)+j+1].push_back({i*(k+1)+1+j,tmp});
	}
	auto seen=dijkstra(G,((k+1)*(k+1))/2,INF);
	int ans=INF;
	rep(i,k+1) rep(j,k+1){
		if(i==0||i==k||j==0||j==k){
			chmin(ans,seen[i*(k+1)+j]);
		}
	}
	cout<<n-ans<<"\n";
}