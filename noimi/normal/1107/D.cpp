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
void makegraph(int x,vector<vec> &v){rep(i,x-1){int a=in(),b=in();v[a].pb(b);v[b].pb(a);}}
template<typename A, size_t NNN, typename T>
void Fill(A (&array)[NNN], const T &val){
    fill( (T*)array, (T*)(array+NNN), val );
}
#define INF 1e9+7
#define LLINF 1e18+7
ll MOD=1e9+7;
#define N 255050

ll n,m,k;
ll a[N];
ll sum[N];
bool mat[6000][6000];
bool check(int x){
    bool flag=true;
    rep(i,n/x){
        rep(j,n/x){
        bool checker=mat[i*x][j*x];
        rep(ii,x){
            rep(jj,x){
            if(checker!=mat[ii+i*x][jj+j*x]){
                flag=false;
                break;
            }
            }
            if(!flag)break;
        }
        if(!flag)break;
    }
    if(!flag)break;
    }
    return flag;
}
main(){
    n=in();
    rep(i,n){
        string s;
        cin>>s;
        rep(j,n/4){
            int p=(s[j]-'0');
            if(p>16)p-=7;
            rep(k,4){
            mat[i][j*4+3-k]=p%2;
            p/=2;
            }
        }
    }
    /*rep(i,n){
        rep(j,n)cout<<mat[i][j];
        cout<<endl;
    }
    */
    vector<pii> factor;
    int nn=n;
    for(int i=2;i*i<=nn;i++){
        if(nn%i==0){
            int res=0;
            while(nn%i==0){
                nn/=i;
                res++;
            }
            factor.pb({i,res});
        }
    }
    if(nn>1)factor.pb({nn,1});
    int ans=1;
    rep(i,factor.size()){
        int res=1;
        int preans=1;
        rep2(j,1,factor[i].second){
            res*=factor[i].first;
            if(check(res)){
                preans=res;
            }
            else break;
        }
        ans*=preans;
    }
    cout<<ans;
    return 0;
}