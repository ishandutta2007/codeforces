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
ll MOD=998244353;

template< typename T >
size_t longest_increasing_subsequence(const vector< T > &a, bool strict) {
  vector< T > lis;
  for(auto &p : a) {
    typename vector< T >::iterator it;
    if(strict) it = lower_bound(begin(lis), end(lis), p);
    else it = upper_bound(begin(lis), end(lis), p);
    if(end(lis) == it) lis.emplace_back(p);
    else *it = p;
  }
  return lis.size();
}


main(){
    int Q=in();
    rep(ii,Q){
        int n=in();
        vector<int> v;
        rep(i,n){
            v.pb(in());
        }
        vec left(n+1,INF),right(n+1);
        rep(i,n){
            left[v[i]]=min(left[v[i]],(int)i);
            right[v[i]]=max(right[v[i]],(int)i);
        }
        int ans=0,tmp=0,pl=-1;
        int cnt=0;
        rep2(i,1,n){
            if(left[i]==INF)continue;
            cnt++;
            if(pl<left[i]){
                tmp++;
                pl=right[i];
            }
            else{
                tmp=1;
                pl=right[i];
            }
            //cout<<pl<<" "<<tmp<<endl;
            ans=max(ans,tmp);
        }
        cout<<cnt-ans<<endl;
    }

}