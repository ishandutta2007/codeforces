#pragma GCC optimize("O3")
#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <deque>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <chrono>
#include <random>
#include <time.h>
#include <fstream>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pb push_back
#define eb emplace_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vec2 vector<vec>
#define vecll2 vector<vecll>
#define vec3 vector<vec2d>
#define vecll3 vector<vecll2d>
#define fi first
#define se second
#define endl "\n"
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(vector<T> v){for(T e:v)cout<<e<<" ";cout<<endl;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
void print(vector<vec> v){for(auto e:v){for(auto ee:e)cout<<ee<<" ";cout<<endl;}}
void print(map<int,int> mp){for(auto e:mp)cout<<e.first<<" "<<e.second<<endl;cout<<endl;}


struct sq{
    int a,b,c,d;
};
bool solve(vector<sq> v){
    sort(all(v),[](sq x,sq y){
        return x.d < y.d;
    });
    vector<pii> s;
    for(auto e:v){
        int a=e.a,b=e.b,c=e.c,d=e.d;
        auto it=lower_bound(all(s),pii{a,-INT_MAX});
        if(it!=s.begin()){
            it--;
            if( (*it).se >= c) return false;
        }
        int n=s.size();
        rep3(i,n-1,0){
            if(s[i].first < b) break;
            else s.pop_back();
        }
        s.eb(b,d);
    }
    return true;
}
main(){
    ios
    int n; cin>>n;
    vector<sq> v[4];
    rep(i,n){
        int a,b,c,d;cin >>a>>b>>c>>d;
        v[0].pb(sq{a,b,c,d});
        v[1].pb(sq{-b,-a,c,d});
        v[2].pb(sq{c,d,a,b});
        v[3].pb(sq{-d,-c,a,b});
    }
    bool flag=1;
    rep(i,4) flag&=solve(v[i]);
    cout << (flag ? "YES\n" : "NO\n");
    return 0;
}