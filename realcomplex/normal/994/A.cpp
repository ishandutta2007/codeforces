#pragma optimize ("O3")
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

int main(){
  fastIO;
  int n,m;
  cin >> n >> m;
  int x[n];
  for(int i = 0;i < n;i ++ )
    cin >> x[i];
  set<int> tt;
  int y;
  for(int i = 0;i < m; i ++ ){
    cin >> y;
    tt.insert(y);
  }
  for(int i = 0;i < n;i ++ ){
    if(tt.count(x[i]))
      cout << x[i] << " ";
  }
  cout << "\n";
  return 0;
}