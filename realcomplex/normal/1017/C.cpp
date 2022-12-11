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
  int bl = sqrt(n);
  int a[n];
  int k = (n + bl - 1)/bl;
  int lf = 0, rf;
  int las = n;
  for(int i = 0;i < k;i ++ ){
    lf = i*bl;
    rf = min(n - 1, lf + bl - 1);
    for(int j = rf;j >= lf; j -- ){
      a[j] = las;
      las -- ;
    }
  }
  for(int i = 0;i < n; i ++ ){
    cout << a[i] << " ";
  }
  return 0;
}