#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 10005;

int can[N];

int main(){
  fastIO;
  int n,m;
  cin >> n >> m;
  int k;
  int sum = 0;
  vector<int> ff;
  for(int i = 0 ; i < n; i ++ ){
    k = i/2;
    if(sum + k > m) break;
    sum += k;
    ff.push_back(i + 1);
  }
  for(int i = 0 ; i < ff.size(); i ++ ){
    for(int j = i + 1; j < ff.size(); j ++ ){
      can[ff[i] + ff[j]] ++ ;
    }
  }
  int need = m - sum;
  for(int k = ff.back() + 1; k < N ; k ++ ){
    if(can[k] == need && ff.size() < n){
      ff.push_back(k);
      need = 0;
      break;
    }
  }
  if(need > 0){
    cout << -1;
    return 0;
  }
  int inf = (int)1e8;
  while(ff.size() < n){
    ff.push_back(inf);
    inf += 5001;
  }
  for(auto x : ff)
    cout << x << " ";
  return 0;
}