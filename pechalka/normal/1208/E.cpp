#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <set>

using namespace std;

vector<long long> tree;

void add(int p, int left, int right, int x, int y, long long val){
  if (y <= left || right <= x)
    return;
  if (x <= left && right <= y){
    //cout << p << " " << left << " " << right << " " << val << "\n";
    tree[p] += val;
    return;
  }
  int mid = (left + right) / 2;
  add(2 * p + 1, left, mid, x, y, val);
  add(2 * p + 2, mid, right, x, y ,val);
}

void get1(int p, int left, int right, long long mod){
  if (left + 1 == right){
    cout << tree[p] + mod << ' ';
    return;
  }
  int mid = (left + right) / 2;
  get1(2 * p + 1, left, mid, mod + tree[p]);
  get1(2 * p + 2, mid, right, mod + tree[p]);
}

//another tree

void build(vector<long long> &t, int p, int left, int right, vector<long long> &A){
  if (left + 1 == right){
    t[p] = A[left];
    return;
  }
  int mid = (left + right) / 2;
  build(t, 2 * p + 1, left, mid, A);
  build(t, 2 * p + 2, mid, right, A);
  t[p] = max(t[2 * p + 1], t[2 * p + 2]);
}

const long long INF = 1e9;

long long get2(vector<long long> &t, int p, int left, int right, int x, int y){
  if (y <= left || right <= x)
    return -INF;
  if (x <= left && right <= y)
    return t[p];
  int mid = (left + right) / 2;
  return max(get2(t, 2 * p + 1, left, mid, x, y), get2(t, 2 * p + 2, mid, right, x, y));
}

int main(){
  int n, w;
  cin >> n >> w;
  tree.resize(4 * w);
  for (int i = 0; i < n; ++i){
    int l;
    cin >> l;
    vector<long long> t(4 * l);
    vector<long long> A(l);
    for (int j = 0; j < l; ++j)
      cin >> A[j];
    build(t, 0, 0, l, A);
    if (w >= 2 * l + 1){
      for (int j = 0; j < l; ++j)
        add(0, 0, w, j, j + 1, max(0ll, get2(t, 0, 0, l, 0, j + 1)));
      for (int j = 0; j < l; ++j)
        add(0, 0, w, w - j - 1, w - j, max(0ll, get2(t, 0, 0, l, l - j - 1, l)));
      add(0, 0, w, l, w - l, max(0ll, get2(t, 0, 0, l, 0, l)));
    } else {
      for (int j = 0; j < w; ++j){
        if (w - j - 1 >= l || j >= l)
          add(0, 0, w, j, j + 1, max(0ll, get2(t, 0, 0, l, max(0, l - w + j), j + 1)));
        else
          add(0, 0, w, j, j + 1, get2(t, 0, 0, l, max(0, l - w + j), j + 1));
      }
    }
  }
  get1(0, 0, w, 0);
  return 0;
}