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

const int N = (int)1e5 + 9;
const int AL = 26;
bool ff[N];
vector<int> pos[AL];

int main(){
  fastIO;
  string t;
  cin >> t;
  for(int i = 0 ; i < (int)t.size(); i ++ ){
    pos[t[i] - 'a'].push_back(i);
  }
  int id = 0;
  vector<int> cur;
  vector<int> ans;
  int las;
  for(int i = 0 ; i < AL; i ++ ){
    if(!pos[i].empty()){
      las = pos[i].back();
      while(id <= las){
        while(!cur.empty() && cur.back() <= i){
          ans.push_back(cur.back());
          cur.pop_back();
        }
        cur.push_back(t[id] - 'a');
        id ++ ;
      }
    }
    while(!cur.empty() && cur.back() <= i){
      ans.push_back(cur.back());
      cur.pop_back();
    }
  }
  while(!cur.empty()){
    ans.push_back(cur.back());
    cur.pop_back();
  }
  for(auto p : ans){
    cout << char(p + 'a');
  }
  return 0;
}