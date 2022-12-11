#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 4010;

vector<int> data, nw;

long long v[N], d[N], p[N];
int n;

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i = 0;i < n;i++) {
    cin >> v[i] >> d[i] >> p[i];
    data.push_back(i);
  }
  for(int i = 0;i < data.size();i++) {
    int idx = data[i];
    long long cnt = 0;
    for(int j = i + 1;j < data.size() and cnt < v[idx];j++) {
      p[data[j]] -= v[idx] - (cnt++);
    }
    long long sum = 0;
    for(int j = i + 1;j < data.size();j++) {
      p[data[j]] -= sum;
      if(p[data[j]] < 0ll) {
        sum += d[data[j]];
      }
    }
    nw.clear();
    for(int j = 0;j < data.size();j++) {
      if(p[data[j]] >= 0) {
        nw.push_back(data[j]);
      }
    }
    data = nw;
  }
  cout << data.size() << "\n";
  for(int x : data) {
    cout << x+1 << " ";
  }
  cout << "\n";
  return 0;
}