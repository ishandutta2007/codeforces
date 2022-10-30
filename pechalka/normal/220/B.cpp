#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MAXN = 100000;

const int K = 317;

int cnt[MAXN + 1];

int A[MAXN];

struct query{
  int left, right, i;
  query(){
  }
  query(int _left, int _right, int _i){
    left = _left;
    right = _right;
    i = _i;
  }
};

query B[MAXN];
int ans[MAXN];

int main(){
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i){
    cin >> A[i];
    if (A[i] > MAXN)
      A[i] = 0;
  }
  for (int i = 0; i < m; ++i){
    cin >> B[i].left >> B[i].right;
    --B[i].left;
    B[i].i = i;
  }
  sort(B, B + m, [](const query &a, const query &b){
    return make_pair(a.left / K, a.right) < make_pair(b.left / K, b.right);
  });
  int nowl = 0, nowr = 0, nowans = 1;
  for (int i = 0; i < m; ++i){
    auto cur = B[i];
    while (nowl > cur.left){
      --nowl;
      if (cnt[A[nowl]] == A[nowl])
        --nowans;
      ++cnt[A[nowl]];
      if (cnt[A[nowl]] == A[nowl])
        ++nowans;
      //cout << nowl << ' ' << nowr << ' ' << nowans << '\n';
    }
    while (nowr < cur.right){
      if (cnt[A[nowr]] == A[nowr])
        --nowans;
      ++cnt[A[nowr]];
      if (cnt[A[nowr]] == A[nowr])
        ++nowans;
      ++nowr;
      //cout << nowl << ' ' << nowr << ' ' << nowans << '\n';
    }
    while (nowl < cur.left){
      if (cnt[A[nowl]] == A[nowl])
        --nowans;
      --cnt[A[nowl]];
      if (cnt[A[nowl]] == A[nowl])
        ++nowans;
      ++nowl;
      //cout << nowl << ' ' << nowr << ' ' << nowans << '\n';
    }
    while (nowr > cur.right){
      --nowr;
      if (cnt[A[nowr]] == A[nowr])
        --nowans;
      --cnt[A[nowr]];
      if (cnt[A[nowr]] == A[nowr])
        ++nowans;
      //cout << nowl << ' ' << nowr << ' ' << nowans << '\n';
    }
    ans[cur.i] = nowans - (cnt[0] == 0);
  }
  for (int i = 0; i < m; ++i)
    cout << ans[i] << '\n';
  return 0;
}