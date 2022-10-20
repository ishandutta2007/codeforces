#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
const int maxc = 1e7 + 5;
int a[maxn];
vector<int> bit[2][25];
void add(int b, int bit_id, int x)
{
  x++;
  while(x < bit[b][bit_id].size())
  {
    bit[b][bit_id][x]++;
    x += (x&(-x));
  }
}
int query(int b, int bit_id, int x)
{
  x++;
  int ans = 0;
  while(x)
  {
    ans += bit[b][bit_id][x];
    x -= (x&(-x));
  }
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  for(int l = 0; l < 2; l++)
  for(int i = 0; i < 25; i++)
    bit[l][i].resize((1<<i)+2);
  int n;
  cin >> n;
  long long ans = 0;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++)
  {
    int x = a[i];
    for(int j = 0; j < 25; j++)
    {
      int cut = (1<<j) - a[i] % (1<<j);
      long long tmp = 0;
      tmp += query(x&1, j, (1<<j)) - query(x&1, j, cut-1);
      //if(j == 0 && i == 3) cout << tmp << " " << query(1,0,1) << " " << query(1,0,0) << endl;
      tmp += query((x&1)^1, j, cut-1);
      if(tmp&1) ans ^= (1<<j);
      //if(j == 0 && i == 3) cout << "..." << tmp << " " << query(0,0,0) << endl;
      add(x&1, j, a[i]%(1<<j));
      x /= 2;
    }
  }
  cout << ans << endl;
  return 0;
}