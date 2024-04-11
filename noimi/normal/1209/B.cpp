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
struct UnionFind{
    vector<int> par,sizes;
    UnionFind(int n):par(n+1),sizes(n+1,1){
        rep2(i,1,n)par[i]=i;
    }
    int find(int x){
        return (x==par[x]?x:par[x]=find(par[x]));
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return ;
        if(sizes[x]<sizes[y]){
            swap(x,y);
        }
        par[y]=x;
        sizes[x]+=sizes[y];
    }
    bool same(int x,int y) {return (find(x)==find(y));}
    int size(int x) {return sizes[find(x)];}
};
int gcd(int x,int y){
    if(x==0)return y;
    else{
        return gcd(y%x,x);
    }
}
main(){
    int n=in();
    string s;
    cin>>s;
    vec lamp(n);
    rep(i,n){
        if(s[i]=='1')lamp[i]=1;
    }
    int M=0;
    vec a,b;
    rep(i,n){
        a.pb(in());b.pb(in());
    }
    rep(i,5000){
        int t=0;
        rep(j,n){
            if(i>=b[j]&&(i-b[j])%a[j]==0){
                lamp[j]=1-lamp[j];
            }
            t+=lamp[j];
        }
        M=max(t,M);
    }
    cout<<M<<endl;
}