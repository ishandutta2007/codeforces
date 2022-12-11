#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a)

int main(){
  fastIO;
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  vector<int> mv;
  bool has;
  for(int i = 0; i < n;i ++ ){
    has = false;
    for(int j = i;j < n;j ++ ){
      if(b[i] == a[j]){
        has = true;
        for(int x = j - 1;x >= i;x -- ){
          mv.push_back(x);
          swap(a[x], a[x + 1]);
        }
        break;
      }
    }
    if(!has){
      cout << -1;
      return 0;
    }
  }
  cout << mv.size() << "\n";
  for(auto x : mv)
    cout << x+1 << " ";
  return 0;
}