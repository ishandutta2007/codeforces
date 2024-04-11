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


template<typename T>
struct BIT{
    vector<T> data;

    BIT(int size){
        data.assign(++size,0);
    }
    T sum(int k){
        T ret=0;
        for(++k;k>0;k-=k&-k) ret+=data[k];
        return (ret);
    }
    void add(int k,T x){
        for(++k;k<data.size();k+=k&-k)data[k]+=x;
    }
};
/*

BIT(size) :size
sum(k) [0,k]
add(k,x) kx
*/

main(){
    int n=in();
    BIT<int> bit(n+1);
    vec a,b,inv(n+1);
    rep(i,n){
        a.pb(in());
    }
    rep(i,n){
        int x=in();
        b.pb(x);
        inv[x]=i+1;
    }
    int ans=0;
    rep3(i,n-1,0){
        int x=a[i];
        int y=inv[x];
        if(-bit.sum(y)+n-i-1<n-y)ans++;
        bit.add(y,1);
    }
    cout<<ans<<endl;
}