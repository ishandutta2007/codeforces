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
    int n=in();
    vector<int> prime(2010,1);
    prime[1]=0;
    prime[2]=1;
    for(int i=2;i<=2000;i++){
        for(int j=i*2;j<=2000;j+=i){
            prime[j]=0;
        }
    }
    int m;
    rep2(i,n,n*2){
        if(prime[i]){
            m=i;break;
        }
    }
    cout<<m<<endl;
    rep(i,n-1){
        cout<<i+1<<" "<<i+2<<endl;
    }
    cout<<n<<" "<<1<<endl;
    rep2(i,3,1000){
        int M;
        rep2(j,i,i*2)if(prime[j]){M=j;break;}
        if(M>i+i/2)cout<<00000;
    }
    rep2(i,1,m-n){
        cout<<i<<" "<<i+n/2<<endl;
    }
}