//HACK ME, PLEASE! ^_^
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>

#define pb push_back
#define i64 long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
#define sqr(x) (x) * (x)

const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);

using namespace std;
int n, k;

vi id[20];

string a;

string ans[20];
int cnt[20];

void build(int x)
{
    ans[x] = a;
    int l = x; int r = x; int K = (int)id[x].size();
    memset(cnt, 0, sizeof cnt);

    while (K < k && (l > -1 || r < 10))
    {
        if  (l != -1) l--;
        if  (r != 10) r++;
        if  (K + (int)id[r].size() > k)
        {
            cnt[r] = k - K;
            K = k;
        } else cnt[r] = (int)id[r].size(), K += (int)id[r].size();
        if  (l == -1) continue;
        if  (K + (int)id[l].size() > k)
        {
            cnt[l] = k - K;
            K = k;
        } else cnt[l] = (int)id[l].size(), K += (int)id[l].size();
    }

    for (int i = x + 1; i < 10; i++)
     for (int j = 0; j < cnt[i]; j++)
      ans[x][id[i][j]] = x + '0';

    for (int i = x - 1; i >= 0; i--)
     for (int j = (int)id[i].size() - 1; j >= (int)id[i].size() - cnt[i]; j--)
      ans[x][id[i][j]] = x + '0';

}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> k; scanf("\n");
  getline(cin, a);
  n = (int)a.length();
  forn(i, n)
   id[a[i] - '0'].pb(i);

  forn(i, 10)
   build(i);

  sort(ans, ans + 10);
  int mi = 0; int cntmi = 0;
  forn(i, n) cntmi += abs(ans[0][i] - a[i]);

  foran(i, 1, 10)
  {
      int cnt = 0;
      forn(j, n)
       cnt += abs(ans[i][j] - a[j]);
      if (cnt >= cntmi) continue;
      mi = i; cntmi = cnt;
  }


  printf("%d\n%s\n", cntmi, ans[mi].c_str());
  return 0;
}
/*
6 5
898196
*/