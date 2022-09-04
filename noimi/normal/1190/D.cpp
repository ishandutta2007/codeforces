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
    vector<pii> v;
    rep(i,n){
        int x=in(),y=in();
        v.pb({-y,x});
    }
    set<int> s;
    map<int,int> mp;
    vector<int> a;
    rep(i,n){
        a.pb(v[i].second);
    }
    sort(all(v));
    sort(all(a));
    a.erase(unique(all(a)),a.end());
    rep2(i,1,a.size()){
        mp[a[i-1]]=i;
    }
    rep(i,n){
        v[i].second=mp[v[i].second];
    }
    int pos=0;
    ll ans=0;
    BIT<ll> BIT(N);
    while(pos<n){
        int next=pos;
        vec t;
        t.pb(0);
        while(next<n&&v[pos].first==v[next].first){
            t.pb(v[next].second);
            next++;
        }
        t.pb(N);
        sort(all(t));
        rep(i,t.size()-1){
            ll T=BIT.sum(t[i+1]-1)-BIT.sum(t[i]);
            T=max(T,0ll);
            ans-=T*(T+1)/2;
        }
        rep2(i,1,t.size()-2){
            //cout<<t[i]<<" ";
            if(BIT.sum(t[i])-BIT.sum(t[i]-1)==0){
                BIT.add(t[i],1);
            }
        }
        //cout<<endl;
        ll S=BIT.sum(N);
        //cout<<ans<<endl;
        ans+=S*(S+1)/(ll)2;
        //cout<<ans<<endl;
        pos=next;
    }
    cout<<ans;
}