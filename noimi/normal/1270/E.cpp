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
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define eb emplace_back
#define ep emplace
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define fi first
#define se second
#define endl "\n"
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
void print(vec v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(vecll v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(vector<vec> v){for(auto e:v){for(auto ee:e)cout<<ee<<" ";cout<<endl;}}
void print(map<int,int> mp){for(auto e:mp)cout<<e.first<<" "<<e.second<<endl;cout<<endl;}

pii ask(vec v){
    for(auto e:v){
        cout<<e<<" ";
    }
    cout<<endl;
    cout.flush();
    int a,b;cin>>a>>b;
    return {a,b};
}
main(){
    // ios
    int t=1;
    while(t--){
        int n=in();
        vec x,y;
        int xx=in();int yy=in();
        x.pb(0),y.pb(0);
        rep(i,n-1)x.pb(in()-xx),y.pb(in()-yy);
        while(1){
            vec ans;
            rep(i,n){
                if((x[i]+y[i])%2!=0){
                    ans.pb(i+1);
                }
            }
            if(ans.size()){
                cout<<ans.size()<<endl;
                for(auto e:ans)cout<<e<<" ";
                return 0;
            }
            else{
                rep(i,n){
                    x[i]=(x[i]+y[i])/2;
                    y[i]=x[i]-y[i];
                }
            }
        }
    }
}