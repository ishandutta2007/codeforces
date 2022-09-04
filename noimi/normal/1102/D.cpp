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
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
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
template<typename A, size_t NNN, typename T>
void Fill(A (&array)[NNN], const T &val){
    fill( (T*)array, (T*)(array+NNN), val );
}
#define INF 1e9+7
#define LLINF 1e18+7
ll MOD=1e9+7;
#define N 310000
ll n,m;
ll dp[N];
ll dp2[N];
vec G[N];
int s[N];
int main(){
    n=in();
    string t;
    cin>>t;
    rep(i,n){
        s[i]=(t[i]-'0');
    }
    int c[3]={};
    rep(i,n){
        c[(s[i])]++;
    }
    m=n/3;
    rep(i,3){
        c[i]-=m;
    }
    rep(i,n){
        if(c[0]<0){
            if(s[i]!=0&&c[s[i]]>0){
                c[s[i]]--;
                c[0]++;
                s[i]=0;
            }
        }
    }
    rep3(i,n-1,0){
        if(c[2]<0){
            if(s[i]!=2&&c[s[i]]>0){
                c[s[i]]--;
                c[2]++;
                s[i]=2;
            }
        }
    }
    rep3(i,n-1,0){
        if(c[0]>0&&c[1]<0){
            if(s[i]==0){
                s[i]=1;
                c[0]--;
                c[1]++;
            }
        }
    }
    rep(i,n){
        if(c[2]>0&&c[1]<0){
            if(s[i]==2){
                s[i]=1;
                c[2]--;
                c[1]++;
            }
        }
    }
    rep(i,n)cout<<s[i];
    return 0;
}