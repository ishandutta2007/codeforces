#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;
const int maxn = 200005;
int a[maxn], tm[maxn];
vector<pii> base;
int main()
{
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> a[i];
  int Q;
  cin >> Q;
  for(int i = 0; i < Q; i++)
  {
    int cmd;
    cin >> cmd;
    if(cmd == 1)
    {
      int p,x;
      cin >> p >> x;
      a[p] = x;
      tm[p] = i;
    }
    else
    {
      int money;
      cin >> money;
      while(base.size() && base[(int)base.size()-1].second <= money) base.pop_back();
      base.push_back({i, money});
    }
  }
  for(int i = 1; i <= n; i++)
  {
    int t = lower_bound(base.begin(),base.end(),make_pair(tm[i],0))-base.begin();
    if(t != base.size())
    {
      a[i] = max(a[i], base[t].second);
    }
  }
  for(int i = 1; i <= n; i++)
  {
    cout << a[i];
    if(i != n) cout << " ";
    else cout << "\n";
  }
  return 0;
}