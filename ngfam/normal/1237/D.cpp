#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n;
int a[N];
int suffix[N];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i + n] = a[i];
    a[i + n + n] = a[i];
  }

  memset(suffix, 60, sizeof suffix);

  vector < int > st;
  for(int i = 0; i < n + n + n; ++i) {
    while(!st.empty() && a[i] >= a[st.back()]) st.pop_back();
    if(!st.empty()) {
      int low = 0, high = st.size() - 1, ans = -1;
      while(low <= high) {
        int mid = (low + high) >> 1;
        if(a[st[mid]] > a[i] * 2) {
          ans = mid;
          low = mid + 1;
        }
        else {
          high = mid - 1;
        }
      }
      if(ans != -1) suffix[st[ans]] = min(suffix[st[ans]], i);
    }
    st.push_back(i);
  }

  for(int i = n + n + n - 1; i >= 0; --i) suffix[i] = min(suffix[i + 1], suffix[i]);

  for(int i = 0; i < n; ++i) {
    if(suffix[i] > n + n + n) cout << -1 << " ";
    else {
      cout << suffix[i] - i << " ";
    }
  }

  return 0;
}