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
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
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
template<typename A, size_t NNN, typename T>
void Fill(A (&array)[NNN], const T &val){
    fill( (T*)array, (T*)(array+NNN), val );
}
#define INF 1e9+7
#define LLINF 1e18+7
ll MOD=998244353;
#define N 510000
ll n,m,k;
int dp[20][8000];
int a[100];
int main(){
    n=in();
    rep(i,n)a[i]=in();
    dp[0][4000]=1;
    rep(i,n){
        rep2(j,1000,7000){
            dp[i+1][j-a[i]]+=dp[i][j];
            dp[i+1][j+a[i]]+=dp[i][j];
        }
    }
    bool flag=false;
    rep2(i,-10,10){
        if(dp[n][4000+360*i])flag=true;
    }
    cout<<(flag?"YES":"NO");
    return 0;
}