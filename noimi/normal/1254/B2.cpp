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
    int n;
    vecll a;
    n=in();
    rep(i,n){
        a.pb(in());
    }
    ll int sum=0;
    rep(i,n){
        sum+=a[i];
    }
    ll int Sum=sum;
    ll ans=LLINF;
    for(ll int i=2;i*i<=sum;i++){
        if(sum%i==0){
            while(sum%i==0)sum/=i;
            ll pre=0;
            ll start=0;
            ll res=a[0]%i;
            ll mid;
            ll tmp=0;
            ll tmpans=0;
            bool flag=true;
            rep(now,n){
                // cout<<i<<" "<<tmp<<endl;
                tmp+=a[now]%i-pre;
                pre=0;
                if(tmp>=(i+1)/2&&flag){
                    mid=now;
                    flag=0;
                }
                if(tmp>=i){
                    // cout<<" "<<mid<<" "<<now<<endl;
                    tmpans+=(ll)(mid-start)*res;
                    rep2(j,start+1,now-1){
                        tmpans+=(ll)abs(mid-j)*(a[j]%i);
                    }
                    tmpans+=(ll)(now-mid)*(a[now]%i+i-tmp);
                    res=tmp-i;pre=a[now]%i-res;
                    now--;
                    start=now+1;
                    flag=1;
                    tmp=0;
                }
            }
            ans=min(ans,tmpans);
        }
    }
    ll i=sum;
    if(sum!=1){
        ll pre=0;
            ll start=0;
            ll res=a[0]%i;
            ll mid;
            ll tmp=0;
            ll tmpans=0;
            bool flag=true;
            rep(now,n){
                tmp+=a[now]%i-pre;
                pre=0;
                if(flag&&tmp>=(i+1)/2){
                    mid=now;
                    flag=0;
                }
                if(tmp>=i){
                    tmpans+=(ll)(mid-start)*res;
                    rep2(j,start+1,now-1){
                        tmpans+=(ll)abs(mid-j)*(a[j]%i);
                    }
                    tmpans+=(ll)(now-mid)*(a[now]%i+i-tmp);
                    res=tmp-i;pre=a[now]%i-res;
                    now--;
                    start=now+1;
                    tmp=0;
                    flag=true;
                }
            }
            ans=min(ans,tmpans);
    }
    if(ans==LLINF){
        cout<<-1;return 0;
    }
    cout<<ans;
}