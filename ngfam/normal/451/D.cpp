#include <bits/stdc++.h>
#define left yasou
#define right hasagi

using namespace std;

const int N = 100010;

int n;
int z[2];
char s[N];
int left[N];
int right[N];
int cnt[2][2];
long long calc[N];
pair < int, int > a[N];
vector < int > solve[2];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  a[0].first = -1;
  scanf("%s", s + 1);
  int m = strlen(s + 1);
  for(int i = 1; i <= m; ++i){
    if(s[i] - 'a' != a[n].first){
      a[++n] = make_pair(s[i] - 'a', 1);
      left[n] = i;
      right[n] = i;
    }
    else{
      ++a[n].second;
      right[n] = i;
    }
  }
  z[0] = 1;
  int nw = 0;
  for(int i = 1; i <= m; ++i){
    nw = 1 - nw;
    calc[i] = calc[i - 1];
    calc[i] += z[nw];
    ++z[nw];
  }
  for(int i = 1; i <= n; ++i){
    solve[a[i].first].push_back(i);
  }
  long long tot = 0, even = 0;
  int sum = 0;
  for(int i = solve[0].size() - 1; i >= 0; --i){
    int x = solve[0][i];
    tot += 1LL * a[x].second * sum;
    tot += 1LL * (1LL * a[x].second * (a[x].second - 1)) / 2 + a[x].second;
    sum += a[x].second;
  }
  sum = 0;
  for(int i = solve[1].size() - 1; i >= 0; --i){
    int x = solve[1][i];
    tot += 1LL * a[x].second * sum;
    tot += 1LL * (1LL * a[x].second * (a[x].second - 1)) / 2 + a[x].second;
    sum += a[x].second;
  }
  for(int i = solve[0].size() - 1; i >= 0; --i){
    int x = solve[0][i];
    left[x] %= 2;
    right[x] %= 2;
    even += 1LL * cnt[1 - left[x]][0] * ((a[x].second + 1) / 2);
    even += 1LL * cnt[left[x]][1] * ((a[x].second + 1) / 2);
    even += 1LL * cnt[1 - left[x]][1] * (a[x].second / 2);
    even += 1LL * cnt[left[x]][0] * (a[x].second / 2);
    even += calc[a[x].second];
    cnt[right[x]][0] += (a[x].second + 1) / 2;
    cnt[right[x]][1] += a[x].second / 2;
  }
  memset(cnt, 0, sizeof cnt);
  for(int i = solve[1].size() - 1; i >= 0; --i){
    int x = solve[1][i];
    left[x] %= 2;
    right[x] %= 2;
    even += 1LL * cnt[1 - left[x]][0] * ((a[x].second + 1) / 2);
    even += 1LL * cnt[left[x]][1] * ((a[x].second + 1) / 2);
    even += 1LL * cnt[1 - left[x]][1] * (a[x].second / 2);
    even += 1LL * cnt[left[x]][0] * (a[x].second / 2);
    even += calc[a[x].second];
    cnt[right[x]][0] += (a[x].second + 1) / 2;
    cnt[right[x]][1] += a[x].second / 2;
  }
  cout << even << " " << tot - even;
  return 0;
}