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
#define N 1100000
ll MOD=1e9+7;
 
int mat[1010][1010];
template<typename T>
struct BIT{
    vector<T> data;
 
    BIT(int size){
        data.assign(++size,0);
    }
    T sum(int k){
        T ret=0;
        for(++k;k>0;k-=k&-k)ret+=data[k];
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
ll ans[N];
main(){
    ll int n=lin();
    int w=lin();
    rep(iii,n){
        vector<ll> v;
        int m=in();
        rep(j,m){
            v.pb(lin());
        }
        ll M=-LLINF;
        int ttt=-1;
        rep(j,min(m,w-m+1)){
            M=max(M,v[j]);
            if(w-1-j>=m&&M<0)continue;
            ans[j]+=M;
            ans[j+1]-=M;
            ttt=j;
        }
        M=-LLINF;
        rep(j,min(m,w-m+1)){
            if(w-1-j==ttt)break;
            M=max(M,v[m-1-j]);
            if(w-1-j>=m&&M<0)continue;
            ans[w-1-j]+=M;
            ans[w-j]-=M;
        }
        //cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
        if(m*2<=w){
            if(M<0)continue;
            ans[m]+=M;
            ans[w-m]-=M;
        }
        else{
            vector<int> deq(m+1);
            int t=0,s=0;
            int k=w-m;
            rep2(i,1,k){
                while(t<s&&v[deq[s-1]]<v[i]){
                    s--;
                }
                deq[s]=i;
                s++;
            }
            rep2(i,k+1,m-2){
                while(t<s&&v[deq[s-1]]<v[i]){
                    s--;
                }
                deq[s]=i;
                s++;
                ans[i]+=v[deq[t]];ans[i+1]-=v[deq[t]];
                if(deq[t]==i-k)t++;
                if(s<t)s++;
            }
        }
    }
    cout<<ans[0]<<" ";
    rep2(i,1,w-1){
        ans[i]+=ans[i-1];
        cout<<ans[i]<<" ";
    }
}