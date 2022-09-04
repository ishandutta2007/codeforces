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

main(){
    int n;cin>>n;
    vec a;
    rep(i,n){
        int x;cin>>x;a.pb(x);
    }
    int g=n/2,k=(n+1)/2;
    rep(i,n){
        if(a[i]){
            if(a[i]&1)k--;
            else g--;
        }
    }
    ll dp[110][110][2];
    rep(i,110)rep(j,110)rep(k,2)dp[i][j][k]=100000;
    dp[0][0][0]=dp[0][0][1]=0;
    int sum=g+k,cnt=0;
    rep(i,n){
        rep(j,n+1){
            if(a[i]){
                rep(k,2){
                    chmin(dp[i+1][j][(a[i]&1)],dp[i][j][k]+((a[i]&1)^(k&1)));
                }
            }
            else{
                rep(kk,2){
                    if(k-j<sum-cnt){
                        chmin(dp[i+1][j][0],dp[i][j][kk]+((kk&1)^0));
                    }
                    if(j<k){
                        chmin(dp[i+1][j+1][1],dp[i][j][kk]+((kk&1)^1));
                    }
                }
            }
        }
        if(!a[i])cnt++;
    }
    // cout<<dp[2][2][1]<<endl;
    ll ans=1e6;
    rep(j,2)chmin(ans,dp[n][k][j]);
    cout<<ans<<endl;
}