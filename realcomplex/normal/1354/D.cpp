#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1e6 + 1;
int segt[N * 4 + 10];

int main(){
  fastIO;
  int n,q;
  cin >> n >> q;
  int a;
  int lf,rf;
  int mid;
  int node;
  for(int i = 1; i <= n; i ++ ){
    cin >> a;
    lf=1,rf=n;
    node=1;
    while(1){ // worst segtree implementation ever but recursive calls are too expensive
      segt[node]++;
      if(lf==rf)break;
      mid=(lf+rf)>>1;
      if(mid>=a){
        rf=mid;
        node<<=1;
      }
      else{
        lf=mid+1;
        node<<=1;
        node|=1;
      }
    }
  }
  for(int i = 1; i <= q; i ++ ){
    cin >> a;
    if(a > 0){
      lf = 1, rf = n;
      node = 1;
      while(1){
        segt[node]++;
        if(lf==rf)break;
        mid=(lf+rf)>>1;
        if(mid>=a){
          rf=mid;
          node<<=1;
        }
        else{
          lf=mid+1;
          node<<=1;
          node|=1;
        }
      }
    }
    else{
      a=-a;
      lf=1,rf=n;
      node=1;
      while(1){
        segt[node]--;
        if(lf==rf)break;
        mid=(lf+rf)>>1;
        if(segt[node<<1] >= a){
          node <<= 1;
          rf=mid;
        }
        else{
          a-=segt[node<<1];
          node <<= 1;
          node |= 1;
          lf=mid+1;
        }
      }
    }
  }
  if(segt[1]==0){
    cout << 0;
    return 0;
  }
  lf=1,rf=n;
  node=1;
  while(1){
    if(lf==rf){
      cout << lf;
      return 0;
    }
    mid=(lf+rf)>>1;
    if(segt[node << 1] > 0){
      node <<= 1;
      rf=mid;
    }
    else{
      node <<= 1;
      node |= 1;
      lf=mid+1;
    }
  }
  return 0;
}