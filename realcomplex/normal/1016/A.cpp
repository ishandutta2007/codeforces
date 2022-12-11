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
  int n,m;
  cin >> n >> m;
  int c = 0, a;
  for(int i = 0;i < n; i ++ ){
    cin >> a;
    c += a;
    cout << c/m << " ";
    c %= m;
  }
  return 0;
}