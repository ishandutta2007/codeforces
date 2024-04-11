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
ll MOD=1e9+7;

int mat[1010][1010];

main(){
    int n=in();
    int m=n/4;
    rep(i1,m){
        rep(j1,m){
            rep(i,4){
                rep(j,4){
                    mat[i1*4+i][j1*4+j]=(i1*m+j1)*16+i*4+j;
                }
            }
        }
    }
    bool flag=true;
    rep(i,n){
        int t=0,s=0;
        rep(j,n){
            t^=mat[i][j];
            s^=mat[j][i];
        }
        if(t||s)cout<<"NO";
    }
    rep(i,n){
        rep(j,n){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}