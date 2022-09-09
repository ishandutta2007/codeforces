#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;

int n;
string s1, s2;
int have[26][26];
int have1[26], have2[26];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    memset(have, -1, sizeof have);
    memset(have1, -1, sizeof have1);
    memset(have2, -1, sizeof have2);

    cin >> n;
    cin >> s1;
    cin >> s2;

    int num = 0;
    pii ans1 = mapa(-1, -1);
    pii ans2 = mapa(-1, -1);
    for (int i = 0; i < n; ++i) {
        if (s1[i] != s2[i]) {
            ++num;
            if (have[s2[i] - 'a'][s1[i] - 'a'] != -1) {
                ans1 = mapa(have[s2[i] - 'a'][s1[i] - 'a'], i);
            }
            if (have1[s2[i] - 'a'] != -1) {
                ans2 = mapa(have1[s2[i] - 'a'], i);
            }
            if (have2[s1[i] - 'a'] != -1) {
                ans2 = mapa(have2[s1[i] - 'a'], i);
            }
            have[s1[i] - 'a'][s2[i] - 'a'] = i;
            have1[s1[i] - 'a'] = i;
            have2[s2[i] - 'a'] = i;
        }
    }

    if (ans1.ff != -1) {
        cout << num - 2 << "\n" << ans1.ff + 1 << " " << ans1.ss + 1 << endl;
        return 0;
    }

    if (ans2.ff != -1) {
        cout << num - 1 << "\n" << ans2.ff + 1 << " " << ans2.ss + 1 << endl;
        return 0;
    }
    
    cout << num << "\n-1 -1\n";

    return 0;
}