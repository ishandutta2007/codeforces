#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int mod = 1e9 + 7;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    string s; cin >> s;
    set <char> good;
    for (auto x : s) good.insert(x);
    cin >> s;
    string s1, s2;
    int i = 0;
    for (; i < s.size() and s[i] != '*'; ++i)
        s1 += s[i];
    ++i;
    for (; i < s.size(); ++i)
        s2 += s[i];
    int q; cin >> q;
    while (q --> 0) {
        bool c = true;
        string t; cin >> t;
        if (s1.size() + s2.size() > t.size()) c = false;
        for (int k = 0; k < min((int)t.size(), (int)s1.size()); ++k) {
            if (s1[k] == '?' and good.find(t[k]) == good.end()) c = false;
            if (s1[k] != '?' and s1[k] != t[k]) c = false;
        }
        for (int k = (int)t.size() - 1, j = (int)s2.size() - 1; j >= 0 and k >= 0; --j, --k) {
            if (s2[j] == '?' and good.find(t[k]) == good.end()) c = false;
            else if (s2[j] != '?' and s2[j] != t[k]) c = false;
        }
        for (int k = (int)s1.size(); k < (int)t.size() - (int)s2.size(); ++k) {
            if (good.find(t[k]) != good.end()) c = false;
        }
        if (s.find('*') == -1 and s1.size() != t.size()) c = false;
        if (c) cout << "YES\n";
        else cout << "NO\n";
    }
}