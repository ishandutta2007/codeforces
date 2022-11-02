#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
#include <fstream>
#include <stack>
#include <deque>
#include <utility>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 100 + 10;

int sum[N][N];
string s[N];

void add(int x, int y, int delta) {
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            sum[i][j] += delta;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s[i][j] == 'B') {
                if (sum[i][j] != +1) {
                    add(i, j, 1 - sum[i][j]);
                    ans++;
                }
            } else {
                if (sum[i][j] != -1) {
                    add(i, j, -1 - sum[i][j]);
                    ans++;
                }
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}