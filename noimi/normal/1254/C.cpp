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
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define all(c) begin(c),end(c)
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
void print(vec v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(vecll v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(map<int,int> mp){for(auto e:mp)cout<<e.first<<" "<<e.second<<endl;cout<<endl;}


#define INF 1e9+7
#define LLINF 1e18+7
#define N 250000

const ll MOD=1e9+7;

ll ask1(int i,int j,int k){
    cout<<1<<" "<<i<<" "<<j<<" "<<k<<endl;
    cout.flush();
    ll res;cin>>res;
    return res;
}
int ask2(int i,int j,int k){
    cout<<2<<" "<<i<<" "<<j<<" "<<k<<endl;
    cout.flush();
    int res;cin>>res;
    return res;
}

main(){
    int n=in();
    deque<int> t1,t2,t3,t4;
    vector<pll> l,r;
    rep2(i,3,n){
        int res=ask2(1,2,i);
        ll size=ask1(1,2,i);
        if(res==1)r.pb({size,i});
        else l.pb({size,i});
    }
    ll m=0;int mem;
    rep(i,l.size()){
        m=max(m,l[i].first);
        if(m==l[i].first)mem=l[i].second;
    }
    // cout<<mem;

    sort(all(l));
    rep(i,l.size()){
        if(l[i].second==mem)continue;
        if(ask2(1,mem,l[i].second)==1){
            t2.push_front(l[i].second);
        }
        else{
            t1.push_back(l[i].second);
        }
    }
    // cout<<l.size()<<endl;
    if(l.size())
    t1.push_back(mem);
    m=0;
    rep(i,r.size()){
        m=max(m,r[i].first); if(m==r[i].first)mem=r[i].second;
    }
    sort(all(r));
    rep(i,r.size()){
        if(r[i].second==mem)continue;
        if(ask2(2,mem,r[i].second)==1){
            t4.push_front(r[i].second);
        }
        else{
            t3.push_back(r[i].second);
        }
    }
    if(r.size())
    t3.pb(mem);
    cout<<"0 1 ";
    for(auto e:t1)cout<<e<<" ";
    for(auto e:t2)cout<<e<<" ";
    cout<<"2 ";
    for(auto e:t3)cout<<e<<" ";
    for(auto e:t4)cout<<e<<" ";
    cout.flush();
}