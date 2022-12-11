#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 110;

char str[N][N];
int cnt[N];

vector<int> ans;
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0;i < n;i++) {
    scanf("%s", str[i]);
  }
  for(int i = 0;i < n;i++) {
    scanf("%d", &cnt[i]);
  }
  for(int i = 0;i < n;i++) {
    for(int j = 0;j < n;j++) {
      if(cnt[j] == 0) {
        ans.push_back(j+1);
        for(int ii = 0;ii < n;ii++) {
          cnt[ii] -= (str[j][ii] == '1');
        }
      }
    }
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", (int)ans.size());
  for(int i = 0;i < ans.size();i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}