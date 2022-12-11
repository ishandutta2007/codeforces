#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 9;

vector<int> dv[N];
bool use[N];
bool hh[N];

void init(){
  for(int i = N-1; i >= 1; i -- )
    for(int j = i ; j < N ; j += i){
      dv[j].push_back(i);
    }
}

int main(){
  fastIO;
  init();
  
  int n;
  cin >> n;
  int p = 1;
  vector<int> c;
  bool can;
  while(c.size() < n){
    for(int j = p; j <= n; j += p){
      dv[j].pop_back();
      if(hh[j]) continue;
      can = true;
      for(auto x : dv[j]){
        if(x > p && use[x]){
          can = false;
        }
      }
      if(can){
        hh[j] = true;
        if(!c.empty()){
          cout << p << " ";
        }
        c.push_back(j);
        for(auto x : dv[j]){
          use[x] = true;
        }
      }
    }
    p ++ ;
  }
  return 0;
}