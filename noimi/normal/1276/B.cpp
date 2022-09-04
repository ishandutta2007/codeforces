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
//#define pq priority_queue<int>
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


const ll MOD=1e9+7;
const int N=500000;
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
main(){
    int t=in();
    while(t--){
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        UnionFind uf(n+1);
        vecpii t;
        rep(i,m){
            int p,q;cin>>p>>q;
            if(p!=a&&p!=b&&q!=a&&q!=b){
                uf.unite(p,q);
            }
            else t.emplace_back(p,q);
        }
        vecpii mem(n+1);
        for(auto e:t){
            if(e.second==b)swap(e.first,e.second);
            if(e.second==a)swap(e.first,e.second);
            if(e.second==b)continue;
            if(e.first==a){
                mem[uf.find(e.second)].first++;
            }
            else mem[uf.find(e.second)].second++;
        }
        ll A=0,B=0;
        rep(i,n+1){
            if(mem[i].first&&!mem[i].second) A+=uf.size(i);
            else if(mem[i].second&&!mem[i].first)B+=uf.size(i);
        }
        cout<<A*B<<endl;
    }
    
}