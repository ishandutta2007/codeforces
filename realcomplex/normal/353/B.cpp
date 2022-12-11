#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int MX = 100;
vector<int> ix[MX];

vector<int> rem;

int main(){
  fastIO;
  int n;
  cin >> n;
  int rr[n * 2];
  int p;
  for(int i = 0;i < n * 2;i ++ ){
    cin >> p;
    ix[p].push_back(i);
  }
  int v1, v2;
  int tp;
  int s1 = 0, s2 = 0;
  for(int i = 1;i < MX;i ++ ){
    if(ix[i].size() >= 2){
      v1 = ix[i].back();
      ix[i].pop_back();
      v2 = ix[i].back();
      ix[i].pop_back();
      rr[v1] = 1;
      rr[v2] = 2;
      s1 ++ ;
      s2 ++ ;
      while(!ix[i].empty()){
        tp = ix[i].back();
        ix[i].pop_back();
        rem.push_back(tp);
      }
    }
    else{
      if(ix[i].size() == 1){
        tp = ix[i][0];
        ix[i].clear();
        if(s1 < s2){
          s1 ++ ;
          rr[tp] = 1;
        }
        else{
          s2 ++ ;
          rr[tp] = 2;
        }
      }
    }
  }
  cout << s1*s2 << "\n";
  for(auto x : rem){
    if(s1 < s2){
      rr[x] = 1;
      s1 ++ ;
    }
    else{
      rr[x] = 2;
      s2 ++ ;
    }
  }
  for(int i = 0;i < n*2;i ++ )
    cout << rr[i] << " ";
  return 0;
}