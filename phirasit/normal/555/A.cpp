#include <stdio.h>
#include <set>
#include <vector>
#include <map>

using namespace std;

const int N = 100010;

set<int> S;
map<int, int> mp;

vector<int> ls[N];
int n, k;

int main() {
  scanf("%d%d", &n, &k);
  int cnt = 0;
  for(int i = 0;i < k;i++) {
    int sz;
    scanf("%d", &sz);
    for(int j = 0;j < sz;j++) {
      int val;
      scanf("%d", &val);
      ls[i].push_back(val);
      S.insert(val);
    }
  }
  int c = 0;
  for(int x : S) {
    mp[x] = c++;
  }
  for(int i = 0;i < k;i++) {
    cnt++;
    int p = ls[i].size();
    for(int j = 1;j < ls[i].size();j++) {
      if(mp[ls[i][j]] != mp[ls[i][j-1]]+1) {
        p = j;
        break;
      }
    }
    if(ls[i][0] == 1) {
      cnt += 2 * (ls[i].size() - p);
    }else {
      cnt += 2 * (ls[i].size() - 1);
    }
  }
  printf("%d\n", cnt-1);
  return 0;
}