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

const int N= 105;
int cnt[N];

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  int l, r;
  for(int i = 0;i < n;i ++ ){
    cin >> l >> r;
    cnt[l] ++ ;
    cnt[r + 1] -- ;
  }
  vector<int> p;
  for(int j = 1;j <= m;j ++ ){
    cnt[j] += cnt[j - 1];
    if(cnt[j] == 0)
      p.push_back(j);
  }
  cout << p.size() << "\n";
  for(auto x : p)
    cout << x << " ";
  cout << "\n";
  return 0;
}