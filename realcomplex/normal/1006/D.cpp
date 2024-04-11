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

int charset(char a, char b, char c, char d){
  map<char, int>ct;
  ct[a] ++ ;
  ct[b] ++ ;
  ct[c] ++ ;
  ct[d] ++ ;
  if(ct.size() == 4)
    return 2;
  if(ct.size() == 3){
    if(a == b)
      return 2;
    else
      return 1;
  }
  if(ct.size() == 2){
    if(ct[a] == 2)
      return 0;
    else
      return 1;
  }
  return 0;
}

int main(){
  fastIO;
  int n;
  cin >> n;
  string a,b;
  cin >> a >> b;
  int ans = 0;
  int x;
  for(int i = 0;i < n/2;i ++ ){
    x = charset(a[i], a[n - i - 1], b[i], b[n - i - 1]);
    ans += x;
  }
  if(n%2)
    if(a[n/2] != b[n/2])
      ans ++ ;
  cout << ans << "\n";
  return 0;
}