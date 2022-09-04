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
#define pb emplace_back
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


const ll MOD=998244353;
const int N=500000;

main(){
    int n=in(),m=in();
    vector<ll> a(n+1);
    rep(i,m){
        int x=in(),y=in();
        ll c=lin();
        a[x]-=c;
        a[y]+=c;
    }
    vector<pair<int,ll>> p,q;
    rep2(i,1,n){
        // cout<<a[i]<<endl;
        if(a[i]>0)p.emplace_back(i,a[i]);
        else if(a[i]<0)q.pb(i,-a[i]);
    }
    int t1=0,t2=0;
    vector<ll> x,y,z;
    while(t1<p.size()&&t2<q.size()){
        if(p[t1].second<q[t2].second){
            q[t2].second-=p[t1].second;
            x.pb(p[t1].first);
            y.pb(q[t2].first);
            z.pb(p[t1].second);
            t1++;
        }
        else if(p[t1].second>q[t2].second){
            p[t1].second-=q[t2].second;
            x.pb(p[t1].first);
            y.pb(q[t2].first);
            z.pb(q[t2].second);
            t2++;
        }
        else{
            x.pb(p[t1].first);
            y.pb(q[t2].first);
            z.pb(q[t2].second);
            t1++;t2++;
        }
    }
    cout<<x.size()<<endl;
    rep(i,x.size()){
        cout<<y[i]<<" "<<x[i]<<" "<<z[i]<<endl;
    }
}