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
const int N = 100;

string s[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int ans = 0;
    vector<char> c;
    c.push_back('f');
    c.push_back('a');
    c.push_back('c');
    c.push_back('e');
    sort(c.begin(), c.end());
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j + 1 < m; j++) {
            vector<char> x;
            x.clear();
            x.push_back(s[i][j]);
            x.push_back(s[i + 1][j]);
            x.push_back(s[i][j + 1]);
            x.push_back(s[i + 1][j + 1]);
            sort(x.begin(), x.end());
            if (x == c) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}