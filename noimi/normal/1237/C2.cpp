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

struct point{
    int x,y,z,id;
};

main(){
    int n=in();
    vector<point> v;
    rep(i,n){
        v.pb(point{in(),in(),in(),(int)i+1});
    }
    sort(all(v),[](point a,point b){
        if(a.x!=b.x)return a.x<b.x;
        if(a.y!=b.y)return a.y<b.y;
        return a.z<b.z;
    });
    vec used(n+1);
    rep(i,n-1){
        if(v[i].x==v[i+1].x&&v[i].y==v[i+1].y){
            cout<<v[i].id<<" "<<v[i+1].id<<endl;
            used[i]=used[i+1]=1;
            i++;
        }
    }
    rep(i,n){
        if(used[i])continue;
        int next=i+1;
        while(next<n&&used[next])next++;
        if(v[i].x==v[next].x){
            cout<<v[i].id<<" "<<v[next].id<<endl;
            used[i]=used[next]=1;
            i=next;
        }
        else i=next-1;
    }
    rep(i,n-1){
        if(used[i])continue;
        int next=i+1;
        while(next<n&&used[next])next++;
        cout<<v[i].id<<" "<<v[next].id<<endl;
        i=next;
    }
}