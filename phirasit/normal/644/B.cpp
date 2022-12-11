#include <iostream>
#include <queue>

using namespace std;

const int N = 200010;

long long T[N], D[N], ans[N];
queue<int> que;
int n, b;

int main() {

  ios::sync_with_stdio(false);

  cin >> n >> b;
  long long _time = 0ll;
  for(int i = 0;i < n;i++) {
    ans[i] = -1;
    cin >> T[i] >> D[i];
    while(!que.empty() and max(_time, T[que.front()]) + D[que.front()] <= T[i]) {
      _time = max(_time, T[que.front()]);
      ans[que.front()] = (_time += D[que.front()]);
      que.pop();
    }
    if(que.empty() and _time <= T[i]) {
      _time = T[i];
      ans[i] = (_time += D[i]);
    }else {
      while(!que.empty() and max(_time, T[que.front()]) <= T[i]) {
        _time = max(_time, T[que.front()]);
        ans[que.front()] = (_time += D[que.front()]);
        que.pop();        
      }
      if(que.size() < b) {
        que.push(i);
      }
    }
  }
  while(!que.empty()) {
    _time = max(_time, T[que.front()]);
      ans[que.front()] = (_time += D[que.front()]);
      que.pop();    
  }

  for(int i = 0;i < n;i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}