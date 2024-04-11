#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=2167167167167167167;
const int INF=2100000000;
const ll mod=1e9+7;
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
	int n,m;
    cin>>n>>m;
    vector<vector<int>> G(n);
    int S,T;
    cin>>S>>T;
    S--,T--;
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> dis(n,INF);
    vector<ll> dp(n),dp1(n);
    dp[S]=1;
    dis[S]=0;
    queue<int> q;
    q.push(S);
    while(!q.empty()){
        int a=q.front();
        q.pop();
        if(a<n) q.push(a+n);
        for(auto x:G[a%n]){
            if(dis[x]==INF){
                dis[x]=dis[a]+1;
                dp[x]=dp[a];
                q.push(x);
            }else if(dis[x]==dis[a%n]+1+a/n){
                dp[x]=(dp[a]+dp[x])%mod;
            }else if(dis[x]==dis[a%n]+a/n){
                if(a<n){
                    dp1[x]=(dp1[x]+dp[a])%mod;
                }else{
                    dp1[x]=(dp1[x]+dp1[a-n])%mod;
                }
            }
        }
    }
    /*vec_out(dis);
    vec_out(dp);
    vec_out(dp1);*/
    cout<<(dp[T]+dp1[T])%mod<<"\n";
}