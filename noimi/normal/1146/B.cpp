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
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
#define MAX_V 400010
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

#define INF 1e9+7
#define LLINF 1e18+7
ll MOD=998244353;
#define N 110000

main(){
    string s;cin>>s;
    int b=0;
    rep(i,s.size()){
        if(s[i]!='a')b++;
    }
    if(b%2){
        cout<<":(";return 0;
    }
    b/=2;
    vector <char> t;
    rep(i,s.size()-b){
        t.pb(s[i]);
    }
    int aa=t.size();
    rep(i,aa){
        if(t[i]!='a')t.pb(t[i]);
    }
    bool flag=true;
    rep(i,s.size()){
        if(s[i]!=t[i]){
            flag=false;
        }
    }
    if(flag){
        rep(i,s.size()-b){
            cout<<s[i];
        }
    }
    else cout<<":(";
}