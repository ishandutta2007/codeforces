    #include <bits/stdc++.h>
     
    using namespace std;
     
    const int N = 100010;
     
    int n, w;
    int bit[N];
    int cnt[N];
    pair < int, int > a[N];
     
    int main(){
      ios_base::sync_with_stdio(false); cin.tie(NULL);
     
      map < pair < int, int >, int > numx;
     
      cin >> n >> w;
      for(int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
      }
     
      sort(a + 1, a + n + 1, [&](pair < int, int > x, pair < int, int > y){
        long long vx = abs(x.second - w), vy = abs(y.second - w);
        return abs(x.first) * vy < abs(y.first) * vx;
      });
     
      for(int i = 1; i <= n; ++i) {
        numx[a[i]] = i;
        if(i > 1) {
          auto x = a[i - 1], y = a[i];
          long long vx = abs(x.second - w), vy = abs(y.second - w);
          if(abs(x.first) * vy == abs(y.first) * vx) {
            numx[a[i]] = numx[a[i - 1]];
          }
        }
      }
     
      sort(a + 1, a + n + 1, [&](pair < int, int > x, pair < int, int > y){
        long long vx = abs(x.second + w), vy = abs(y.second + w);
        return abs(x.first) * vy < abs(y.first) * vx;
      });
     
      long long ans = 0;
      for(int i = n; i >= 1; --i) {
      //  cout << a[i].first << " " << a[i].second << endl;
        int j = i;
        vector < int > vec;
        while(j > 0) {
          auto x = a[i], y = a[j];
          long long vx = abs(x.second + w), vy = abs(y.second + w);
          if(abs(x.first) * vy == abs(y.first) * vx) {
            vec.push_back(j);
          }
          else break;
          --j;
        }
        for(int j : vec) {
          int id = numx[a[j]];
          for(int x = id; x > 0; x -= x & -x) ans += bit[x];
        }
        for(int j : vec){
          int id = numx[a[j]];
          for(int x = id; x < N; x += x & -x) bit[x]++;
        }
        i = j + 1;
        ans += 1LL * vec.size() * ((int)vec.size() - 1) / 2;
    //    cout << vec.size() << endl;
      }
     
      cout << ans;
     
     
      return 0;
    }