#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
typedef long long ll;
typedef long double ld;
  
using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string s, t = "SLM";
    vector<vector<int>> a(4, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> s;
        int x = s.size() - 1, y = t.find(s.back());
        a[x][y]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> s;
        int x = s.size() - 1, y = t.find(s.back());
        a[x][y]--;
    }
    int ans = 0;
    for (int i = 1; i < 4; i++)
        ans += abs(a[i][0]);
    sort(a[0].begin(), a[0].end());
    if (a[0][1] < 0)
        ans += a[0][2];
    else
        ans -= a[0][0];
    cout << ans;
}