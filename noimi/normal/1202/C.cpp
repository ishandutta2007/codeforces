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
ll MOD=1e9+7;



main(){
    int T=in();
    rep(iii,T){
        string s;
        cin>>s;
        ll int r=0,d=0;
        ll int maxr=0,minr=0,maxd=0,mind=0;
        rep(i,s.size()){
            if(s[i]=='D')r++;
            if(s[i]=='S')d++;
            if(s[i]=='A')r--;
            if(s[i]=='W')d--;
            maxr=max(maxr,r);
            minr=min(minr,r);
            maxd=max(maxd,d);
            mind=min(mind,d);
        }
        r=0,d=0;
        int rflag=0,dflag=0;
        rep(i,s.size()){
            if(r==maxr){
                if(rflag==0){
                    rflag=1;
                }
                else if(rflag==2){
                    rflag=4;
                }
                else if(rflag==3)rflag=5;
            }
            if(r==minr){
                if(rflag==0){
                    rflag=2;
                }
                else if(rflag==1)rflag=3;
                else if(rflag==4)rflag=5;
            }
            if(d==maxd){
                if(dflag==0){
                    dflag=1;
                }
                else if(dflag==2){
                    dflag=4;
                }
                else if(dflag==3)dflag=5;
            }
            if(d==mind){
                if(dflag==0){
                    dflag=2;
                }
                else if(dflag==1)dflag=3;
                else if(dflag==4)dflag=5;
            }
            if(s[i]=='D')r++;
            if(s[i]=='S')d++;
            if(s[i]=='A')r--;
            if(s[i]=='W')d--;
            
        }
        if(r==maxr){
                if(rflag==0){
                    rflag=1;
                }
                else if(rflag==2){
                    rflag=4;
                }
                else if(rflag==3)rflag=5;
            }
            if(r==minr){
                if(rflag==0){
                    rflag=2;
                }
                else if(rflag==1)rflag=3;
                else if(rflag==4)rflag=5;
            }
            if(d==maxd){
                if(dflag==0){
                    dflag=1;
                }
                else if(dflag==2){
                    dflag=4;
                }
                else if(dflag==3)dflag=5;
            }
            if(d==mind){
                if(dflag==0){
                    dflag=2;
                }
                else if(dflag==1)dflag=3;
                else if(dflag==4)dflag=5;
            }
        ll int R=maxr-minr+1ll;
        ll int D=maxd-mind+1ll;
        ll ans=R*D;
        if(R>2&&rflag<5){
            ans=D*(R-1ll);
        }
        if(D>2&&dflag<5){
            ans=min(ans,R*(D-1ll));
        }
        cout<<ans<<endl;
    }
}