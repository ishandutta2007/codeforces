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
  ll int n=in(),m=in(),k=in(),q=in();
  vector<vector<ll>> tr(n+1);
  vector<ll> st;
  rep(i,k){
    ll int r=in(),c=in();
    tr[r].pb(c);
  }
  rep(i,q){
    st.pb(in());
  }
  rep(i,n+1){
    if(tr[i].size())sort(all(tr[i]));
  }
  sort(all(st));
  ll int pl,pr,c;
  rep2(i,1,n){
    if(tr[i].size()){c=i;pl=tr[i][0],pr=tr[i][tr[i].size()-1];break;}
  }
  pl=1,pr=1;
  ll int l=c-2,r=c-2;
  ll int mx;
  rep3(i,n,1){
    if(tr[i].size()){
      mx=i;break;
    }
  }
  //cout<<l<<" "<<pl<<" "<<r<<" "<<pr<<endl;
  if(c==1){
    c=2;
    l=INF;
    r=tr[1][tr[1].size()-1]-1;
    pr=tr[1][tr[1].size()-1];
  }
  rep2(i,c,mx){
    if(tr[i].size()==0){
      l++;r++;continue;
    }
    else{
      int pn=lower_bound(all(st),pl)-st.begin();
      int pn2=lower_bound(all(st),pr)-st.begin();
      ll int pl1=(pn<q?st[pn]:INF),pl2=(pn-1>=0?st[pn-1]:INF);
      ll int pr1=(pn2<q?st[pn2]:INF),pr2=(pn2-1>=0?st[pn2-1]:INF);
      ll int t1=min(l+(ll)abs(pl1-tr[i][0])+(ll)abs(pl1-pl),r+(ll)abs(pr1-tr[i][0])+(ll)abs(pr1-pr));
      ll int t2=min(l+(ll)abs(pl2-tr[i][0])+(ll)abs(pl2-pl),r+(ll)abs(pr2-tr[i][0])+(ll)abs(pr2-pr));
      //cout<<pl1<<" "<<pl2<<endl;
      ll int ttr;
      if(t1<t2){
        ttr=t1+1+tr[i][tr[i].size()-1]-tr[i][0];
      }
      else{
        ttr=t2+1+tr[i][tr[i].size()-1]-tr[i][0];
      }
      t1=min(r+(ll)abs(pr1-tr[i][tr[i].size()-1])+(ll)abs(pr1-pr),l+(ll)abs(pl1-tr[i][tr[i].size()-1])+(ll)abs(pl1-pl));
      t2=min(r+(ll)abs(pr2-tr[i][tr[i].size()-1])+(ll)abs(pr2-pr),l+(ll)abs(pl2-tr[i][tr[i].size()-1])+(ll)abs(pl2-pl));
      if(t1<t2){
        l=t1+1+tr[i][tr[i].size()-1]-tr[i][0];
      }
      else{
        l=t2+1+tr[i][tr[i].size()-1]-tr[i][0];
      }
      r=ttr;
      pr=tr[i][tr[i].size()-1];
      pl=tr[i][0];
    }
    //cout<<l<<" "<<pl<<" "<<r<<" "<<pr<<endl;
  }
  cout<<min(l,r)<<endl;
}