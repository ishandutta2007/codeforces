#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1 << 18;
const int B = sqrt(N);

int n, m;
int a[N];
int pos[N];

int close[N];
int l[N], r[N];
vector<int> q_l[N], q_r[N];
int dp1[N], dp2[N], dp3[N];

int tree[N];

int get(int r) {
  int res = 0;
  
  for (; r > 0; r -= r & (-r)) {
    res += tree[r];
  }
  
  return res;
}

int get(int l, int r) {
  return get(r + 1) - get(l);
}

void add(int ind, int val) {
  ind++;
  
  for (; ind <= n; ind += ind & (-ind)) {
    tree[ind] += val;
  }
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    pos[a[i]] = i;
  }
  
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      int x = pos[i];
      int y = pos[j];
      if (x > y) {
        swap(x, y);
      }
      
      close[y]++;
    }
  }
  
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &l[i], &r[i]);
    l[i]--; r[i]--;
    q_l[l[i]].push_back(i);
    q_r[r[i]].push_back(i);
  }
  
  int closed = 0;
  
  for (int i = 0; i < n; i++) {
    for (int j : q_l[i]) {
      dp1[j] = get(l[j], r[j]);
      dp2[j] = closed;
    }
    
    int x = a[i];
    for (int j = x + x; j <= n; j += x) {
      int t = pos[j];
      if (t >= i) {
        add(t, 1);
      }
    }
    
    for (int d = 1; d * d <= x; d++) {
      int subd = x / d;
      if (d * subd != x) {
        continue;
      }
      
      if (d == subd) {
        int t = pos[d];
        if (t >= i) {
          add(t, 1);
        }
      } else {
        {
          int t = pos[d];
          if (t >= i) {
            add(t, 1);
          }
        }
        
        {
          int t = pos[subd];
          if (t >= i) {
            add(t, 1);
          }
        }
      }
    }
    
    closed += close[i];
    add(i, -close[i]);
    
    for (int j : q_r[i]) {
      dp3[j] = closed;
    }
  }
  
  for (int i = 0; i < m; i++) {
    printf("%d\n", dp3[i] - dp2[i] - dp1[i]);
  }
  
  return 0;
}