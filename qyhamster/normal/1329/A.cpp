#include <bits/stdc++.h>
#define pii pair<long long,long long>
using namespace std;
const int maxn = 1e5+5;
long long a[maxn],res[maxn],to_add[maxn];
pii p[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  long long sum = 0;
  for(int i = 0; i < m; i++)
  {
    cin >> a[i];
    sum += a[i];
  }
  for(int i = 0; i < m; i++)
  {
    if(a[i] + i > n || sum < n)
    {
      cout << "-1" << endl;
      exit(0);
    }
  }
  for(int i = 0; i < m; i++)
  {
    p[i].first = a[i];
    p[i].second = i;
  }
  multiset<long long> s;
  for(int i = 0; i < m; i++)
  {
    s.insert(p[i].first+i);
  }
  int last = 0;
  for(int i = 0; i < m-1; i++)
  {
    s.erase(s.lower_bound(p[i].first+i));
    int delta = min(n - *(prev(s.end())) - last , p[i].first-1);
    to_add[i] = delta;
    last += delta;
    if(last + *(prev(s.end())) >= n) break;
  }
  for(int i = 1; i < m; i++)
  {
    to_add[i] += to_add[i-1];
  }
  res[p[0].second+1] = 1;
  for(int i = 1; i < m; i++) res[p[i].second+1] = to_add[i-1]+i+1;
  for(int i = 1; i <= m; i++) cout << res[i] << " "; cout << endl;
  return 0;
}