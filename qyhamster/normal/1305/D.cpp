#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
vector<int> e[maxn];
int d[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 1; i < n; i++)
  {
    int u,v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
    d[u]++;
    d[v]++;
  }
  for(int i = 0; i < n/2; i++)
  {
    vector<int> leaf;
    for(int i = 1; i <= n; i++)
    {
      if(d[i] == 1)
      {
        leaf.push_back(i);
      }
      if(leaf.size() == 2) break;
    }
    cout << "? " << leaf[0] << " " << leaf[1] << endl;
    fflush(stdout);
    int x;
    cin >> x;
    if(x == leaf[0])
    {
      cout << "! " << leaf[0] << endl;
      fflush(stdout);
      exit(0);
    }
    if(x == leaf[1])
    {
      cout << "! " << leaf[1] << endl;
      fflush(stdout);
      exit(0);
    }
    d[leaf[0]] = d[leaf[1]] = -maxn;
    for(auto k:e[leaf[0]]) d[k]--;
    for(auto k:e[leaf[1]]) d[k]--;
  }
  for(int i = 1; i <= n; i++)
  {
    if(d[i] >= 0)
    {
      cout << "! " << i << endl;
      fflush(stdout);
      exit(0);
    }
  }
  return 0;
}