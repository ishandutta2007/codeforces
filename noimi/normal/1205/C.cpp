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
ll MOD=998244353;
vector<vec> v;
int ask(int x1,int y1,int x2,int y2){
    printf("? %d %d %d %d\n",x1,y1,x2,y2);
    cout.flush();
    int t;cin>>t;
    return t;
}
main(){
    int n=in();
    v.resize(n+1);
    rep2(i,1,n)v[i].resize(n+1);
    v[1][1]=1;
    v[n][n]=0;
    rep2(j,1,n){
        if(j%2){
            if(j!=1){
                if(ask(1,j-2,1,j))
                v[1][j]=v[1][j-2];
                else
                v[1][j]=1-v[1][j-2];
            }
            for(int i=3;i<=n;i+=2){
                if(ask(i-2,j,i,j))
                v[i][j]=v[i-2][j];
                else
                v[i][j]=1-v[i-2][j];
            }
        }
        else{
            if(ask(1,j-1,2,j))
            v[2][j]=v[1][j-1];
            else
            v[2][j]=1-v[1][j-1];
            for(int i=4;i<=n;i+=2){
                if(ask(i-2,j,i,j))
                v[i][j]=v[i-2][j];
                else
                v[i][j]=1-v[i-2][j];
            }
        }
    }
    rep2(j,1,n){
        if(j%2==0){
            if(j==2){
                if(ask(1,2,3,2))
                v[1][2]=0;
                else v[1][2]=1;
                for(int i=5;i<=n;i+=2){
                    if(ask(i-2,j,i,j))
                    v[i][j]=v[i-2][j];
                    else
                    v[i][j]=1-v[i-2][j];
                }
            }
            else{
                if(ask(1,j-2,1,j))
                v[1][j]=v[1][j-2];
                else
                v[1][j]=1-v[1][j-2];
                for(int i=3;i<=n;i+=2){
                    if(ask(i-2,j,i,j))
                    v[i][j]=v[i-2][j];
                    else
                    v[i][j]=1-v[i-2][j];
                }
            }
        }
        else{
            if(j==1){
                if(ask(2,1,3,2))
                v[2][1]=0;
                else
                v[2][1]=1;
            }
            else{
                if(ask(2,j-2,2,j))
                v[2][j]=v[2][j-2];
                else
                v[2][j]=1-v[2][j-2];
            }
            for(int i=4;i<=n;i+=2){
                if(ask(i-2,j,i,j))
                v[i][j]=v[i-2][j];
                else
                v[i][j]=1-v[i-2][j];
            }
        }
    }
    int m;
    bool f;
    rep2(i,1,n){
        if(v[i][i]==v[i+1][i+1]&&v[i+1][i+1]!=v[i+2][i+2]){m=i;break;}
        if(v[i][i]!=v[i+1][i+1]&&v[i+1][i+1]==v[i+2][i+2]){m=i;break;}
    }
    if(v[m+1][m]!=v[m+2][m+1]){
        if(v[m][m]==v[m+1][m+1]){
            if(ask(m+1,m,m+2,m+2)){
                f=(v[m+1][m]==v[m+2][m+2]);
            }
            else{
                f=(v[m+1][m]!=v[m+2][m+2]);
            }
        }
        else{
            if(ask(m,m,m+2,m+1)){
                f=(v[m][m]==v[m+2][m+1]);
            }
            else f=(v[m][m]!=v[m+2][m+1]);
        }
    }
    else{
        if(v[m][m]==v[m+1][m+1]){
            if(ask(m,m,m+2,m+1)){
                f=(v[m][m]==v[m+2][m+1]);
            }
            else{
                f=(v[m][m]!=v[m+2][m+1]);
            }
        }
        else{
            if(ask(m+1,m,m+2,m+2)){
                f=(v[m+1][m]==v[m+2][m+2]);
            }
            else f=(v[m+1][m]!=v[m+2][m+2]);
        }
    }
    cout<<"!\n";
    rep2(i,1,n){
        rep2(j,1,n){
            if((i+j)%2){
                if(f)cout<<v[i][j];
                else cout<<1-v[i][j];
            }
            else cout<<v[i][j];
        }
        cout<<endl;
    }
}