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
#include <deque>
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
void print(vec v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(vecll v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(map<int,int> mp){for(auto e:mp)cout<<e.first<<" "<<e.second<<endl;cout<<endl;}
void print(pll p) {cout<<"("<<p.first<<","<<p.second<<")"<<endl;}
void print(pii p) {cout<<"("<<p.first<<","<<p.second<<")"<<endl;}


int n; vec a;
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
    n=in();
    rep(i,n)a.pb(in());
    int q=in();
    vec ans(q);
    vector<pair<pii,int>> v;
    rep(i,q){
        int a=in(),b=in();
        v.pb({{a,b},i});
    }
    sort(all(v));
    vecpii id;
    rep(i,n){
        id.pb({a[i],-i});
    }
    sort(all(id),greater<pii>());
    int cnt=0;
    BIT<int> bit(n+1);
    for(auto e:v){
        int num=e.second;
        int k=e.first.first,pos=e.first.second;
        while(cnt<k){
            bit.add(-id[cnt].second,1);
            cnt++;
        }
        int l=-1,r=n-1;
        while(l<r-1){
            int mid=(l+r)/2;
            if(bit.sum(mid)>=pos)r=mid;
            else l=mid;
        }
        ans[num]=a[r];
    }
    for(auto e:ans){
        cout<<e<<endl;
    }
}