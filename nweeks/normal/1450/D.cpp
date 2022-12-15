#include <bits/stdc++.h>
#define int long long
using namespace std;

bool isBitonic(vector<int> &arr) {
  int nbElem = arr.size();
  int cur = 0;
  while (cur + 1 < nbElem and arr[cur] <= arr[cur + 1])
    ++cur;
  while (cur + 1 < nbElem and arr[cur] >= arr[cur + 1])
    ++cur;
  return cur + 1 == nbElem;
}

bool isPerm(vector<int> arr) {
  sort(arr.begin(), arr.end());
  for (int i(0); i < (int)arr.size(); ++i)
    if (arr[i] != i + 1)
      return false;
  return true;
}

vector<int> compress(vector<int> &arr, int k, int nbElem) {

  deque<pair<int, int>> q;
  vector<int> compressed(nbElem - k + 1);
  for (int i(0); i < k - 1; ++i) {
    while (!q.empty() and q.back().first > arr[i])
      q.pop_back();
    q.emplace_back(arr[i], i);
  }
  for (int i(0); i < nbElem - k + 1; ++i) {
    while (!q.empty() and q.front().second < i)
      q.pop_front();
    while (!q.empty() and q.back().first > arr[i + k - 1])
      q.pop_back();
    q.emplace_back(arr[i + k - 1], i + k - 1);
    compressed[i] = q.front().first;
  }
  return compressed;
}

string solve() {
  int nbElem;
  cin >> nbElem;

  vector<int> arr(nbElem);
  for (auto &v : arr)
    cin >> v;
  string ret(nbElem, '0');
  ret[0] = char('0' + isPerm(arr));
  int lo = 1, up = nbElem;
  while (lo < up) {
    int mid = (lo + up) / 2;

    vector<int> compressed = compress(arr, mid, nbElem);
    if (isBitonic(compressed))
      up = mid;
    else
      lo = mid + 1;
  }

  auto compressed = compress(arr, lo, nbElem);
  int cntInc(0);
  while (cntInc < (int)compressed.size() - 1 and
         compressed[cntInc] <= compressed[cntInc + 1])
    cntInc++;
  vector<int> inc, dec;

  map<int, int> cntOcc;
  for (auto v : compressed) {
    cntOcc[v]++;
  }
  for (int i(0); i <= cntInc; ++i)
    inc.push_back(compressed[i]);
  for (int i((int)compressed.size() - 1); i > cntInc; --i)
    dec.push_back(compressed[i]);

  for (int i(lo); i <= nbElem; ++i) {
    assert(!inc.empty());
    assert(dec.empty() or inc.back() > dec.back());
    if ((int)cntOcc.size() == nbElem - i + 1 and
        cntOcc.rbegin()->first == nbElem - i + 1)
      ret[i - 1] = '1';
    cntOcc[inc.back()]--;
    if (!cntOcc[inc.back()])
      cntOcc.erase(inc.back());
    inc.pop_back();
    while (!dec.empty() and (inc.empty() or dec.back() >= inc.back())) {
      inc.push_back(dec.back());
      dec.pop_back();
    }
  }
  return ret;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }
}