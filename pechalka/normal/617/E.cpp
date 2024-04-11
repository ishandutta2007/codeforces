#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MAXN = 100000;
const int K = 317;

int cnt[1048576];
int A[MAXN + 1];

struct query{
  int left, right, i;
  query(){
  };
  query(int _left, int _right, int _i){
    left = _left;
    right = _right;
    i = _i;
  }
};

query B[MAXN];
long long ans[MAXN];

int main(){
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i){
    int a;
    cin >> a;
    A[i + 1] = A[i] ^ a;
  }
  for (int i = 0; i < m; ++i){
    int l, r;
    cin >> l >> r;
    B[i] = query(l - 1, r, i);
  }
  sort(B, B + m, [](const query &a, const query &b){
    return make_pair(a.left / K, a.right) < make_pair(b.left / K, b.right);
  });
  ++cnt[0];
  int nowl = 0, nowr = 0;
  long long anscnt = 0;
  for (int i = 0; i < m; ++i){
    auto cur = B[i];
    while (nowl > cur.left){
      --nowl;
      int tmp = k ^ A[nowl];
      anscnt += cnt[tmp];
      ++cnt[A[nowl]];
      //cout << nowl << ' ' << nowr << ' ' << anscnt << '\n';
    }
    while (nowr < cur.right){
      ++nowr;
      int tmp = k ^ A[nowr];
      anscnt += cnt[tmp];
      ++cnt[A[nowr]];
      //cout << nowl << ' ' << nowr << ' ' << anscnt << '\n';
    }
    while (nowl < cur.left){
      int tmp = k ^ A[nowl];
      --cnt[A[nowl]];
      anscnt -= cnt[tmp];
      ++nowl;
      //cout << nowl << ' ' << nowr << ' ' << anscnt << '\n';
    }
    while (nowr > cur.right){
      int tmp = k ^ A[nowr];
      --cnt[A[nowr]];
      anscnt -= cnt[tmp];
      --nowr;
      //cout << nowl << ' ' << nowr << ' ' << anscnt << '\n';
    }
    ans[cur.i] = anscnt;
  }
  for (int i = 0; i < m; ++i)
    cout << ans[i] << '\n';
  return 0;
}