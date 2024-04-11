#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define cmpby(_x) [](const auto& a, const auto& b) {return (a _x) < (b _x);}
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);


int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    string s;
    cin >> s;

    vector<int> used(26);

    char cur = 'a';
    for (int i = 0; i < szof(s); ++i) {
        if (s[i] != '@') {
            if (s[i] != cur) {
                cout << "NO\n";
                return 0;
            }
            for (int j = i; j < szof(s); ++j) {
                if (s[j] == cur) {
                    s[j] = '@';
                }
            }
            ++cur;
        }
    }

    cout << "YES\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}