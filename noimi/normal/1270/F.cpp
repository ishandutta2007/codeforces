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
template<class T> inline void print(vector<T> v){for(T e:v)cout<<e<<" ";cout<<endl;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
void print(vector<vec> v){for(auto e:v){for(auto ee:e)cout<<ee<<" ";cout<<endl;}}
void print(map<int,int> mp){for(auto e:mp)cout<<e.first<<" "<<e.second<<endl;cout<<endl;}

const int T=120;
int _v[T*200000+1000];
auto v=_v+200100;
main(){
    ios
    string s;cin>>s;
    ll ans=0;
    // 010~T-1
    rep(i,T){
        int now=0;
        v[now]=1;
        int mi=0,ma=0;
        for(auto e:s){
            if(e=='0')now--;
            else now+=i;
            ans+=v[now];
            v[now]++;
            chmin(mi,now);chmax(ma,now);
        }
        rep2(j,mi,ma)v[j]=0;
    }
    vec ones;
    rep(i,s.size()){
        if(s[i]=='1')ones.pb(i);
    }
    ones.pb(s.size());
    int now=0;
    rep(i,s.size()){
        if(i>ones[now])now++;
        if(now==ones.size()-1)break;
        int cnt=0,p=now,ss=i;
        int z=0;
        while(cnt<=((int)s.size()-i)/T+1){
            int zz=(ones[p]-ss); ss=ones[p]+1;
            if(cnt){
                int l=(z+cnt-1)/cnt,r=(z+zz)/cnt;
                l=max(l,T);
                ans+=max(0,r-l+1);
            }
            cnt++;
            z+=zz;
            p++;
            if(p==ones.size())break;
        }
    }
    cout<<ans<<endl;
}