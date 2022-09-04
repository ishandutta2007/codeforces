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


#define INF 1e9+7
#define LLINF 1e18+7
#define N 250000

const ll MOD=1e9+7;

main(){
    int T=in();
    vector<char> v;
    rep(i,10){
        v.pb('0'+i);
    }
    rep(i,26){
      v.pb('a'+i);
      v.pb('A'+i);
    }
    rep(iii,T){
        int r=in(),c=in(),k=in();
        vector<string> s;
        rep(i,r){
          string S;cin>>S;
          s.pb(S);
        }
        int now=0,cnt=0;
        rep(i,r)rep(j,c)if(s[i][j]=='R')cnt++;
        int t=cnt/k;
        vec size;
        rep(i,cnt%k)size.pb(t+1);
        rep(i,k-cnt%k)size.pb(t);
        cnt=0;
        vector<string> ans(r,string(c,'0'));
        rep(i,r){
          
          if(i&1){
            rep3(j,c-1,0){
              ans[i][j]=v[now];
              if(s[i][j]=='R')cnt++;
              if(cnt==size[now]){
                cnt=0;now++;
                now=min(k-1,now);
              }
            }
          }
          else{
            rep(j,c){
              ans[i][j]=v[now];
              if(s[i][j]=='R')cnt++;
              if(cnt==size[now]){
                cnt=0;now++;
                now=min(k-1,now);
              }
            }
          }
        }
        rep(i,r){
          cout<<ans[i]<<endl;
        }
    }
}