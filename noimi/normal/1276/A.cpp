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
 
main(){
    int t=in();
    while(t--){
        string s;cin>>s;
        int ans=0;
        if(s.size()<3){
            cout<<0<<endl<<endl;
            continue;
        }
        vec v;
        rep(i,s.size()-2){
            if(s.substr(i,3)=="one"){
                if(i>0&&s[i-1]!='o')
                v.pb(i+1);
                else 
                v.pb(i+2);
                ans++;
            }
            if(s.substr(i,3)=="two"){
                if(i+4<s.size()&&s.substr(i,5)=="twone")continue;
                ans++;
                v.pb(i+2);
            }
        }
        cout<<ans<<endl;
        print(v);
    }
    
}