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


main(){
    int n;cin>>n;
    int cnt=0,tmp=0;
    vec a;
    rep(i,n){
        a.pb(in());
        if(a[i]%2==0)tmp+=a[i]/2;
        else{
            if(a[i]<0)tmp+=a[i]/2-1;
            else tmp+=a[i]/2;
        }
    }
    cnt=-tmp;
    rep(i,n){
        if(a[i]%2&&cnt){
            cnt--;
            if(a[i]<0)cout<<a[i]/2<<endl;
            else cout<<a[i]/2+1<<endl;
        }
        else if(a[i]%2!=0&&a[i]<0) cout<<a[i]/2-1<<endl;
        else cout<<a[i]/2<<endl;
    }

}