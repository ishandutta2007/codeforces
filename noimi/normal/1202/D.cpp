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

#define INF 1e9+7
#define LLINF 1e18+7
#define N 250000
ll MOD=1e9+7;



main(){
    int T=in();
    vec a;
    a.pb(1);
    rep2(i,2,100000){
        a.pb(a[a.size()-1]+i);
    }
    rep(iii,T){
        int n=in();
        int t=upper_bound(all(a),n)-a.begin();
        vec ans;
        rep3(i,t-1,0){
            while(n>=a[i]){
                n-=a[i];ans.pb(7);
            }
            ans.pb(3);
        }
        ans.pb(3);ans.pb(1);
        rep3(i,ans.size()-1,0){
            cout<<ans[i];
        }
        cout<<endl;
    }
}