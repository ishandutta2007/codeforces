#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.length() != s2.length()) {
        cout << "No";
        return 0;
    }
    set<char> s{'a', 'e', 'i', 'o', 'u'};
    REP(i, s1.length()) {
        if (s.count(s1[i]) ^ s.count(s2[i])) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}