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
#define setp(n) setprecision(n)<<fixed
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
void print(vec v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(map<int,int> mp){for(auto e:mp)cout<<e.first<<" "<<e.second<<endl;cout<<endl;}


#define INF 1e9+7
#define LLINF 1e18+7
#define N 250000
ll MOD=1e9+7;


bool f(ll n,ll k){
    bool flag=true;
    if(n<1)return false;
    if(n<k)flag=false;
    int cnt=0;
    while(n){
        cnt+=n&1;
        n>>=1;
    }
    // cout<<n<<" "<<cnt<<" "<<k<<endl;
    if(cnt>k)flag=false;
    return flag;
}
main(){
    ll n=in(),p=in();
    ll now=1;
    while(1){
        if(f(n-now*p,now)){
            cout<<now<<endl;
            return 0;
        }
        if(n-now*p<=0){
            cout<<-1;return 0;
        }
        now++;
    }
}