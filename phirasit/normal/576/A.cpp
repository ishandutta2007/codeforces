#include <iostream>
#include <vector>

using namespace std;

const int N = 1010;

vector<int> ans;

int mark[N];
int n;

int prime(int val) {
  for(int i = 2;i*i <= val;i++) {
    if(val % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  cin >> n;
  for(int i = 2;i <= n;i++) {
    int val = i;
    for(int j = 2;j <= val;j++) {
      while(val % j == 0) {
        val /= j;
        mark[j] = 1;
      }
    }
  }
  for(int i = 2;i <= n;i++) {
    if(not prime(i)) continue;
    for(int j = i * i;j <= n;j *= i) {
      mark[j] = 1;
    }
  }
  for(int j = 2;j <= n;j++) {
    if(mark[j]) {
      ans.push_back(j);
    }
  }
  cout << ans.size() << endl;
  for(int val : ans) {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}