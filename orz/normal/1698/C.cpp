#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
using namespace std;

const int maxN = 3e5;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, ai;
  bool zero;
  cin >> t;
  while(t--)
  {
    vector<int> a;
    unordered_map<int, int, custom_hash> mp;
    zero = false;

    int neg = 0, pos = 0;
    cin >> n;
    a.reserve(n);
    for (int i = 0; i < n; i++)
    {
      cin >> ai;
      pos += ai > 0;
      neg += ai < 0;
      if (ai == 0) zero = true;
      else {a.push_back(ai); mp[ai] = 1;}
    }
    if (zero) {mp[0] = 1;}
    if (pos >=3 || neg >= 3) {cout << "NO" << endl; continue;}

    bool ans = true;

    n = (int) a.size();

    if (zero)
    {
      for (int i = 0; i < n-1; i++)
      {
        for (int j = i+1; j < n; j++)
        {
          int total = a[i] + a[j];
          if (mp.count(total) == 0) ans = false;
        }
      }
    }
    for (int i = 0; i < n-2; i++)
    {
      for (int j = i+1; j < n-1; j++)
      {
        for (int k = j+1; k < n; k++)
        {
          int total = a[i] + a[j] + a[k];
          if (mp.count(total) == 0) ans = false;
        }
      }
    }
    if (ans == false) cout << "NO" << endl;
    else cout << "YES" << endl;
  }
}