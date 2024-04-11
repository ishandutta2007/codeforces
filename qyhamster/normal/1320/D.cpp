#include <iostream>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn],num[maxn],nxt[maxn];
long long hs[maxn],pwr[maxn];
const int MOD = 1e9 + 7;
const int P = 890501;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  pwr[0] = 1;
  for(int i = 1; i < maxn; i++) pwr[i] = pwr[i-1] * P % MOD;
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = "#" + s;
  int cur = 0, cnt = 0;
  for(int i = 1; i <= n; i++)
  {
    cur++;
    a[i] = cur;
    if(s[i] == '0')
    {
      cur = 0;
      hs[i] = (hs[i-1] * P + a[i] % 2) % MOD;
      num[i] = ++cnt;
    }
    else
    {
      hs[i] = hs[i-1];
      num[i] = num[i-1];
    }
  }
  //for(int i = 1; i <= n; i++) cout << hs[i] << ' ';cout << '\n';
  int hold = n+1;
  for(int i = n; i >= 1; i--)
  {
    if(s[i] == '0') hold = i;
    nxt[i] = hold;
  }
  int Q;
  cin >> Q;
  while(Q--)
  {
    int u,v,len;
    cin >> u >> v >> len;
    if(num[v+len-1] == num[v-1] || num[u+len-1] == num[u-1])
    {
      if(num[v+len-1] == num[v-1] && num[u+len-1] == num[u-1])cout << "Yes" << '\n';
      else cout << "No" << '\n';
      continue;
    }
    bool check = 1;
    bool temp = 0;
    long long first = ((hs[u+len-1] - hs[u-1] * pwr[num[u+len-1] - num[u-1]]) % MOD + MOD) % MOD;
    long long second = ((hs[v+len-1] - hs[v-1] * pwr[num[v+len-1] - num[v-1]]) % MOD + MOD) % MOD;
    if(first == second || abs(first - second + MOD) % MOD == pwr[num[u+len-1] - num[u-1] - 1] || abs(second - first + MOD) % MOD == pwr[num[u+len-1] - num[u-1] - 1]) temp = 1;
    if(!temp) check = 0;
    if((nxt[u] - u) % 2 != (nxt[v] - v) % 2) check = 0;
    if(num[v+len-1] - num[v-1] != num[u+len-1] - num[u-1]) check = 0;
    if(check) cout << "Yes" << '\n';
    else cout << "No" << '\n';
  }
  return 0;
}