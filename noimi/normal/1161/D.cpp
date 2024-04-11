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
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
#define MAX_V 400010
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

#define INF 1e9+7
#define LLINF 1e18+7
#define N 310000
ll MOD=998244353;
ll inv[N];

vector<vec> G(N);
main(){
    inv[2]=499122177ll;
    string ss;
    cin>>ss;
    int m=ss.size();
    vec s;
    rep(i,m){
        if(ss[i]=='1')s.pb(1);
        else if(ss[i]=='0')s.pb(0);
        else s.pb(-1);
    }
    if(s[m-1]==1){
        cout<<0;return 0;
    }
    s[m-1]=0;
    ll ans=0;
    rep2(i,1,m-1){
        int sta=0;
        ll preans=1;
        int pre=1;
        int now;
        vec used(m,0);
        rep(j,(m+1)/2){
            sta=0;
            if(used[j])continue;
            //cout<<" "<<i<<" "<<j<<endl;
            if(s[j]==-1){
                sta=1;
                preans=preans*2ll%MOD;
            }
            else now=s[j];
            int pos=m-j-1;
            //cout<<pos<<" "<<preans<<endl;
            used[j]=1;
            if(pos<i){
                if(sta){
                    if(s[pos]!=-1)preans=preans*inv[2]%MOD;
                }
                else{
                    if(s[pos]!=-1&&now!=s[pos])preans=0;
                }
                used[pos]=1;
                continue;
            }
            else while(1){
                if(pos<i){
                    if(sta){
                        if(s[pos]!=-1)preans=preans*inv[2]%MOD;
                    }
                    else{
                        if(s[pos]!=-1&&now!=s[pos])preans=0;
                    }
                    //cout<<pos<<" "<<preans<<endl;
                    used[pos]=1;break;
                }
                if(s[pos]==-1){
                    if(m-1-pos!=pos)
                    preans=preans*2ll%MOD;
                    sta=1;
                }
                else now=now^s[pos];
                //cout<<pos<<" "<<preans<<endl;
                used[pos]=1;
                pos=i+m-1-pos;
                if(pos<i){
                    if(sta){
                        if(s[pos]!=-1)preans=preans*inv[2]%MOD;
                    }
                    else{
                        if(s[pos]!=-1&&now!=s[pos])preans=0;
                    }
                    used[pos]=1;break;
                }
                else if(pos==i+m-1)break;
                if(used[pos])break;
                if(s[pos]==-1){
                    preans=preans*2ll%MOD;
                    sta=1;
                }
                else now=now^s[pos];
                used[pos]=1;
                //cout<<pos<<" "<<preans<<endl;
                pos=m-1-pos;
                if(pos==m-1-pos)break;
                //cout<<pos<<" "<<preans<<endl;
            }
        }
        ans=(ans+preans)%MOD;
        //cout<<ans<<endl;
    }
    cout<<ans;
}