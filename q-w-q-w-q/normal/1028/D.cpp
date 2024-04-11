#include <cstdio>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

const int mod = 1e9 + 7;
int n;
priority_queue<int> buy;
priority_queue<int, vector<int>, greater<int>> sell;
set<int> unk;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;
  buy.push(-(1 << 30));
  sell.push(1 << 30);
  int ans = 1;
  while (n--) {
    char op[10];
    int x;

    cin >> op >> x;
    if (op[1] == 'D') {
      if (x < buy.top())
        buy.push(x);
      else if (x > sell.top())
        sell.push(x);
      else
        unk.insert(x);
    } else {
      if (x < buy.top()) {
        cout << 0;
        return 0;
      }
      if (x > sell.top()) {
        cout << 0;
        return 0;
      }

      if (x == sell.top()) {
        sell.pop();
        for (int y : unk)
          buy.push(y);
        unk.clear();
      } else if (x == buy.top()) {
        buy.pop();
        for (int y : unk)
          sell.push(y);
        unk.clear();
      } else {
        ans = ans * 2 % mod;
        for (int y : unk) {
          if (y < x)
            buy.push(y);
          if (y > x)
            sell.push(y);
        }
        unk.clear();
      }
    }
  }

  cout << 1ll * ans * (unk.size() + 1) % mod;
}