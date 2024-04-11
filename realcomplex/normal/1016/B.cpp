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

const int N = 1005;
int cnt[N];

int main(){
  fastIO;
  int n,m, q;
  cin >> n >> m >> q;
  string s, t;
  cin >> s >> t;
  bool is;
  for(int i = 0;i <= n-m;i ++ ){
    is = true;
    for(int j = 0;j < m;j ++ ){
      if(s[i + j] != t[j])
        is = false;
    }
    if(is)
      cnt[i] = 1;
  }
  for(int i = 1;i <= n;i ++ )
    cnt[i] += cnt[i - 1];
  int l, r;
  for(int i = 0;i < q;i ++ ){
    cin >> l >> r;
    l --; 
    r -- ;
    r = r - m + 1;
    if(r < l)
      cout << 0 << "\n";
    else if(l == 0)
      cout << cnt[r] << "\n";
    else
      cout << cnt[r] - cnt[l - 1] << "\n";
  }
  return 0;
}