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


#define LLINF 1e18+7
#define N 250000
ll MOD=998244353;

main(){
    int q=in();
    rep(iii,q){
        int n=in();
        vecll p;
        rep(i,n){
            p.pb(lin());
        }
        ll x=in(),a=in(),y=in(),b=in();
        ll K=lin();
        int l=0,r=n+1;
        sort(all(p),greater<ll>());
        while(l<r-1){
            ll k=K;
            vector<ll> pr;
            int mid=(l+r)/2;
            rep(i,mid){
                ll t=0;
                if((i+1)%a==0)t+=x;
                if((i+1)%b==0)t+=y;
                pr.pb(t);
            }
            sort(all(pr),greater<ll>());
            rep(i,mid){
                k-=pr[i]*p[i]/100;
                //cout<<k<<endl;
            }
            if(k>0)
            l=mid;
            else
            r=mid;
        }
        if(r==n+1)cout<<-1;
        else cout<<r;
        cout<<endl;
    }
}