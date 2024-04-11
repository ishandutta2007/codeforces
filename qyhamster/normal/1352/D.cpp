#ifdef LOCAL
#include <iostream>
#include <vector>
#include <queue>
#else
#include <bits/stdc++.h>
#endif
#define pii pair<int,int>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    deque<int> dq;
    for(int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      dq.push_back(x);
    }
    long long A = 0, B = 0, R = 1;
    int base = 0, cur = 0, side = 1;
    while(!dq.empty())
    {
      if(side == 1)
      {
        cur += dq.front();
        A += dq.front();
        dq.pop_front();
      }
      else
      {
        cur += dq.back();
        B += dq.back();
        dq.pop_back();
      }
      if(cur > base)
      {
        base = cur;
        cur = 0;
        side = 1 - side;
        if(!dq.empty())R++;
      }
    }
    cout << R << " " << A << " " << B << endl;
  }
  return 0;
}