#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
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
map <string, int> mp;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        string s1, s2;
        cin >> s1 >> s2 >> s2;
        for (int j = 0; j < szof(s1); ++j) {
            s1[j] = tolower(s1[j]);
        }
        for (int j = 0; j < szof(s2); ++j) {
            s2[j] = tolower(s2[j]);
        }
        mp[s1] = mp[s2] + 1;
        ans = max(ans, mp[s1]);
    }

    cout << ans + 1 << endl;

    return 0;
}