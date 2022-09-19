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
	ll n,k;
    cin>>n>>k;
    vector<vector<int>> G(n);
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int leaf=0;
    vector<int> order={0},pare(n,-2);
    pare[0]=-1;
    rep(i,n){
        int a=order[i];
        for(auto x:G[a]){
            if(pare[x]==-2){
                pare[x]=a;
                order.push_back(x);
            }
        }
        if(i!=0&&G[a].size()==1) leaf++;
    }
    priority_queue<int> pq;
    vector<int> dp(n,-1);
    rep(i,n){
        int a=order[n-1-i];
        for(auto x:G[a]){
            if(x!=pare[a]){
                if(dp[a]==-1){
                    dp[a]=dp[x];
                }else{
                    pq.push(min(dp[a],dp[x]));
                    chmax(dp[a],dp[x]);
                }
            }
        }
        if(dp[a]==-1) leaf--,dp[a]=0;
        dp[a]++;
    }
    assert(leaf==0);
    pq.push(dp[0]);
    ll ans=-ILL;
    ll blue=n;
    rep(i,k+1){
        if(i==0) continue;
        if(pq.empty()){
            for(ll j=i;j<=k;j++){
                chmax(ans,j*(n-j));
            }
            break;
        }
        blue-=pq.top();
        pq.pop();
        ll tmp=blue;
        if(blue>=n/2) tmp=n/2;
        chmax(ans,i*(n-i)+tmp*(tmp-n));
    }
    cout<<ans<<"\n";
}