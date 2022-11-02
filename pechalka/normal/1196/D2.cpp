#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
  int q;
  cin >> q;
  for (int query = 0; query < q; ++query){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string sample = "RGB";
    vector<int> dp1(n + 1);
    vector<int> dp2(n + 1);
    vector<int> dp3(n + 1);
    for (int i = k - 1; i >= 0; --i){
      //n - k + i
      dp1[n - k + i] = dp1[n - k + i + 1] + (sample[i % 3] != s[n - k + i]);
      dp2[n - k + i] = dp2[n - k + i + 1] + (sample[(i + 1) % 3] != s[n - k + i]);
      dp3[n - k + i] = dp3[n - k + i + 1] + (sample[(i + 2) % 3] != s[n - k + i]);
    }
    for (int i = n - k - 1; i >= 0; --i){
      dp1[i] = dp1[i + 1] + (sample[(2 * n + k + i) % 3] != s[i]) - (sample[(2 * n + 2 * k + i) % 3] != s[i + k]);
      dp2[i] = dp2[i + 1] + (sample[(2 * n + k + i + 1) % 3] != s[i]) - (sample[(2 * n + 2 * k + i + 1) % 3] != s[i + k]);
      dp3[i] = dp3[i + 1] + (sample[(2 * n + k + i + 2) % 3] != s[i]) - (sample[(2 * n + 2 * k + i + 2) % 3] != s[i + k]);
    }
    int ans = k;
    for (int i = 0; i <= n - k; ++i){
      ans = min(ans, dp1[i]);
      ans = min(ans, dp2[i]);
      ans = min(ans, dp3[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}