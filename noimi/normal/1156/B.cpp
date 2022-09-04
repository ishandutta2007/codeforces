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
ll MOD=1e9+7;
//#define N 110000



main(){
    int n=in();
    rep(iii,n){
        string s;cin>>s;
        vector<char> v;
        rep(i,s.size()){
            v.pb(s[i]);
        }
        sort(ALL(v));
        int num[26]={};
        int var=0;
        vec uni;
        for(auto c:v){
            int t=c-'a';
            if(num[t]==0){
                var++;
                uni.pb(t);
            }
            num[t]++;
        }
        if(var==2){
            if(uni[0]+1==uni[1]){
                cout<<"No answer\n";continue;
            }
        }
        if(var==3){
            if(uni[0]+1==uni[1]&&uni[1]+1==uni[2]){
                cout<<"No answer\n";continue;
            }
            if(uni[0]+1==uni[1]){
                int t=uni[0];
                rep(i,num[t])cout<<char('a'+t);
                t=uni[2];
                rep(i,num[t])cout<<char('a'+t);
                t=uni[1];
                rep(i,num[t])cout<<char('a'+t);
            }
            else{
                int t=uni[1];rep(i,num[t])cout<<char('a'+t);
                t=uni[0];rep(i,num[t])cout<<char('a'+t);
                t=uni[2];rep(i,num[t])cout<<char('a'+t);

            }
            cout<<endl;
            continue;
        }
        if(var%2){
            rep(i,var/2){
                rep(j,num[uni[i]])cout<<char('a'+uni[i]);
                rep(j,num[uni[var/2+i+1]])cout<<char('a'+uni[var/2+i+1]);
            }
            rep(i,num[uni[var/2]])cout<<char('a'+uni[var/2]);
        }
        else{
            rep(i,var/2){
                int t=uni[var/2+i];
                rep(j,num[t])cout<<char('a'+t);
                t=uni[i];
                rep(j,num[t])cout<<char('a'+t);
            }
        }
        cout<<endl;
    }
}