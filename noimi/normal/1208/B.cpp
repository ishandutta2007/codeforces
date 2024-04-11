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


#define LLINF 1e18+7
#define N 250000
ll MOD=1e9+7;

main(){
    int n=in();
    vector<int> v;
    rep(i,n){
        v.pb(in());
    }
    int t=0;
    map<int,int> pre;
    int ans=n-1;
    while(1){
        map<int,int> back=pre;
        rep3(i,n-1,0){
            if(back[v[i]]){
                ans=min(ans,(int)i-t+1);
                break;
            }
            back[v[i]]=1;
        }
        if(pre[v[t]])break;
        pre[v[t]]=1;
        t++;
        if(t==n){
            ans=0;
            break;
        }
    }
    cout<<ans<<endl;
}