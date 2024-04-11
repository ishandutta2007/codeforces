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
    vector<ll> p(N);
    rep(i,N){
        cin>>p[i];
    }
    vector<vector<ll>> G;
    G.push_back({0,2});
    G.push_back({p[0],1});
    ll k=1;
    rep(i,N-1){
        if(p[i]==p[i+1]) G[k][1]=2;
        else G.push_back({p[i+1],1}),k++;
    }
    G.push_back({Q,2});
    k++;
    ll l=0,Z=0;
    while(l<k){
        if(G[l+1][1]==2) Z+=2,l++;
        else{
            ll r=l+2;
            while(G[r][1]==1) r++;
            if(G[l][0]!=G[r][0]) Z+=2;
            else{
                ll J=1,a=G[l][0];
                for(ll i=l;i<r;i++){
                    if(G[i][0]!=a&&G[i+1][0]!=a) J=2;
                }
                Z+=J;
            }
            Z+=r-l-1;
            l=r;
        }
    }
    cout<<Z-2<<endl;
}