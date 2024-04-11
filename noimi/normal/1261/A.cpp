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
void print(pll p) {cout<<"("<<p.first<<","<<p.second<<")"<<endl;}
void print(pii p) {cout<<"("<<p.first<<","<<p.second<<")"<<endl;}

void solve(){
    int n=in(),k=in();
    string s;cin>>s;
    int l=0,r=0;
    int now=0;
    vecpii v;
    rep(i,k-1){
        while(s[l]!='(')l++;
        swap(s[now],s[l]);
        if(now!=l){
            v.pb({now+1,l+1});
        }
        now++;r=max(r,now);
        while(s[r]!=')')r++;
        swap(s[now],s[r]);
        if(now!=r){
            v.pb({now+1,r+1});
        }
        now++;l=max(l,now);
    }
    // cout<<now<<" "<<l<<endl;
    rep(i,n/2-k+1){
        while(s[l]!='(')l++;
        swap(s[now],s[l]);
        if(now!=l){
            v.pb({now+1,l+1});
        }
        now++;
        l=max(l,now);
    }
    cout<<v.size()<<endl;
    for(auto e:v){
        cout<<e.first<<" "<<e.second<<endl;
    }
}

main(){
    int q=in();
    while(q--)solve();
}