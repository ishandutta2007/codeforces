#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
const int maxn = 1000000;
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
    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    sort(a,a+n);
    set<int> s;
    for(int i = 0; i < n; i++)
      for(int j = i+1; j < n; j++)
        s.insert(a[j]-a[i]);
    cout << s.size() << endl;
  }
}