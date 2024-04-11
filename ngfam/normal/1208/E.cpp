#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n, w;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  cin >> n >> w;

  vector < long long > sum(w + 5, 0);

  for(int i = 1; i <= n; ++i) {
    int sz; cin >> sz;
    vector < int > a(sz + 2), lef(sz + 2), rig(sz + 2);
    
    int cnt = 0;
    vector < int > ordered(sz + 2);


    stack < int > st;
    for(int i = 1; i <= sz; ++i) {
      cin >> a[i];
      while(!st.empty() && a[st.top()] <= a[i]) {
        rig[st.top()] = i;
        ordered[++cnt] = st.top();
        st.pop();
      }
      if(st.empty()) lef[i] = 0;
      else lef[i] = st.top();
      st.push(i);
    }

    while(!st.empty()) {
      rig[st.top()] = 0;
      ordered[++cnt] = st.top();
      st.pop();
    }

    vector < int > lo(sz + 2), hi(sz + 2);

    for(int i = sz; i >= 1; --i) {
      int p = ordered[i];

      lo[p] = p; hi[p] = w - sz + p;
      if(lef[p]) lo[p] = max(lo[p], hi[lef[p]] + 1);
      if(rig[p]) hi[p] = min(hi[p], lo[rig[p]] - 1);

      if(a[p] < 0) {
        lo[p] = max(lo[p], w - sz + 1);
        hi[p] = min(hi[p], sz);
      }

      if(lo[p] <= hi[p]){

        sum[lo[p]] += a[p];
        sum[hi[p] + 1] -= a[p];
      }
    }
  }

  for(int i = 1; i <= w; ++i) {
    sum[i] += sum[i - 1];
    cout << sum[i] << " ";
  }

  return 0;
}