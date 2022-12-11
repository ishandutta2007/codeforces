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

const int N = 3005;
const int M = (int)3e6 + 9;
char f[N];
vector<int> p[M];

int main(){
  fastIO;
  int n, k;
  cin >> n >> k;
  for(int i = 1; i <= n; i ++ ){
    cin >> f[i];
  }
  bool df = true;
  int cnt = 0;
  int moves = 0;
  while(df){
    df = false;
    vector<int> cur;
    for(int i = 1; i < n; i ++ ){
      if(f[i] == 'R' && f[i + 1] == 'L'){
        df = true;
        cur.push_back(i);
        swap(f[i], f[i + 1]);
        i ++ ;
      }
    }
    if(!df) break;
    cnt ++ ;
    if(cnt > k){
      cout << -1;
      return 0;
    }
    p[cnt] = cur;
    moves += (int)cur.size();
  }
  if(moves < k){
    cout << -1;
    return 0;
  }
  for(int i = k ; i >= 1; i -- ){
    if(p[i].empty()){
      p[i].push_back(p[cnt].back());
      p[cnt].pop_back();
      if(p[cnt].empty()) cnt -- ;
    }
  }
  for(int i = 1; i <= k ; i ++ ){
    cout << p[i].size() << " ";
    for(auto x : p[i]) cout << x << " ";
    cout << "\n";
  }
  return 0;
}