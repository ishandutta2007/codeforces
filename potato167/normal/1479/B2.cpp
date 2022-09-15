#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
ll I=1167167167167167167;
ll Q=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end());reverse(v.begin(),v.end());}

int main() {
	ll N;
    cin>>N;
    vector<ll> p={0};
    ll k=0;
    rep(i,N){
        ll a;
        cin>>a;
        if(p[k]!=a) p.push_back(a),k++;
    }
    vector<ll> q(N+1,-1),dp(k+1),r(k,-1);
    rep(i,k+1){
        if(q[p[i]]!=-1) r[q[p[i]]]=i;
        q[p[i]]=i;
    }
    rep(i,k){
        if(r[i]!=-1) chmax(dp[r[i]-1],dp[i]+1);
        chmax(dp[i+1],dp[i]);
    }
    cout<<k-dp[k]<<endl;
}