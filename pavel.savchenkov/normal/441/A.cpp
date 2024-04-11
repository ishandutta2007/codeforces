#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n, v;
  scanf("%d%d", &n, &v);

  vector <int> res;
  for (int i = 0; i < n; ++i) {
    int k;
scanf("%d", &k);

    bool was = false;
    for (int j = 0; j < k; ++j) {
      int s;
      scanf("%d", &s);
      if  (s < v) was = true; 
    }
    if  (was) {
     res.push_back(i + 1);
     }
  }

  printf("%d\n", res.size());
  for (int i = 0; i < res.size(); ++i)
    printf("%d ", res[i]);
}