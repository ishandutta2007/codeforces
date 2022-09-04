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
ll MOD=1e9+7;
#define N 310000
ll a[N],b[N],rui[N];
int main(){
    int n=in();
    rep(i,n)a[i]=lin();
    sort(a,a+n);
    rep(i,n-1){
        b[i]=a[i+1]-a[i]-1;
    }
    sort(b,b+(n-1),greater<ll>());
    rui[0]=b[0];
    rep(i,n-1){
        rui[i+1]=rui[i]+b[i+1];
    }
    int q=in();
    rep(i,q){
        ll l=lin(),r=lin();
        ll ans=a[n-1]-a[0]+1+r-l;
        ll left=0,right=n+1;
        ll c=r-l;
        while(left<right-1){
            int mid=(left+right+1)/2;
            if(b[mid-1]<=c)right=mid;
            else left=mid;
        }
        if(left!=0ll)
        ans=ans-rui[left-1]+c*left;
        cout<<ans<<" ";
    }
}