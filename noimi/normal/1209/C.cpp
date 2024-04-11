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
    int T=in();
    rep(iii,T){
        int n=in();
        string d;
        cin>>d;
        vec v;
        rep(i,n){
            v.pb((int)(d[i]-'0'));
        }
        bool pos=false;
        rep(s,10){
            vec t(n);
            bool two=true;
            rep(i,n){
                if(v[i]>s){
                    t[i]=2;
                    two=0;
                }
                else if(v[i]==s&&two){
                    t[i]=2;
                }
                else t[i]=1;
            }
            vec cnt;
            rep(i,n){
                if(t[i]==1)cnt.pb(v[i]);
            }
            rep(i,n){if(t[i]==2)cnt.pb(v[i]);}
            bool inc=true;
            rep(i,n-1)if(cnt[i]>cnt[i+1])inc=false;
            if(inc){
                rep(i,n)cout<<t[i];
                cout<<endl;
                pos=true;
                break;
            }
        }
        if(!pos)cout<<'-'<<endl;
    }
}