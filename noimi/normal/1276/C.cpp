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
//#define pq priority_queue<int>
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
 
 
const ll MOD=1e9+7;
const int N=500000;
 
main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n=in();
    map<int,int> mp;
    rep(i,n){
        mp[in()]++;
    }
    vecpii a;
    for(auto e:mp)a.pb({e.second,e.first});
    sort(all(a));
    int ans=0,now=n;
    int l=0,rr=2000;
    while(l<rr-1){
        int mid=(l+rr)/2;
        if(mid*mid>n)rr=mid;
        else l=mid;
    }
    vec r={a[0].first};
    rep(i,a.size()-1){
        r.pb(r.back()+a[i+1].first);
    }
    int s;
    rep2(i,1,l){
        int t=upper_bound(all(a),pii{i,0})-a.begin();
        int sum=(t?r[t-1] : 0)+(a.size()-t)*i;
        int tmp=(sum/i)*i;
        if(sum/i<i)continue;
        if(ans<tmp){
            ans=tmp;s=i;
        }
    }
    vector<vec> mat(s,vec(ans/s));
    vec t;
    rep2(i,0,a.size()-1){
        int T=min(a[i].first,s);
        rep(j,T)t.pb(a[i].second);
    }
    rep(j,ans/s){
        rep(i,s){
            mat[i][(j+i)%(ans/s)]=t.back();
            t.pop_back();
        }
    }
    cout<<ans<<endl;
    cout<<s<<" "<<ans/s<<endl;
    rep(i,s){
        rep(j,ans/s){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}