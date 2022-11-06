#include <bits/stdc++.h>

using namespace std;

set < pair <int, int> > s;

int main() {
    int n, i, x;
    cin >> n;
    for(i = 1; i <= 2 * n; i++) {
        cin >> x;
        s.insert({x, i});
    }
    int ans = (1 << 30);
    for(auto it1 : s)
        for(auto it2 : s)
           if(it1.second != it2.second) {
                int cnt = 0;
                int sum = 0;
                for(auto it : s)
                  if(it.second != it1.second && it.second != it2.second) {
                     if(cnt % 2 == 0)
                        sum -= it.first;
                     else
                        sum += it.first;
                     cnt++;
                  }
                ans = min(ans, sum);
           }
    cout << ans;
    return 0;
}