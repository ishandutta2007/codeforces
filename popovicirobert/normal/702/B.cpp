#include <bits/stdc++.h>
#define MAXN 100000

using namespace std;


unordered_map <int, int> mp;
int v[MAXN + 1];

int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    long long ans = 0;
    for(long long p2 = 1; p2 <= (1 << 30); p2 *= 2) {
        for(i = 1; i <= n; i++) {
            ans += mp[p2 - v[i]];
            if(2 * v[i] == p2)
                ans--;
        }
    }
    cout << ans / 2;
  //  cin.close();
  //  cout.close();
    return 0;
}