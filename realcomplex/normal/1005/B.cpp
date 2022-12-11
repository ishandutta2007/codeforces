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
  string s, t;
  cin >> s >> t;
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  int m = min(s.size(), t.size());
  int cnt = 0;
  for(int i = 0;i < m; i ++ ){
    if(s[i] == t[i])
      cnt ++ ;
    else
      break;
  }
  cout << (s.size() + t.size()) - (cnt * 2);
  return 0;
}