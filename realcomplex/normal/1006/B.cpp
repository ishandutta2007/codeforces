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
  int n, k;
  cin >> n >> k;
  bool xi[n];
  pii x[n];
  for(int i = 0;i < n;i ++ ){
    cin >> x[i].fi;
    x[i].se = i;
    xi[i] = false;
  }
  sort(x, x + n);
  reverse(x, x + n);
  int sum = 0;
  for(int i = 0;i < k;i ++ ){
    sum += x[i].fi;
    xi[x[i].se] = true;
  }
  vector<int>pp;
  int u = 0;
  for(int i = 0;i < n;i ++ ){
    u ++ ;
    if(xi[i] == true){
      if(pp.size() < k - 1 or i + 1 == n){
        pp.push_back(u);
        u = 0;
      }
    }
    else{
      if(i + 1 == n)
        pp.push_back(u);
    }
  }
  cout << sum << "\n";
  for(auto x : pp)
    cout << x << " ";
  return 0;
}