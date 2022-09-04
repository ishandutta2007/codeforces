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
#define pb emplace_back
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


const ll MOD=998244353;
const int N=510000;

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
    vec a;
    rep(i,n)a.pb(in()-1);
    vec inv(n);
    rep(i,n){
        inv[a[i]]=i;
    }
    vecll ans(n);
    ll tmp=0;
    BIT<ll> bit(n);
    rep(i,n){
        tmp+=bit.sum(inv[i]);
        bit.add(inv[i],1);
        ans[i]=i*(i+1)/2-tmp;
    }
    // print(ans);
    ll l=inv[0],r=inv[0];
    BIT<ll> b(n),c1(n),c2(n);
    rep(i,n){
        l=min((int)l,inv[i]),r=max((int)r,inv[i]);
        int L=l-1,R=r+1;
        int k;
        int left,right;
        if(i&1){
            k=(i+1)/2;
            while(L<R-1){
                int mid=(L+R)/2;
                if(b.sum(mid)<k)L=mid;
                else R=mid;
            }
            if(R>inv[i]){
                left=inv[i],right=L;
            }
            else{
                left=R+1,right=inv[i];
            }
            b.add(inv[i],1);
        }
        else{
            b.add(inv[i],1);
            k=(i+2)/2;
            while(L<R-1){
                int mid=(L+R)/2;
                if(b.sum(mid)<k)L=mid;
                else R=mid;
            }
            left=min(R,inv[i]),right=max(R,inv[i]);
            // left=inv[i],right=R;
        }
        // cout<<left<<" "<<right<<endl;
        c1.add(left,-(left-1));
        c2.add(left,1);
        c1.add(right+1,right);
        c2.add(right+1,-1);
        // cout<<"sum:"<<c1.sum(r)+c2.sum(r)*r<<endl;
        // cout<<"sum:"<< (i+2)/2 * ((i+3)/2)<<endl;
        ll sum=c1.sum(r)+c2.sum(r)*r - (i+2)/2 * ((i+3)/2);
        cout<<ans[i]+sum<<" ";
    }
}