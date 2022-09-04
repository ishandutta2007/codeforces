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
#define setp(n) setprecision(n)<<fixed
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
void print(vec v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(map<int,int> mp){for(auto e:mp)cout<<e.first<<" "<<e.second<<endl;cout<<endl;}


#define INF 1e9+7
#define LLINF 1e18+7
#define N 250000
ll MOD=1e9+7;


main(){
    int n=in(),k=in();
    if(k==2){
        map<int,int> m1,mp;
        rep(i,n){
            int a=in();
            m1[a]+=1;
        }
        for(auto E:m1){
            int e=E.first;
            int a=1;
            for(int i=2;i*i<=e;i++){
                if(e%i==0){
                    int j=1;
                    rep(iii,k){
                        j*=i;
                        if(j>1e5)break;
                    }
                    while(e%j==0)e/=j;
                }
            }
            mp[e]+=E.second;
        }
        ll ans=0;
        for(auto e:mp){
            ans+=(ll)e.second*(ll)(e.second-1)/2;

        }
        cout<<ans<<endl;
    }
    else{
        vecll v;
        rep2(i,1,INF){
            ll t=1;
            rep(j,k)t*=i;
            if(t<=1e10)v.pb(t);
            else break;
        }
        map<int,int> mp;
        rep(i,n){
            mp[in()]+=1;
        }
        ll ans=0;
        for(auto e:mp){
            // cout<<e.first<<" "<<e.second<<endl;
            int a=e.first;
            for(auto m:v){
                if(m/a>1e5)break;
                if(m%a==0){
                    if(a!=m/a)
                    ans+=(ll)e.second*(ll)mp[m/a];
                    else
                    ans+=(ll)e.second*(ll)(e.second-1);
                }
            }
        }
        cout<<ans/2;
    }
}