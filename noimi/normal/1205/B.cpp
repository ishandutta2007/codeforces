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

vector<vec> G;
main(){

    ll t=0;
    int n=in();
    G.resize(n+1);
    vecll v;
    rep(i,n)v.pb(lin());
    vec c;
    rep(i,64){
        int cnt=0;
        ll T=(1ll)<<i;
        vec s;
        rep(j,n){
            ll x=v[j];
            if(x&T){cnt++;s.pb(j);}
        }
        if(cnt>=3){
            cout<<3<<endl;
            return 0;
        }
        else if(cnt==2){
            G[s[0]].pb(s[1]);
            G[s[1]].pb(s[0]);
            c.pb(s[0]);
            c.pb(s[1]);
        }
    }
    sort(all(c));
    c.erase(unique(all(c)),c.end());
    rep2(i,0,n-1){
        sort(all(G[i]));
        G[i].erase(unique(all(G[i])),G[i].end());
    }
    ll ans=INF;
    for(auto e:c){
        vec visited(n+1,INF);
        vector<pii> d={{e,0}};
        rep(iii,65){
            vector<pii> D;
            bool flag=false;
            for(auto x:d){
                for(auto z:G[x.first]){
                    if(z!=x.second){
                        if(z==e){
                            flag=true;
                            ans=min(iii+1ll,ans);
                        }
                        D.pb(pii(z,x.first));
                    }
                }
            }
            d=D;
            if(flag)break;
        }
        
    }
    cout<<(ans==INF?-1:ans)<<endl;
}