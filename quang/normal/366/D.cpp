#include <bits/stdc++.h>

using namespace std;

const int N = 3010;

int n, m;
vector <pair<int, pair<int, int> > > a[N];
vector <int> b;
bool used[N];
int st[N], top;

bool check(int l, int r) {
    top = 1;
    st[0] = 1;
    for (int i = 2; i <= n; i++) {
        used[i] = 0;
    }
    used[1] = 1;
    for (int i = 0; i <top; i++) {
        int u = st[i];
        for (int j = 0; j < a[u].size(); j++)  {
            int v = a[u][j].first;
            int L = a[u][j].second.first;
            int R = a[u][j].second.second;
          if (used[v]) {
            continue;
          }
            if (L <= l && r <= R) {
                used[v] = 1;            
                st[top++] = v;
            }
      }
    }
    return used[n];
}

int main() {                         
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, l, r;
        scanf("%d %d %d %d", &u, &v, &l, &r);
        a[u].push_back(make_pair(v, make_pair(l, r)));      
        a[v].push_back(make_pair(u, make_pair(l, r)));      
        b.push_back(l);
        b.push_back(r);
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    int res = 0;     
    for (int i = 0; i < b.size(); i++) {
        int left = b[i];
        int l, r;
        if (!check(left, left)) {
            continue;
        }
        l = i;
        r = b.size();
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (check(left, b[m])) {
                l = m;              
            } else {
                r = m;
            }
        }
        res = max(res, b[l] - left + 1);
    } 
    if (!res) {
        cout << "Nice work, Dima!";
  } else {
    cout << res << endl;
    }          
  return 0;                 
}