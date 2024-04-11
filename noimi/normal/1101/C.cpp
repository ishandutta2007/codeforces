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
ll MOD=1e9+7;
#define N 505050

ll n,m;
ll p;
ll a[N];
int dp[N][10];
int ans[N];
int main(){
    int q=in();
    rep(iii,q){
        n=in();
        vector<pair<pii,int>> v;
        rep(i,n){
            v.pb({{in(),in()},i});
        }
        sort(ALL(v));
        bool flag=true;
        int mem=-1;
        int temp=-1;
        rep(i,n-1){
            temp=max(temp,v[i].first.second);
            if(temp<v[i+1].first.first){
                mem=i;
            }
        }
        if(mem==-1){
            cout<<-1<<endl;
        }
        else{
            rep(i,mem+1)ans[v[i].second]=1;
            rep2(j,mem+1,n-1){
                ans[v[j].second]=2;
            }
            rep(i,n){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}