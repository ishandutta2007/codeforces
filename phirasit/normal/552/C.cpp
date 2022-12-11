#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;
int w, m;

int main() {
  ios::sync_with_stdio(false);
  cin >> w >> m;
  while(m > 0) {
    ans.push_back(m % w);
    m /= w;
  }
  for(int i = 0;i < ans.size();i++) {
    if(ans[i] % w == 0) {
      if(i == ans.size() - 1) {
        ans.push_back(ans[i] / w);
      }else {
        ans[i+1] += ans[i] / w;
      }
    }else if(ans[i] == 1) {
      continue;
    }else if(ans[i] == w-1) {
      if(i == ans.size() - 1) {
        ans.push_back(1);
      }else {
        ans[i+1]++;
      }
    }else {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}