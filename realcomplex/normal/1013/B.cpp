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
  int n,x;
  cin >> n >> x;
  int a[n];
  set<int>cur, ch;
  for(int i = 0;i < n;i ++ ){
    cin >> a[i];
    if(cur.count(a[i])){
      cout << 0;
      return 0;
    }
    cur.insert(a[i]);
  }
  int ans = 3;
  for(int i = 0;i < n;i ++ ){
    if((a[i] & x) == a[i]){
      continue;
    }
    a[i] &= x;
    if(ch.count(a[i])){
      ans = min(ans, 2);
    }
    if(cur.count(a[i])){
      ans = min(ans, 1);
    }
    ch.insert(a[i]);
  }
  cout << (ans == 3 ? -1 : ans);
  return 0;
}