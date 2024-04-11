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


const ll MOD=998244353;
const int N=500000;

void no(){cout<<"NO";}
void solve(){
    int a=in(),b=in(),c=in(),d=in();
    if(abs(a-b+c-d)>1){
        no();return ;
    }
    int n=a+b+c+d;
    if((a+b+c+d)&1){
        if((a+c)>(b+d)){
            if(c-1<d && d) no();
            else{
                cout<<"YES\n";
                rep(i,n){
                    if(i&1){
                        if(d>0)cout<<3<<" ";
                        else cout<<1<<" ";
                        d--;
                    }
                    else{
                        if(c>0)cout<<2<<" ";
                        else cout<<0<<" ";
                        c--;
                    }
                }
            }
        }
        else{
            if(a>b-1 && a)no();
            else{
                cout<<"YES\n";
                rep(i,n){
                    if(i&1){
                        if(a>0)cout<<0<<" ";
                        else cout<<2<<" ";
                        a--;
                    }
                    else{
                        if(b>0)cout<<1<<" ";
                        else cout<<3<<" ";
                        b--;
                    }
                }
            }
        }
    }
    else{
        if(a>b && a)no();
        else{
            cout<<"YES\n";
            rep(i,n){
                if(i&1){
                    if(b>0)cout<<1<<" ";
                    else cout<<3<<" ";
                    b--;
                }
                else{
                    if(a>0)cout<<0<<" ";
                    else cout<<2<<" ";
                    a--;
                }
            }
        }
    }
}
main(){
    int q=1;
    while(q--){
        solve();
    }
}