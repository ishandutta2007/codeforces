#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, k;
int a[N];

int main() {
  scanf("%d %d", &n, &k);
  
  int sum = 0;
  for (int i=0; i<n; i++) {
    scanf("%d", a + i);
    sum += a[i];
  }
  
  if (sum % k > 0) return 0 * printf("No\n");
  
  int part = sum / k;
  
  vector<int> ans;
  for (int i=0; i<n;) {
    int dur = 0;
    int j = i;
    while (j < n && dur < part) {
      dur += a[j++];
    }
    
    if (dur != part) return 0 * printf("No\n");
    
    ans.push_back(j);
    i = j;
  }
  
  printf("Yes\n");
  printf("%d", ans[0]);
  for (int i=1; i<ans.size(); i++) printf(" %d", ans[i] - ans[i-1]);
  printf("\n");
  
  return 0;
}