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


const ll MOD=998244353;
const int N=500000;

void solve(){
    int n=in();
    vec p;
    rep(i,n){
        p.pb(in());
    }
    vec v;
    int cnt=1;
    rep(i,n){
        while(i<n-1&&p[i+1]==p[i]){i++;cnt++;}
        v.pb(cnt);cnt=1;
    }
    // print(v);
    vec w;
    int sum=0,now=0;
    while((sum+v[now])*2<=n){w.pb(v[now]);sum+=v[now];now++;}
    if(w.size()<3){
        cout<<0<<" "<<0<<" "<<0<<endl;
    }
    else{
        int g=w[0];
        now=1;
        int s=0,b=0;
        while(now<w.size()&& s<=g){s+=w[now];now++;}
        b=sum-g-s;
        if(b<=g || s<=g) cout<<0<<" "<<0<<" "<<0<<endl;
        else cout<<g<<" "<<s<<" "<<b<<endl;
    }
}
main(){
    int q=in();
    while(q--){
        solve();
    }
}