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

ll sol[] = {4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292, 341};

int main(){
  fastIO;
  int n;
  cin >> n;
  if( n <= 12)
    cout << sol[n - 1];
  else
    cout << sol[11] + (49ll * (n - 12));
  return 0;
}